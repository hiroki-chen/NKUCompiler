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
#include <common/utils.hh>
#include <frontend/nodes/item_func.hh>
#include <sstream>

compiler::Item_func_call_list::Item_func_call_list(const uint32_t& line_no)
    : Item_expr(line_no)
{
}

compiler::Item_func_call::Item_func_call(
    const uint32_t& line_no,
    Item_ident* const identifier,
    Item_func_call_list* const arguments)
    : Item_expr(line_no)
    , identifier(identifier)
    , arguments(arguments)
{
}

compiler::Item_func_def_arg::Item_func_def_arg(
    const uint32_t& line_no,
    const basic_type& type,
    Item_ident* const identifier)
    : Item_expr(line_no)
    , type(type)
    , identifier(identifier)
{
}

compiler::Item_func_def_list::Item_func_def_list(const uint32_t& line_no)
    : Item_expr(line_no)
{
}

compiler::Item_func_def::Item_func_def(const uint32_t& line_no,
    const basic_type& return_type,
    Item_ident* const identifier,
    Item_func_def_list* const parameter,
    Item_block* const func_body)
    : Item(line_no)
    , return_type(return_type)
    , identifier(identifier)
    , parameter(parameter)
    , func_body(func_body)
{
}

void compiler::Item_func_call_list::add_arg(Item_expr* const arg)
{
    arguments.emplace_back(arg);
}

void compiler::Item_func_def_list::add_arg(Item_func_def_arg* const arg)
{
    arguments.emplace_back(arg);
}

std::string
compiler::Item_func_call_list::print_result(void) const
{
    std::ostringstream oss;
    oss << "Node: Function Call List" << std::endl;
    oss << "--Argument List:" << std::endl;
    for (auto item : arguments) {
        oss << "--" << item->print_result() << std::endl;
    }
    return oss.str();
}

std::string
compiler::Item_func_call::print_result(void) const
{
    std::ostringstream oss;
    oss << "Node: Function Call" << std::endl;
    oss << "--Identifier" << std::endl << identifier->print_result();
    oss << "--Arguments" << std::endl << arguments->print_result();
    return oss.str();
}

std::string
compiler::Item_func_def_arg::print_result(void) const
{
    std::ostringstream oss;
    oss << "Node: Function Definition Argument with type " << compiler::to_string(type) << std::endl;
    oss << "--Identifier" << std::endl << identifier->print_result();
    return oss.str();
}

std::string
compiler::Item_func_def_list::print_result(void) const
{
    std::ostringstream oss;
    oss << "Node: Function Definition Argument List" << std::endl;
    oss << "--Arguments" << std::endl;
    for (auto item : arguments) {
        oss << "--" << item->print_result() << std::endl;
    }
    return oss.str();
}

std::string
compiler::Item_func_def::print_result(void) const
{
    std::ostringstream oss;
    oss << "Node: Function Definition with return type " << compiler::to_string(return_type) << std::endl;
    oss << "--" << identifier->print_result() << std::endl;
    oss << "--" << parameter->print_result() << std::endl;
    oss << "--" << func_body->print_result() << std::endl;
    return oss.str();
}