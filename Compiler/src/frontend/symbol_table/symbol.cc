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
#include <frontend/symbol_table/symbol.hh>

compiler::Symbol::Symbol(const std::string& name, const symbol_type& type)
    : name(name)
    , type(type)
{
}

compiler::Symbol_func::Symbol_func(
    const std::string& name,
    const basic_type& return_type,
    Item_func_def_list* const arguments)
    : Symbol(name, compiler::symbol_type::FUNC_TYPE)
    , return_type(return_type)
    , arguments(arguments)
{
}