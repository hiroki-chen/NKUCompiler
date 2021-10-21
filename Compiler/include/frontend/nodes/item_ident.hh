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
} // namespace compiler

#endif