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
#include <common/termcolor.hh>
#include <common/utils.hh>
#include <frontend/nodes/item_expr.hh>
#include <sstream>

compiler::Item_expr::Item_expr(const uint32_t& lineno)
    : Item(lineno)
{
}

compiler::Item_expr_cond::Item_expr_cond(const uint32_t& lineno, Item_expr* const item_expr)
    : Item_expr(lineno)
    , expr(item_expr)
{
}

compiler::Item_expr_comma::Item_expr_comma(const uint32_t& lineno)
    : Item_expr(lineno)
{
}

compiler::Item_expr_binary::Item_expr_binary(const uint32_t& lineno, const binary_type& type, Item_expr* const lhs, Item_expr* const rhs)
    : Item_expr(lineno)
    , type(type)
    , lhs(lhs)
    , rhs(rhs)
{
}

compiler::Item_expr_unary::Item_expr_unary(const uint32_t& lineno, const unary_type& type, Item_expr* const expr)
    : Item_expr(lineno)
    , type(type)
    , expr(expr)
{
}

std::string
compiler::Item_expr_cond::print_result(const uint32_t& indent, const bool& leaf) const
{
    std::ostringstream oss;
    print_indent(indent, leaf, oss);
    oss << " Conditional Expression" << std::endl;
    oss << expr->print_result(indent + 2, true);
    return oss.str();
}

std::string
compiler::Item_expr_comma::print_result(const uint32_t& indent, const bool& leaf) const
{
    std::ostringstream oss;
    print_indent(indent, leaf, oss);
    oss << " Comma Expression" << std::endl;
    for (uint32_t i = 0; i < expressions.size(); i++) {
        oss << expressions[i]->print_result(indent + 2, i == expressions.size() - 1 ? true : false);
    }
    return oss.str();
}

std::string
compiler::Item_expr_binary::print_result(const uint32_t& indent, const bool& leaf) const
{
    std::ostringstream oss;
    
    print_indent(indent, leaf, oss);
    oss << " Binary Expression with type "
        << termcolor::bright_blue << compiler::to_string(get_binary_type()) << termcolor::reset
        << std::endl;
    oss << lhs->print_result(indent + 2, false);
    oss << rhs->print_result(indent + 2, true);
    return oss.str();
}

std::string
compiler::Item_expr_unary::print_result(const uint32_t& indent, const bool& leaf) const
{
    std::ostringstream oss;
    
    print_indent(indent, leaf, oss);
    oss << " Unary Expression with type "
        << termcolor::bright_blue << compiler::to_string(get_unary_type()) << termcolor::reset
        << std::endl;
    oss << expr->print_result(indent + 2, false);
    return oss.str();
}