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

#include <list>
#include <unordered_map>

// TODO: Implement our symbol table according to LAB5.

namespace compiler {

using symbol_table_type = std::unordered_map<std::string, Symbol*>;

/**
 * @brief Class for a single symbol table.
 * 
 */
typedef class Symbol_block {
protected:
    symbol_table_type block;

public:
    virtual Symbol* find_symbol(const std::string& name);

    virtual void add_symbol(const std::string& name, Symbol* const symbol);

    virtual symbol_table_type get_block(void) const { return block; }
} Symbol_block;

/**
 * @brief Class for symbol table.
 * 
 * @note Currently we do not take into consideration the storage of functions and structs.
 * 
 */
typedef class Symbol_table {
protected:
    int last_uuid;

    std::list<Symbol_block*> symbol_table;

public:
    virtual ~Symbol_table()
    {
        for (auto& cur : symbol_table)
            delete cur;
    }

    virtual int get_top_scope_uuid() const { return (int)symbol_table.size() - 1; }

    virtual int get_last_find_uuid(void) const { return last_uuid; }

    virtual Symbol_block* get_spec_block(const uint32_t& index);

    virtual std::list<Symbol_block*> get_symbol_table(void) { return symbol_table; }

    virtual Symbol* find_symbol(const std::string& name);

    virtual void add_symbol(const std::string& name, Symbol* const symbol);

    virtual void enter_scope() { symbol_table.push_front(new Symbol_block()); }

    virtual void leave_scope()
    {
        delete (*symbol_table.begin());
        symbol_table.pop_back();
    }
} Symbol_table;
} // namespace compiler

#endif