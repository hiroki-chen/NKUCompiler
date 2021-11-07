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
#include <ir/context.hh>
#include <common/compile_excepts.hh>

compiler::ir::IRContext::IRContext()
{
    symbol_table.enter_scope();
}

void compiler::ir::IRContext::enter_scope(void)
{
    if (symbol_table.get_top_scope_uuid() == -1) {
        throw fatal_error("Error: The global symbol table is not found!");
    }
    symbol_table.enter_scope();
}

void compiler::ir::IRContext::leave_scope(void)
{
    if (symbol_table.get_top_scope_uuid() == 0) {
        throw fatal_error("Error: The compiler is trying to leave the global scope!");
    }
    symbol_table.leave_scope();
}