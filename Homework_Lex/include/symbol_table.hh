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

#include "item_ident.hh"

#include <map>
#include <stack>

namespace compiler {

/**
 * @brief A class for symbol table.
 * 
 *        The scope will increment as left brace appears. Especially, 1 denotes the global scope.
 * 
 */
typedef class Symbol_table {
private:
    std::stack<std::map<std::string, Item_ident*>> symbol_table;

public:
    void enter_scope(void);

    void leave_scope(void);

    void put(Item_ident* const item);

    Item_ident* get(const std::string& name);

    uint32_t get_current_scope(void) { return symbol_table.size(); }

    Symbol_table();

    Symbol_table(const Symbol_table& symbol_table) = delete;

    virtual ~Symbol_table() = default;
} Symbol_table;

}

#endif