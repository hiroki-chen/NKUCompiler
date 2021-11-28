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
#include <common/compile_excepts.hh>
#include <frontend/nodes/item.hh>

/**
 * @brief Used to temporarily store nodes for evaluation, since values can only
 * be computed after the deepmost node is evaluated.
 *
 */
compiler::NodeStack stack;

void compiler::Item_root::generate_ir_helper(
    ir::IRContext* const ir_context, ir::ir_list& ir_list) const {
  for (Item* const child : children) {
    child->generate_ir(ir_context, ir_list);
  }
}

void compiler::Item::generate_ir(ir::IRContext* const ir_context,
                                 ir::ir_list& ir_list) const {
  stack.emplace_back(const_cast<Item*>(this));
  try {
    generate_ir_helper(ir_context, ir_list);
    stack.pop_back();
  } catch (const std::exception& e) {
    std::cerr << termcolor::red << termcolor::bold << lineno << ": " << e.what() << termcolor::reset << std::endl;
    stack.pop_back();
    // Exception is not handled.
    exit(1);
  }
}

void compiler::Item::generate_ir_helper(ir::IRContext* const ir_context,
                                        ir::ir_list& ir_list) const {
  throw compiler::unsupported_operation(
      "Cannot generate IR for an abstract class!");
}