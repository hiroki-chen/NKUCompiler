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
#include <frontend/nodes/item_decl.hh>
#include <sstream>

compiler::Item_decl::Item_decl(const uint32_t& line_no, const bool& is_decl)
    : Item(line_no)
    , is_decl(is_decl)
{
}

compiler::Item_stmt_decl::Item_stmt_decl(const uint32_t& line_no, const basic_type& type)
    : Item_stmt(line_no)
    , type(type)
{
}

compiler::Item_decl_var::Item_decl_var(const uint32_t& line_no, Item_ident* const identifier, const bool& is_decl)
    : Item_decl(line_no, is_decl)
    , identifier(identifier)
{
}

compiler::Item_decl_array::Item_decl_array(const uint32_t& line_no, Item_ident_array* const identifier, const bool& is_decl)
    : Item_decl(line_no, is_decl)
    , identifier(identifier)
{
}

compiler::Item_decl_pointer::Item_decl_pointer(const uint32_t& line_no, Item_ident_pointer* const identifier, const bool& is_decl)
    : Item_decl(line_no, is_decl)
    , identifier(identifier)
{
}

compiler::Item_decl_var_init::Item_decl_var_init(
    const uint32_t& line_no,
    Item_ident* const identifier,
    Item_expr* const expression,
    const bool& is_const,
    const bool& is_decl)
    : Item_decl_var(line_no, identifier, is_decl)
    , expression(expression)
    , is_const(is_const)
{
}

compiler::Item_decl_array_init::Item_decl_array_init(
    const uint32_t& line_no,
    Item_ident_array* const identifier,
    Item_literal_array_init* const init_value,
    const bool& is_const,
    const bool& is_decl)
    : Item_decl_array(line_no, identifier, is_decl)
    , init_value(init_value)
    , is_const(is_const)
{
}

void compiler::Item_stmt_decl::add_declaration(Item_decl* const declaration)
{
    declarations.emplace_back(declaration);
}

std::string
compiler::Item_stmt_decl::print_result(void) const
{
    std::ostringstream oss;
    oss << "Node: Declaration" << std::endl;

    for (auto item : declarations) {
        oss << "--Declaration:" << item->print_result() << std::endl;
    }
    return oss.str();
}

std::string
compiler::Item_decl_var::print_result(void) const
{
    std::ostringstream oss;
    oss << "Node: Variable Declaration" << std::endl;
    oss << "-- " << identifier->print_result() << std::endl;
    return oss.str();
}

std::string
compiler::Item_decl_var_init::print_result(void) const
{
    std::ostringstream oss;
    oss << "Node: Variale Declaration with initial value";
    if (is_const == true) {
        oss << " and is CONST" << std::endl;
    }
    oss << "--Initial value: " << std::endl
        << expression->print_result() << std::endl;
    
    return oss.str();
}

std::string
compiler::Item_decl_array::print_result(void) const
{
    std::ostringstream oss;
    oss << "Node: Array Declaration" << std::endl;
    oss << "-- " << identifier->print_result() << std::endl;
    return oss.str();
}

std::string
compiler::Item_decl_array_init::print_result(void) const
{
    std::ostringstream oss;
    oss << "Node: Array Declaration with initial value" << std::endl;
    oss << "--Initial value: " << std::endl
        << init_value->print_result() << std::endl;
    return oss.str();
}

std::string
compiler::Item_decl_pointer::print_result(void) const
{
    std::ostringstream oss;
    oss << "Node: Pointer Declaration" << std::endl;
    oss << "--" << identifier->print_result();
    return oss.str();
}