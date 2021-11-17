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
#include <frontend/nodes/item_struct.hh>
#include <sstream>

compiler::Item_struct_body::Item_struct_body(const uint32_t& lineno)
    : Item_stmt(lineno) {}

std::string compiler::Item_struct_body::print_result(const uint32_t& indent,
                                                     const bool& leaf) const {
  std::ostringstream oss;
  print_indent(indent, leaf, oss);
  oss << " Struct Body" << std::endl;
  for (uint32_t i = 0; i < struct_body.size(); i++) {
    oss << struct_body[i]->print_result(
        indent + 2, i == struct_body.size() - 1 ? true : false);
  }
  return oss.str();
}