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
#include <backend/units.hh>

void compiler::reg::Machine_block::emit_assembly(std::ostream& os) const {
  // Emit the label.
  os << ".L" << no << ":" << std::endl;
  for (compiler::reg::Machine_instruction* const instruction : inst_list) {
    instruction->emit_assembly(os);
  }
}

void compiler::reg::Machine_function::emit_assembly(std::ostream& os) const {
  os << ".globl " << function_name << std::endl;
  os << ".type " << function_name << ", %%function" << std::endl;
  os << function_name << ":" << std::endl;
  // Allocate the stack and preserve the environment.
  // TODO

  // Traverse all the block in block_list to print assembly code.
  for (compiler::reg::Machine_block* const block : block_list) {
    block->emit_assembly(os);
  }
}

void compiler::reg::Machine_unit::emit_global(std::ostream& os) const {
  return;
}

void compiler::reg::Machine_unit::emit_assembly(std::ostream& os) const {
  // Emit ARM-v7 header template.
  os << compiler::reg::assembly_template;
  emit_global(os);

  // Generate each function.
  for (compiler::reg::Machine_function* const func : func_list) {
    func->emit_assembly(os);
  }
}