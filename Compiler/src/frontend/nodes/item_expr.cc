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
#include <frontend/nodes/item_expr.hh>

compiler::Item_expr::Item_expr(const uint32_t& line_no)
    : Item(line_no)
{
}

compiler::Item_expr_cond::Item_expr_cond(const uint32_t& line_no, Item_expr* const item_expr)
    : Item_expr(line_no)
    , expr(item_expr)
{
}

compiler::Item_expr_binary::Item_expr_binary(const uint32_t& line_no, const binary_type& type, Item_expr* const lhs, Item_expr* const rhs)
    : Item_expr(line_no)
    , type(type)
    , lhs(lhs)
    , rhs(rhs)
{
}

compiler::Item_expr_unary::Item_expr_unary(const uint32_t& line_no, const unary_type& type, Item_expr* const expr)
    : Item_expr(line_no)
    , type(type)
    , expr(expr)
{
}