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
#include <item_ident.hh>

compiler::Item_ident::Item_ident(
    const uint32_t& line_no,
    const std::string& name,
    const uint32_t scope)
    : Item(line_no)
    , name(name)
    , scope(scope)
{
}

compiler::Item_ident_int::Item_ident_int(
    const uint32_t& line_no,
    const std::string& name,
    const uint32_t scope,
    const int& value)
    : Item_ident(line_no, name, scope)
    , value(value)
{
}

compiler::Item_ident_real::Item_ident_real(
    const uint32_t& line_no,
    const std::string& name,
    const uint32_t scope,
    const double& value)
    : Item_ident(line_no, name, scope)
    , value(value)
{
}

compiler::Item_ident_char::Item_ident_char(
    const uint32_t& line_no,
    const std::string& name,
    const uint32_t scope,
    const char& value)
    : Item_ident(line_no, name, scope)
    , value(value)
{
}