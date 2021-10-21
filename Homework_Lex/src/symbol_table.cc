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
#include <symbol_table.hh>

namespace compiler {

Symbol_table::Symbol_table()
{
    enter_scope();
}

void Symbol_table::enter_scope(void)
{
    symbol_table.push(std::map<std::string, Item_ident*>());
}

void Symbol_table::leave_scope(void)
{
    if (symbol_table.size() <= 0) {
        throw std::runtime_error("Symbol Table does not exists but you still tried to leave a scope?\n");
    } else {
        symbol_table.pop();
    }
}

void Symbol_table::put(Item_ident* const item)
{
    if (symbol_table.size() <= 0) {
        throw std::runtime_error("Symbol Table does not exists but you still tried to declare a symbol?\n");
    } else {
        symbol_table.top()[item->get_name()] = item;
    }
}

Item_ident*
Symbol_table::get(const std::string& name)
{
    if (symbol_table.top().count(name) == 0) {
        throw std::runtime_error("Undeclared identifier!\n");
    } else {
        return symbol_table.top().at(name);
    }
}

} // namespace compiler