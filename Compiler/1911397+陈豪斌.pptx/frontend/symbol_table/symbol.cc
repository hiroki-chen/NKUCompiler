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
                         const std::vector<ir::Operand*>& shape,
                         const ir::var_type& var_type)
    : name(name),
      type(type),
      is_pointer(is_pointer),
      shape(shape),
      var_type(var_type),
      arg_count(0) {}

compiler::Symbol::Symbol(const std::string& name, const symbol_type& type,
                         const uint32_t& arg_count,
                         const ir::var_type& var_type)
    : name(name),
      type(type),
      arg_count(arg_count),
      is_pointer(0),
      shape({}),
      var_type(var_type) {}

compiler::Symbol::Symbol(const Symbol& symbol)
    : name(symbol.name),
      type(symbol.type),
      is_pointer(symbol.is_pointer),
      arg_count(symbol.arg_count),
      var_type(symbol.var_type) {
  for (auto item : symbol.shape) {
    shape.emplace_back(new compiler::ir::Operand(*item));
  }
}

compiler::Symbol_const::Symbol_const(
    const std::string& name, const symbol_type& type, const std::string& value,
    const bool& is_pointer, const std::vector<ir::Operand*>& shape,
    const std::vector<std::string>& values, const ir::var_type& var_type)
    : Symbol(name, type, is_pointer, shape, var_type),
      values(values.begin(), values.end()),
      value(value) {}

compiler::Symbol_const::Symbol_const(const Symbol_const& symbol_const)
    : Symbol(symbol_const),
      value(symbol_const.value),
      values(symbol_const.values.begin(), symbol_const.values.end()) {}