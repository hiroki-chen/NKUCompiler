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
    std::cerr << termcolor::red << termcolor::bold << e.what() << termcolor::reset << std::endl;
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
