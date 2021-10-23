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
#ifndef ITEM_IDENT_HH
#define ITEM_IDENT_HH

#include <frontend/nodes/item_expr.hh>

#include <string>
#include <vector>

namespace compiler {

/**
 * @brief Class for identifiers.
 * 
 */
typedef class Item_ident : public Item_expr {
protected:
    const std::string name;

public:
    virtual Item_expr::expr_type get_expr_type(void) const override { return Item_expr::expr_type::IDENTIFIER_TYPE; }

    virtual std::string get_name(void) const { return name; } 

    Item_ident() = delete;

    Item_ident(const uint32_t& line_no, const std::string& name);
} Item_ident;

/**
 * @brief Class for array identifiers.
 * 
 */
typedef class Item_ident_array final : public Item_ident {
protected:
    std::vector<Item_expr*> array_shape;

public:
    virtual void add_shape(Item_expr* const array_shape);

    Item_ident_array() = delete;

    Item_ident_array(const uint32_t& line_no, const std::string& name);

    virtual ~Item_ident_array() override = default;
} Item_ident_array;

typedef class Item_ident_pointer final : public Item_ident {
protected:
    Item_expr* point_to;

public:
    Item_ident_pointer() = delete;

    Item_ident_pointer(const uint32_t& line_no, const std::string& name, Item_expr* point_to);

    virtual ~Item_ident_pointer() override = default;
} Item_ident_pointer;
} // namespace compiler

#endif