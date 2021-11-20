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

compiler::Symbol::Symbol(const std::string& name, const symbol_type& type,
                         const bool& is_pointer,
                         const std::vector<ir::Operand*>& shape)
    : name(name), type(type), is_pointer(is_pointer), shape(shape) {}

compiler::Symbol_const::Symbol_const(const std::string& name,
                                     const symbol_type& type,
                                     compiler::Item_literal* const value,
                                     const bool& is_pointer,
                                     const std::vector<Item_literal*>& values)
    : Symbol(name, type, is_pointer),
      values(values.begin(), values.end()),
      value(value) {}