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
extern uint32_t opt_level;

static void do_init_array(compiler::ir::Operand* const value,
                          compiler::ir::IRContext* const ir_context,
                          std::vector<compiler::ir::IR>& ir_list,
                          std::vector<compiler::ir::Operand*>& init_value,
                          const std::string& array_name, bool is_space = false,
                          bool is_const = false) {
  using namespace compiler;

  if (is_space) {
    for (uint32_t i = 0; i < std::stoul(value->get_value()); i++) {
      init_value.emplace_back(OPERAND_VALUE("0"));
    }

    if (ir_context->is_global_context()) {
      const uint32_t alloc_size = 4 * std::stoul(value->get_value());
      ir_list.emplace_back(ir::op_type::SPACE,
                           OPERAND_VALUE(std::to_string(alloc_size)));
    }
  } else {
    init_value.emplace_back(is_const ? value : OPERAND_VALUE("0"));

    if (ir_context->is_global_context()) {
      ir_list.emplace_back(ir::op_type::WORD, value);
    } else {
      ir_list.emplace_back(
          ir::op_type::STR, new ir::Operand(array_name),
          OPERAND_VALUE(std::to_string(4 * init_value.size() - 4)), value);
    }
  }
}
void compiler::Item_decl_var::generate_ir_helper(
    compiler::ir::IRContext* const ir_context, compiler::ir::ir_list& ir_list,
    const basic_type& b_type) const {
  const std::string name = identifier->get_name();

  compiler::ir::Operand* const default_value = new compiler::ir::Operand(
      compiler::to_ir_type(b_type), "", "0", false, false);

  // Check current scope.
  if (ir_context->is_global_context() == true) {
    const std::string name_symbol =
        compiler::concatenate(ir::global_sign, name);
    ir_list.emplace_back(compiler::ir::op_type::GLOBAL_BEGIN, name_symbol);
    ir_list.emplace_back(compiler::ir::op_type::WORD, default_value);
    ir_list.emplace_back(compiler::ir::op_type::GLOBAL_END, name_symbol);

    // Create a new symbol for the symbol table.
    compiler::Symbol* const symbol = new compiler::Symbol(
        name_symbol, compiler::symbol_type::VAR_TYPE, false);
    ir_context->get_symbol_table()->add_symbol(name, symbol);
  } else {
    const uint32_t id = ir_context->get_symbol_table()->get_available_id();
    const std::string name_symbol = compiler::concatenate(ir::local_sign, id);
    // Create a temporary symbol for the symbol table.
    compiler::Symbol* const symbol =
        new compiler::Symbol(name_symbol, compiler::symbol_type::VAR_TYPE,
                             false, {}, compiler::to_ir_type(b_type));
    ir_context->get_symbol_table()->add_symbol(name, symbol);
    // Generate an explicit declare IR.
    ir_list.emplace_back(ir::op_type::ALLOCA, nullptr,
                         new ir::Operand(name_symbol));
  }
}

void compiler::Item_decl_var_init::generate_ir_helper(
    ir::IRContext* const ir_context, ir::ir_list& ir_list,
    const basic_type& b_type) const {
  try {
    const std::string name = identifier->get_name();

    std::string name_symbol;
    // Check current scope.
    if (ir_context->is_global_context()) {
      name_symbol = compiler::concatenate(ir::global_sign, name);
      ir::Operand* const result = expression->eval_runtime(ir_context);
      ir_list.emplace_back(compiler::ir::op_type::GLOBAL_BEGIN, name_symbol);
      ir_list.emplace_back(compiler::ir::op_type::WORD, result);
      ir_list.emplace_back(compiler::ir::op_type::GLOBAL_END, name_symbol);

      if (is_const) {
        compiler::Symbol_const* const symbol = new compiler::Symbol_const(
            name_symbol, compiler::symbol_type::VAR_TYPE, result->get_value(),
            false, {}, {}, compiler::to_ir_type(b_type));
        ir_context->get_symbol_table()->add_const(
            identifier->get_name(),
            dynamic_cast<compiler::Symbol_const*>(symbol));
      } else {
        compiler::Symbol* const symbol =
            new compiler::Symbol(name_symbol, compiler::symbol_type::VAR_TYPE);
        ir_context->get_symbol_table()->add_symbol(identifier->get_name(),
                                                   symbol);
      }
    } else {
      const uint32_t id = ir_context->get_symbol_table()->get_available_id();
      name_symbol = compiler::concatenate(ir::local_sign, id);
      // Generate an explicit declare IR.
      ir_list.emplace_back(ir::op_type::ALLOCA, nullptr,
                           new ir::Operand(name_symbol));

      compiler::Symbol* const symbol =
          new compiler::Symbol(name_symbol, compiler::symbol_type::VAR_TYPE,
                               false, {}, compiler::to_ir_type(b_type));
      ir_context->get_symbol_table()->add_symbol(identifier->get_name(),
                                                 symbol);

      compiler::Item_stmt_assign* const assignment =
          new compiler::Item_stmt_assign(lineno, identifier, expression);
      assignment->generate_ir(ir_context, ir_list);

      if (is_const) {
        ir_context->get_symbol_table()->add_const(
            name, new compiler::Symbol_const(
                      name_symbol, compiler::symbol_type::VAR_TYPE,
                      expression->eval_runtime(ir_context)->get_value()));
      }
    }

  } catch (const std::exception& e) {
    std::cerr << termcolor::red << termcolor::bold << lineno << ": " << e.what()
              << termcolor::reset << '\n';
    exit(1);
  }
}

void compiler::Item_decl::generate_ir(compiler::ir::IRContext* const ir_context,
                                      compiler::ir::ir_list& ir_list,
                                      const basic_type& b_type) const {
  stack.emplace_back(static_cast<Item*>(const_cast<Item_decl*>(this)));
  try {
    generate_ir_helper(ir_context, ir_list, b_type);
    stack.pop_back();
  } catch (const std::exception& e) {
    std::cerr << termcolor::red << termcolor::bold << lineno << ": " << e.what()
              << termcolor::reset << '\n';
    stack.pop_back();
    exit(1);
  }
}

void compiler::Item_stmt_decl::generate_ir_helper(
    compiler::ir::IRContext* const ir_context,
    compiler::ir::ir_list& ir_list) const {
  for (compiler::Item_decl* const declaration : declarations) {
    declaration->generate_ir(ir_context, ir_list, type);
  }
}

uint32_t compiler::Item_decl_array::calculate_array_size(
    compiler::ir::IRContext* const ir_context, compiler::ir::ir_list& ir_list,
    const compiler::basic_type& b_type,
    std::vector<ir::Operand*>& array_shape) const {
  // Determine the shape of the array.
  for (compiler::Item_expr* const shape : identifier->get_array_shape()) {
    ir::Operand* const value = shape->eval_runtime(ir_context);
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
    compiler::ir::IRContext* const ir_context, compiler::ir::ir_list& ir_list,
    const compiler::basic_type& b_type) const {
  try {
    // Determine the size of the array.
    std::vector<ir::Operand*> array_shape;
    const uint32_t array_size =
        calculate_array_size(ir_context, ir_list, b_type, array_shape);

    ir::Operand* const operand_alloc_notation = OPERAND_VALUE(
        std::to_string(compiler::to_byte_length(b_type) * array_size));

    // Handle global array type.
    const std::string name = identifier->get_name();
    if (ir_context->is_global_context()) {
      const std::string name_symbol =
          compiler::concatenate(ir::global_sign, ir::arr_sign, name);
      ir_context->get_symbol_table()->add_symbol(
          name,
          new compiler::Symbol(name_symbol, compiler::symbol_type::ARRAY_TYPE,
                               false, array_shape));
      ir_list.emplace_back(ir::op_type::GLOBAL_BEGIN, name_symbol);
      ir_list.emplace_back(ir::op_type::SPACE, operand_alloc_notation);
      ir_list.emplace_back(ir::op_type::GLOBAL_END, name_symbol);
      // Handle local array type.
    } else {
      // We need to emit the instruction for allocation. Although this is not
      // needed in the final assembly, but we will need it for live interval
      // analysis.
      const std::string name_symbol = compiler::concatenate(
          ir::local_sign, ir::arr_sign,
          ir_context->get_symbol_table()->get_available_id());
      ir_context->get_symbol_table()->add_symbol(
          name, new compiler::Symbol(
                    name_symbol, compiler::symbol_type::ARRAY_TYPE, true,
                    array_shape, compiler::to_ir_type(b_type)));
      ir_list.emplace_back(ir::op_type::ALLOCA, nullptr,
                           new ir::Operand(name_symbol),
                           operand_alloc_notation);
    }
  } catch (const std::exception& e) {
    std::cerr << termcolor::red << termcolor::bold << lineno << ": " << e.what()
              << termcolor::reset << '\n';
    exit(1);
  }
}

void compiler::Item_decl_array_init::generate_ir_helper(
    compiler::ir::IRContext* const ir_context, compiler::ir::ir_list& ir_list,
    const basic_type& b_type) const {
  try {
    std::vector<ir::Operand*> array_shape;
    const uint32_t array_size =
        calculate_array_size(ir_context, ir_list, b_type, array_shape);
    ir::Operand* const operand_alloc_notation = new ir::Operand(
        compiler::to_ir_type(b_type), "",
        std::to_string(compiler::to_byte_length(b_type) * array_size), false,
        false);

    // Handle initial value type.
    const std::string name = identifier->get_name();
    std::vector<ir::Operand*> initial_values;
    if (ir_context->is_global_context()) {
      const std::string name_symbol =
          compiler::concatenate(ir::global_sign, ir::arr_sign, name);
      ir_context->get_symbol_table()->add_symbol(
          name, new compiler::Symbol(
                    name_symbol, compiler::symbol_type::ARRAY_TYPE, true,
                    array_shape, compiler::to_ir_type(b_type)));
      ir_list.emplace_back(ir::op_type::GLOBAL_BEGIN, name_symbol);
      // Handle init values.
      init_helper(init_value->get_value_list(), initial_values, 0, ir_context,
                  ir_list, compiler::to_ir_type(b_type));
      ir_list.emplace_back(ir::op_type::GLOBAL_END, name_symbol);
    } else {
      // We call a memset to handle local initilization.
      const std::string name_symbol = compiler::concatenate(
          ir::local_sign, ir::arr_sign,
          ir_context->get_symbol_table()->get_available_id());

      ir_context->get_symbol_table()->add_symbol(
          name, new compiler::Symbol(
                    name_symbol, compiler::symbol_type::ARRAY_TYPE, true,
                    array_shape, compiler::to_ir_type(b_type)));
      ir_list.emplace_back(ir::op_type::ALLOCA, nullptr,
                           new ir::Operand(name_symbol),
                           operand_alloc_notation);
      ir_list.emplace_back(ir::op_type::MALLOC, nullptr,
                           new ir::Operand(name_symbol),
                           operand_alloc_notation);

      init_helper(init_value->get_value_list(), initial_values, 0, ir_context,
                  ir_list, compiler::to_ir_type(b_type));
    }
  } catch (const std::exception& e) {
    std::cerr << termcolor::red << termcolor::bold << lineno << ": " << e.what()
              << termcolor::reset << '\n';
    exit(1);
  }
}

// FIXME: Empty list is skipped but the offset is not correct.
void compiler::Item_decl_array_init::init_helper(
    const std::vector<compiler::Item_literal_array_init*> value_list,
    std::vector<compiler::ir::Operand*>& init_value, const uint32_t& index,
    compiler::ir::IRContext* const ir_context, compiler::ir::ir_list& ir_list,
    const ir::var_type& var_type) const {
  // This function is a recursive function that initilzes the array.
  // The reason why the function is implemented in a recursive manner is in that
  // the scalar initialization list may be nested just like thw following
  // representation:
  //      int foo[100] = {{{1,2,3}, {1,2,{3}}}}.
  // So we have to visit each member seperately.

  const std::vector<compiler::Item_expr*> shape = identifier->get_array_shape();
  const std::string array_name = ir_context->get_symbol_table()
                                     ->find_symbol(identifier->get_name())
                                     ->get_name();
  if (index >= shape.size()) {
    return;
  }

  uint32_t size = 1, write_size = 0;
  // Evaluate the size of the dimension from index to the end of the shape
  // array.
  for (auto iter = shape.begin() + index; iter != shape.end(); iter++) {
    size *= std::stoul((*iter)->eval_runtime(ir_context)->get_value());
  }

  const uint32_t res =
      std::stoul(shape[index]->eval_runtime(ir_context)->get_value());
  uint32_t size_this_shape = size / res;

  for (compiler::Item_literal_array_init* const value : value_list) {
    if (value->get_is_numeric()) {
      write_size += 1;

      ir::Operand* const val =
          value->get_value()->eval_runtime(ir_context, ir_list);
      do_init_array(val, ir_context, ir_list, init_value, array_name);
    } else {
      // If the intializaiton list not a numeric value, then it means it has
      // nested intialization list which we need to visit later.
      if (write_size % size_this_shape != 0) {
        ir::Operand* const val = OPERAND_VALUE(
            std::to_string(size_this_shape - (write_size % size_this_shape)));
        do_init_array(val, ir_context, ir_list, init_value, array_name, true,
                      is_const);
      }

      // Visit child intialization list.
      init_helper(value->get_value_list(), init_value, index + 1, ir_context,
                  ir_list, var_type);
      write_size += size_this_shape;
    }
  }

  ir::Operand* const val = OPERAND_VALUE(std::to_string(size - write_size));
  do_init_array(val, ir_context, ir_list, init_value, array_name, true,
                is_const);
}