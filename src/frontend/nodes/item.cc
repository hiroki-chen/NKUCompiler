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
#include <common/compile_excepts.hh>
#include <common/termcolor.hh>
#include <frontend/nodes/item.hh>
#include <sstream>
#include <string>

compiler::Item::Item(const uint32_t& lineno) : lineno(lineno) {}

compiler::Item_root::Item_root(const uint32_t& lineno) : Item(lineno) {}

void compiler::Item_root::add_child(Item* const child) {
  children.emplace_back(child);
}

std::string compiler::Item_root::print_result(const uint32_t& indent,
                                              const bool& leaf) const {
  std::ostringstream oss;

  oss << "Program Root: " << termcolor::reset << '\n';
  for (uint32_t i = 0; i < children.size(); i++) {
    oss << children[i]->print_result(indent, i == children.size() - 1);
  }
  return oss.str();
}