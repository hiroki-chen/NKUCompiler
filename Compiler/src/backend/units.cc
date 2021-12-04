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
#include <common/utils.hh>

static std::string escape_string(const std::string& in) {
  std::string ret = std::move(in);

  if (ret.find("@") != std::string::npos) {
    ret.replace(ret.find("@"), 1, "");
  }
  return ret;
}

void compiler::reg::Machine_block::emit_assembly(std::ostream& os) const {
  // Emit the label.
  if (false == inst_list.empty()) {
    os << escape_string(label) << ":\n";
    for (compiler::reg::Machine_instruction* const instruction : inst_list) {
      instruction->emit_assembly(os);
    }
  }
}

void compiler::reg::Machine_function::emit_assembly(std::ostream& os) const {
  const std::string demangled_func =
      function_name.substr(1, function_name.find_last_of("_") - 1);
  os << ".globl " << demangled_func << '\n';
  os << ".type " << demangled_func << ", %function" << '\n';
  os << demangled_func << ":" << '\n';
  // Allocate the stack and preserve the environment.
  compiler::generate_assembly("\tsub", reg::stack_pointer, reg::stack_pointer,
                              this->stack_size);

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

  for (compiler::reg::Machine_function* const func : func_list) {
    func->emit_assembly(os);
  }
}