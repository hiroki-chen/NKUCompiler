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

namespace compiler {
/**
 * @brief The most basic type for each node in the AST.
 * 
 */
typedef class Item {
protected:
    const uint32_t line_no;

public:
    /**
     * @brief Defines the type of the item.
     * 
     */
    typedef enum type {
        EXPR_ITEM,
        FUNC_DEF_ITEM,
        DECLARE_ITEM,
    } type;

    Item() = delete;

    Item(const Item& item) = delete;

    Item(const uint32_t& line_no);

    virtual Item::type get_type(void) const = 0;

    virtual uint32_t get_line_no(void) const { return line_no; }

    // virtual void print_result() const = 0;

    virtual ~Item() = default;
} Item;

} // namespace compiler

#endif