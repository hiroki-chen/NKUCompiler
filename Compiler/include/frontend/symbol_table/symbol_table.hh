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

#include <unordered_map>
#include <vector>

// TODO: Implement our symbol table according to LAB5.

namespace compiler {

using symbol_table_type = std::unordered_map<std::string, Symbol*>;

/**
 * @brief Class for symbol table.
 * 
 * @note Currently we do not take into consideration the storage of functions and structs.
 * 
 */
typedef class Symbol_table {
protected:
    const uint32_t uuid;

    // The main table for entry storage.
    symbol_table_type symbol_table;

    Symbol_table* parent_table;

    Symbol_table* child_table;

    virtual bool exist(const std::string& name);

public:
    Symbol_table(const uint32_t& uuid);

    virtual uint32_t get_uuid(void) { return uuid; }

    virtual symbol_table_type get_symbol_table(void) { return symbol_table; }

    virtual Symbol* find_symbol(const std::string& name, const bool& recursive = true);

    virtual void add_symbol(const std::string& name, Symbol* const symbol);

    virtual void set_child(Symbol_table* const child) { child_table = child; }

    virtual void set_parent(Symbol_table* const parent) { parent_table = parent; }

    virtual Symbol_table* get_child(void) { return child_table; }

    virtual Symbol_table* get_parent(void) { return parent_table; }
} Symbol_table;
} // namespace compiler

#endif