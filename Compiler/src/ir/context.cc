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
    symbol_table = new Symbol_table(1ul);
}

void compiler::ir::IRContext::enter_scope(void)
{
    if (symbol_table->get_uuid() == 0) {
        throw fatal_error("Error: The global symbol table is not found!");
    }

    // Set the correct relation between current and new symbol table.
    Symbol_table* const child = new Symbol_table(symbol_table->get_uuid() + 1);
    child->set_parent(symbol_table);
    symbol_table->set_child(child);
    symbol_table = symbol_table->get_child();
}

void compiler::ir::IRContext::leave_scope(void)
{
    if (symbol_table->get_uuid() == 1) {
        throw fatal_error("Error: The compiler is trying to leave the global scope!");
    }

    symbol_table = symbol_table->get_parent();
    // No longer needed.
    delete symbol_table->get_child();
}