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
#include <frontend/symbol_table/symbol_table.hh>

#include <sstream>

compiler::Symbol_table::Symbol_table(const uint32_t& uuid)
    : uuid(uuid)
{
}

compiler::Symbol* compiler::Symbol_table::find_symbol(const std::string& name, const bool& recursive)
{
    // Iterate over the current table and the parent table.
    Symbol_table* cur = this;
    while (cur != nullptr) {
        auto cur_symbol_table = cur->get_symbol_table();
        auto iter = cur_symbol_table.find(name);

        if (iter != cur_symbol_table.end()) {
            return iter->second;
        } else if (recursive) {
            cur = cur->parent_table;
        } else {
            break;
        }
    }

    // Not found. Raise an error.
    std::ostringstream oss;
    oss << "Error: Symbol " << name << " is not declaraed.";
    throw compiler::undeclared_symbol(oss.str());
    return nullptr;
}

bool compiler::Symbol_table::exist(const std::string& name)
{
    if (find_symbol(name, false) != nullptr) {
        std::ostringstream oss;
        oss << "Error: Symbol " << name << " is already defined! Redefinition shadows the previous definition.";
        throw compiler::redefined_symbol(oss.str());
    } else {
        return false;
    }
}

// TODO: Implement it.
void compiler::Symbol_table::add_symbol(const std::string& name, Symbol* const symbol)
{
}