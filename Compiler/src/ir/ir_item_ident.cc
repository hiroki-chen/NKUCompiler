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
#include <common/compile_excepts.hh>
#include <frontend/nodes/item_ident.hh>
#include <frontend/nodes/item_literal.hh>

extern uint32_t opt_level;

compiler::ir::Operand* compiler::Item_ident::eval_runtime_helper(
    compiler::ir::IRContext* const ir_context) const {
  compiler::Symbol_table* const symbol_table = ir_context->get_symbol_table();
  try {
    compiler::Symbol_const* const symbol = symbol_table->find_const(name);
    if (symbol->get_is_pointer()) {
      throw compiler::fatal_error(
          "Cannot evaluate pointer / array type. What: " + name);
    } else {
      return compiler::ir::dump_value(symbol->get_values()[0]);
    }
  } catch (const std::exception& e) {
    if (opt_level > 0) {
      compiler::Symbol* const symbol_cur = symbol_table->find_symbol(name);
      compiler::Symbol_const* symbol_assign = symbol_table->find_assign_const(symbol_cur->get_name());
      return compiler::ir::dump_value(symbol_assign->get_values()[0]);
    }
    exit(1);
  }
}

compiler::ir::Operand* compiler::Item_ident::eval_runtime_helper(
    compiler::ir::IRContext* const ir_context,
    std::vector<compiler::ir::IR>& ir_list) const {
  try {
    compiler::Symbol_table* const symbol_table = ir_context->get_symbol_table();
    compiler::Symbol_const* const symbol =
        symbol_table->find_assign_const(name);

    if (symbol->get_is_pointer() || opt_level == 0) {
      return new compiler::ir::Operand(symbol->get_name());
    } else {
      try {
        return compiler::ir::dump_value(symbol->get_values()[0]);
      } catch (const std::exception& e) {
        // Cannot dump value... We return its name.
        return new compiler::ir::Operand(name);
      }
    }
  } catch (const std::exception& e) {
    std::cerr << termcolor::red << termcolor::bold << e.what() << termcolor::reset << std::endl;
    exit(1);
  }
}