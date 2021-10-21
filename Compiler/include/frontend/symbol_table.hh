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

#include <frontend/nodes/symbol_table.hh>
#include <frontend/nodes/item_ident.hh>

#include <map>
#include <vector>

namespace compiler {

/**
 * @brief A class for symbol table.
 * 
 *        The scope will increment as left brace appears. Especially, 1 denotes the global scope.
 * 
 */
typedef class Symbol_table {
protected:
    /**
     * @brief The symbol table.
     * 
     * The lookup of the symbol table is implemented as a stack.
     * (but not a std::stack because std::stack does not allow for traversal)
     * You are only allowed to access the top of the stack.
     */
    std::vector<std::map<std::string, Item_ident*>> symbol_table;

public:
    /**
     * @brief Called when a scope is entered.
     * 
     */
    void enter_scope(void);

    /**
     * @brief Called when a scope is leaved.
     * 
     */
    void leave_scope(void);

    /**
     * @brief Put an item into the symbol table in the current scope.
     * 
     * @param item 
     */
    void put(Item_ident* const item);

    /**
     * @brief Find a symbol in each scope.
     * 
     * @param name 
     * @return Item_ident* 
     */
    Item_ident* get(const std::string& name);

    /**
     * @brief Get the current scope object
     * 
     * @return uint32_t 
     */
    uint32_t get_current_scope(void) { return symbol_table.size(); }

    /**
     * @brief Construct a new Symbol_table object. By default there is a global symbol table.
     * 
     */
    Symbol_table();

    Symbol_table(const Symbol_table& symbol_table) = delete;

    virtual ~Symbol_table() = default;
} Symbol_table;

}

#endif