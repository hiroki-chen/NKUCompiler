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
#include <ir/context.hh>

// Defines symbols for library functions.
static const std::vector<std::pair<std::string, compiler::Symbol*>>
    sysy_functions = {
        {"getint",
         new compiler::Symbol("getint", compiler::symbol_type::FUNC_TYPE, 0,
                              compiler::ir::var_type::i32)},
        {"getch",
         new compiler::Symbol("getch", compiler::symbol_type::FUNC_TYPE, 0,
                              compiler::ir::var_type::i8)},
        {"getarray",
         new compiler::Symbol("getarray", compiler::symbol_type::FUNC_TYPE, 1,
                              compiler::ir::var_type::i32)},
        {"putint",
         new compiler::Symbol("putint", compiler::symbol_type::FUNC_TYPE, 1,
                              compiler::ir::var_type::NONE)},
        {"putch",
         new compiler::Symbol("putch", compiler::symbol_type::FUNC_TYPE, 1,
                              compiler::ir::var_type::NONE)},
        {"putarray",
         new compiler::Symbol("putarray", compiler::symbol_type::FUNC_TYPE, 2,
                              compiler::ir::var_type::NONE)},
};

compiler::ir::IRContext::IRContext() {
  symbol_table.enter_scope();
  register_library_function(sysy_functions);
}

compiler::ir::IRContext::IRContext(const IRContext& ir_context)
    : symbol_table(ir_context.symbol_table),
      loop_variable(ir_context.loop_variable),
      loop_label(ir_context.loop_label),
      break_symbol(ir_context.break_symbol),
      continue_symbol(ir_context.continue_symbol),
      continue_phi_block(ir_context.continue_phi_block),
      break_phi_block(ir_context.break_phi_block) {}

void compiler::ir::IRContext::register_library_function(
    const std::vector<std::pair<std::string, compiler::Symbol*>>& functions) {
  compiler::Symbol_table* const symbol_table = get_symbol_table();
  for (auto function : functions) {
    symbol_table->add_symbol(function.first, function.second);
  }
}

void compiler::ir::IRContext::enter_scope(void) {
  if (symbol_table.get_top_scope_uuid() == -1) {
    throw fatal_error("Error: The global symbol table is not found!");
  }
  symbol_table.enter_scope();
}

void compiler::ir::IRContext::leave_scope(void) {
  if (symbol_table.get_top_scope_uuid() == 0) {
    throw fatal_error(
        "Error: The compiler is trying to leave the global scope!");
  }
  symbol_table.leave_scope();
}