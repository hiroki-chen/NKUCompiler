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
#ifndef SYMBOL_TABLE_HH
#define SYMBOL_TABLE_HH

#include <frontend/symbol_table/symbol.hh>

#include <vector>
#include <unordered_map>

// TODO: Implement our symbol table according to LAB5.

namespace compiler {
typedef class Symbol_table {
protected:
    std::unordered_map<std::string, Symbol*> symbol_table;

    Symbol_table* parent_table;

    Symbol_table* child_table;

public:
    Symbol_table() = default;

    virtual std::unordered_map<std::string, Symbol*> get_symbol_table(void) { return symbol_table; }

    virtual Symbol* find_symbol(const std::string& name, const bool& recursive = true);

    virtual bool add_symbol(Item_ident* const identifier);
} Symbol_table;
} // namespace compiler

#endif