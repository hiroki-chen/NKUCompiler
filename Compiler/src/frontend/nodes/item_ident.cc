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
#include <frontend/nodes/item_ident.hh>

#include <sstream>

compiler::Item_ident::Item_ident(const uint32_t& line_no, const std::string& name)
    : Item_expr(line_no)
    , name(name)
{
}

compiler::Item_ident_array::Item_ident_array(const uint32_t& line_no, const std::string& name)
    : Item_ident(line_no, name)
{
}

compiler::Item_ident_func::Item_ident_func(const uint32_t& line_no, const std::string& name)
    : Item_ident(line_no, name)
{
}

compiler::Item_ident_pointer::Item_ident_pointer(const uint32_t& line_no, const std::string& name, Item_expr* point_to)
    : Item_ident(line_no, name)
    , point_to(point_to)
{
}

void compiler::Item_ident_array::add_shape(Item_expr* const shape)
{
    array_shape.emplace_back(shape);
}

// TODO: We need to lookup the symbol table and get its value :)
std::string
compiler::Item_ident::print_result(const uint32_t& indent, const bool& leaf) const
{
    std::ostringstream oss;
    print_indent(indent, leaf, oss);
    oss << "Node: Identifier with name "
        << termcolor::red << name << termcolor::reset << std::endl;
    return oss.str();
}

std::string
compiler::Item_ident_func::print_result(const uint32_t& indent, const bool& leaf) const
{
    std::ostringstream oss;
    print_indent(indent, leaf, oss);
    oss << "Node: Identifier Function with name "
        << termcolor::red << name << termcolor::reset << std::endl;
    return oss.str();
}

std::string
compiler::Item_ident_array::print_result(const uint32_t& indent, const bool& leaf) const
{
    std::ostringstream oss;
    print_indent(indent, leaf, oss);
    oss << "Node: Array Identifier with name "
        << termcolor::red << name << termcolor::reset << ", and the shape is ";
    for (uint32_t i = 0; i < array_shape.size(); i++) {
        oss << array_shape[i]->print_result(indent + 2, i == array_shape.size() - 1) << " "; // Each number is a dimension.
    }
    oss << std::endl;
    return oss.str();
}