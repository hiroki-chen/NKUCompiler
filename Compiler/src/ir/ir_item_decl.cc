/*
 Copyright (c) 2021 Haobin Chen

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include <common/compile_excepts.hh>
#include <common/termcolor.hh>
#include <common/utils.hh>
#include <frontend/nodes/item_decl.hh>

extern compiler::NodeStack stack;

void compiler::Item_decl_var::generate_ir_helper(
    compiler::ir::IRContext* const ir_context,
    std::vector<compiler::ir::IR>& ir_list, const basic_type& b_type) const {
  const std::string name = identifier->get_name();
  compiler::ir::Operand* const default_value = new compiler::ir::Operand(
      compiler::to_ir_type(b_type), "", "0", false, false);

  // Check current scope.
  if (ir_context->is_global_context() == true) {
    const std::string name_symbol = ir::global_sign + name;
    ir_list.emplace_back(compiler::ir::op_type::GLOBAL_BEGIN, name_symbol);
    ir_list.emplace_back(compiler::ir::op_type::GLOBAL, default_value);
    ir_list.emplace_back(compiler::ir::op_type::GLOBAL_END, name_symbol);

    // Create a new symbol for the symbol table.
    compiler::Symbol* const symbol = new compiler::Symbol(
        name_symbol, compiler::symbol_type::VAR_TYPE, false);
    ir_context->get_symbol_table()->add_symbol(name, symbol);
  } else {
    const uint32_t id = ir_context->get_symbol_table()->get_available_id();
    const std::string name_symbol = ir::local_sign + std::to_string(id) + name;
    // Create a temporary symbol for the symbol table.
    compiler::Symbol* const symbol = new compiler::Symbol(
        name_symbol, compiler::symbol_type::VAR_TYPE, false);
    ir_context->get_symbol_table()->add_symbol(name, symbol);
  }
}

void compiler::Item_decl_var_init::generate_ir_helper(
    ir::IRContext* const ir_context, std::vector<ir::IR>& ir_list,
    const basic_type& b_type) const {
  const std::string name = identifier->get_name();
  std::string name_symbol;
  ir::Operand* const result = expression->eval_runtime(ir_context);
  // Check current scope.
  if (ir_context->is_global_context()) {
    name_symbol = ir::global_sign + name;
    ir_list.emplace_back(compiler::ir::op_type::GLOBAL_BEGIN, name_symbol);
    ir_list.emplace_back(compiler::ir::op_type::GLOBAL, result);
    ir_list.emplace_back(compiler::ir::op_type::GLOBAL_END, name_symbol);
  } else {
    const uint32_t scope_id =
        ir_context->get_symbol_table()->get_top_scope_uuid();
    name_symbol = ir::local_sign + std::to_string(scope_id) + name;
  }
  // Insert into symbol table.
  compiler::Item_literal* const literal_value = ir::wrap_value(result);
  compiler::Symbol* symbol = nullptr;
  if (is_const == true) {
    symbol = new compiler::Symbol_const(
        name_symbol, compiler::symbol_type::VAR_TYPE, literal_value);
    ir_context->get_symbol_table()->add_const(
        identifier->get_name(), dynamic_cast<compiler::Symbol_const*>(symbol));
  } else {
    symbol = new compiler::Symbol(name_symbol, compiler::symbol_type::VAR_TYPE,
                                  literal_value);
    ir_context->get_symbol_table()->add_symbol(identifier->get_name(), symbol);
  }
}

void compiler::Item_decl::generate_ir(compiler::ir::IRContext* const ir_context,
                                      std::vector<compiler::ir::IR>& ir_list,
                                      const basic_type& b_type) const {
  stack.emplace_back(static_cast<Item*>(const_cast<Item_decl*>(this)));
  try {
    generate_ir_helper(ir_context, ir_list, b_type);
    stack.pop_back();
  } catch (const std::exception& e) {
    std::cerr << termcolor::red << termcolor::bold << e.what()
              << termcolor::reset << std::endl;
    stack.pop_back();
    exit(1);
  }
}

void compiler::Item_stmt_decl::generate_ir_helper(
    compiler::ir::IRContext* const ir_context,
    std::vector<compiler::ir::IR>& ir_list) const {
  for (compiler::Item_decl* const declaration : declarations) {
    declaration->generate_ir(ir_context, ir_list, type);
  }
}

uint32_t compiler::Item_decl_array::calculate_array_size(
    compiler::ir::IRContext* const ir_context,
    std::vector<compiler::ir::IR>& ir_list, const compiler::basic_type& b_type,
    std::vector<ir::Operand*>& array_shape) const {
  // Determine the shape of the array.
  for (compiler::Item_expr* const shape : identifier->get_array_shape()) {
    ir::Operand* const value = shape->eval_runtime(ir_context, ir_list);
    if (value->get_type() == ir::var_type::DB) {
      throw compiler::fatal_error("Array shape cannot be a double type!");
    }
    array_shape.emplace_back(value);
  }

  uint32_t array_size = 1;
  for (ir::Operand* const shape : array_shape) {
    int size = 0;
    if ((size = std::stoi(shape->get_value())) < 0) {
      throw compiler::fatal_error("The array has negative shape!");
    }
    array_size *= (uint32_t)size;
  }

  return array_size;
}

void compiler::Item_decl_array::generate_ir_helper(
    compiler::ir::IRContext* const ir_context,
    std::vector<compiler::ir::IR>& ir_list,
    const compiler::basic_type& b_type) const {
  try {
    // Determine the size of the array.
    std::vector<ir::Operand*> array_shape;
    const uint32_t array_size =
        calculate_array_size(ir_context, ir_list, b_type, array_shape);

    ir::Operand* const operand_alloc =
        new ir::Operand(ir::var_type::NONE,
                        ir::var_type_to_string(compiler::to_ir_type(b_type)) +
                            " * " + std::to_string(array_size),
                        "");

    // Handle global array type.
    const std::string name = identifier->get_name();
    if (ir_context->is_global_context()) {
      const std::string name_symbol = ir::global_sign + name + "[]";
      ir_context->get_symbol_table()->add_symbol(
          name,
          new compiler::Symbol(name_symbol, compiler::symbol_type::ARRAY_TYPE,
                               false, array_shape));
      ir_list.emplace_back(ir::op_type::GLOBAL_BEGIN, name_symbol);
      ir_list.emplace_back(ir::op_type::GLOBAL, operand_alloc);
      ir_list.emplace_back(
          ir::op_type::SPACE,
          new ir::Operand(std::to_string(
              ir::to_byte_length(compiler::to_ir_type(b_type)) * array_size)));
      ir_list.emplace_back(ir::op_type::GLOBAL_END, name_symbol);
      // Handle local array type.
    } else {
      const std::string name_symbol =
          ir::local_sign +
          std::to_string(ir_context->get_symbol_table()->get_available_id()) +
          name + "[]";
      ir_context->get_symbol_table()->add_symbol(
          name,
          new compiler::Symbol(name_symbol, compiler::symbol_type::ARRAY_TYPE,
                               true, array_shape));
    }
  } catch (const std::exception& e) {
    std::cerr << termcolor::red << termcolor::bold << e.what()
              << termcolor::reset << std::endl;
    exit(1);
  }
}

void compiler::Item_decl_array_init::generate_ir_helper(
    compiler::ir::IRContext* const ir_context,
    std::vector<compiler::ir::IR>& ir_list, const basic_type& b_type) const {
  try {
    std::vector<ir::Operand*> array_shape;
    const uint32_t array_size =
        calculate_array_size(ir_context, ir_list, b_type, array_shape);
    ir::Operand* const operand_alloc =
        new ir::Operand(ir::var_type::NONE,
                        ir::var_type_to_string(compiler::to_ir_type(b_type)) +
                            " * " + std::to_string(array_size),
                        "");

    // Handle initial value type.
    const std::string name = identifier->get_name();
    std::vector<ir::Operand*> initial_values;
    if (ir_context->is_global_context()) {
      const std::string name_symbol = ir::global_sign + name;
      ir_context->get_symbol_table()->add_symbol(
          name,
          new compiler::Symbol(name_symbol, compiler::symbol_type::ARRAY_TYPE,
                               true, array_shape));
      ir_list.emplace_back(ir::op_type::GLOBAL_BEGIN, name_symbol);
      // Handle init values.
      init_helper(init_value->get_value_list(), initial_values, 0, ir_context,
                  ir_list, compiler::to_ir_type(b_type));
      ir_list.emplace_back(ir::op_type::GLOBAL_END, name_symbol);
    } else {
      const std::string name_symbol =
          ir::local_sign +
          std::to_string(ir_context->get_symbol_table()->get_available_id());
      ir_context->get_symbol_table()->add_symbol(
          name,
          new compiler::Symbol(name_symbol, compiler::symbol_type::ARRAY_TYPE,
                               true, array_shape));
      ir_list.emplace_back(ir::op_type::MALLOC, new ir::Operand(name_symbol),
                           operand_alloc);

      init_helper(init_value->get_value_list(), initial_values, 0, ir_context,
                  ir_list, compiler::to_ir_type(b_type));
    }
  } catch (const std::exception& e) {
    std::cerr << termcolor::red << termcolor::bold << e.what()
              << termcolor::reset << std::endl;
    exit(1);
  }
}

void compiler::Item_decl_array_init::init_helper(
    const std::vector<compiler::Item_literal_array_init*> value_list,
    std::vector<compiler::ir::Operand*>& init_value, const uint32_t& index,
    compiler::ir::IRContext* const ir_context,
    std::vector<compiler::ir::IR>& ir_list,
    const ir::var_type& var_type) const {
  auto lambda_handle_init = [&](ir::Operand* const array_size,
                                const bool& malloc = false) {
    // Get the length of the array item.
    const uint32_t byte_length = ir::to_byte_length(var_type);
    if (malloc == true) {
      // Iterate through the size of the array.
      const uint32_t size = std::stoul(array_size->get_value());
      for (uint32_t i = 0; i < size; i++) {
        init_value.emplace_back(
            new ir::Operand(var_type, "", "0", false, false));
      }
      if (ir_context->is_global_context()) {
        ir_list.emplace_back(
            ir::op_type::SPACE,
            new ir::Operand(std::to_string(byte_length * size)));
      }
    } else {
      init_value.emplace_back(new ir::Operand(var_type, "", "0", false, false));
      if (ir_context->is_global_context()) {
        ir_list.emplace_back(ir::op_type::SPACE, array_size);
      } else {
        const std::string array_name_local =
            ir_context->get_symbol_table()
                ->find_symbol(get_identifier()->get_name())
                ->get_name();
        const uint32_t ind = byte_length * (init_value.size() - 1);
        ir_list.emplace_back(
            ir::op_type::STORE, nullptr, new ir::Operand(array_name_local),
            new ir::Operand(ir::var_type::i32, "", std::to_string(ind), false,
                            false));
      }
    }
  };

  auto lambda_handle_init_const = [&](const bool& malloc = false) -> bool {
    // TODO: Implement me.
    return false;
  };

  // Main.
  const std::vector<compiler::Item_expr*> shape = identifier->get_array_shape();
  if (index < shape.size()) {
    uint32_t size = 1, cur_size = 0;
    for (std::vector<compiler::Item_expr*>::const_iterator iter =
             shape.cbegin() + index;
         iter != shape.end(); iter++) {
      size *= std::stoul((*iter)->eval_runtime(ir_context)->get_value());
      const uint32_t res =
          std::stoul(shape[index]->eval_runtime(ir_context)->get_value());
      const uint32_t cur = size / res;

      for (compiler::Item_literal_array_init* const value : value_list) {
        if (value->get_is_numeric()) {
          cur_size++;
          try {
            if (is_const) {
              lambda_handle_init_const(value->get_value()->eval_runtime(ir_context));
            } else {
              lambda_handle_init(value->get_value()->eval_runtime(ir_context));
            }
          } catch (...) {
          }
        } else {
          if (cur_size % cur != 0) {
            if (is_const) {
            } else {
            }
          }
        }

        init_helper(value->get_value_list(), init_value, index + 1, ir_context,
                    ir_list, var_type);
        cur_size += cur;
      }
    }
  }
}