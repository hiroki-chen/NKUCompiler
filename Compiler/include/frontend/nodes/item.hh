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
#ifndef ITEM_HH
#define ITEM_HH

#include <cstdint>
#include <vector>

namespace compiler {
/**
 * @brief The most basic type for each node in the AST.
 * 
 * @note YOU MUST NOT CREATE A DIRECT INSTANCE FROM ANY ABSTRACT CLASS AS THIS MEANS NOTHING.
 * 
 */
typedef class Item {
protected:
    const uint32_t line_no;

public:
    /**
     * @brief Defines the type of the item.
     * 
     * Basically, there is a super node called <b>Program</b> node, which is defined as a root node of
     * the whole AST. Expr, Decl, and Func_def are derived from the \ref{compiler::Item_root} node.
     * 
     */
    typedef enum type {
        ROOT_ITEM,
        EXPR_ITEM,
        FUNC_DEF_ITEM,
        DECLARE_ITEM,
    } type;

    Item() = delete;

    Item(const Item& item) = delete;

    Item(const uint32_t& line_no);

    virtual Item::type get_type(void) const = 0;

    virtual uint32_t get_line_no(void) const { return line_no; }
    
    /**
     * @brief Prints the the parse result as an abstract syntax tree.
     * @note This function will invoke all of its children's print_result(indent + 2) virtual function
     *       until there is no child anymore.
     *       You should implement this function in each <b>final</b> class.
     * 
     * @return std::string 
     */
    virtual std::string print_result(const uint32_t& indent, const bool& leaf) const = 0;

    virtual ~Item() = default;
} Item;

typedef class Item_root : public Item {
protected:
    std::vector<Item*> children;

public:
    virtual Item::type get_type(void) const override { return Item::type::ROOT_ITEM; }

    virtual void add_child(Item* const child);

    Item_root() = delete;

    Item_root(const uint32_t& line_no);

    virtual std::string print_result(const uint32_t& indent, const bool& leaf) const override;

    virtual ~Item_root() override = default;
} Item_root;

} // namespace compiler

#endif