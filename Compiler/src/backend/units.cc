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

bool compiler::reg::Comparator::operator()(
    const compiler::reg::Machine_operand* lhs,
    const compiler::reg::Machine_operand* rhs) const {
  return *lhs < *rhs;
}

static std::string escape_string(const std::string& in) {
  std::string ret = std::move(in);

  if (ret.find("@") != std::string::npos) {
    ret.replace(ret.find("@"), 1, "");
  }

  if (ret.find("&") != std::string::npos) {
    ret.replace(ret.find("&"), 1, "");
  }
  return ret;
}

void compiler::reg::Machine_block::emit_assembly(std::ostream& os) const {
  // Emit the label.
  os << escape_string(label) << ":\n";
  if (false == inst_list.empty()) {
    for (compiler::reg::Machine_instruction* const instruction : inst_list) {
      instruction->emit_assembly(os);
    }
  }
}

void compiler::reg::Machine_function::backup_registers(void) {
  // Push all the needed registers.
  for (auto reg : compiler::reg::general_registers) {
    reg::Machine_instruction_stack* const stack_r =
        new reg::Machine_instruction_stack(
            *get_blocks()->begin(), reg::stack_type::PUSH,
            new reg::Machine_operand(reg::operand_type::REG, reg));
    add_func_prologue_instruction(stack_r);
  }
}

void compiler::reg::Machine_function::emit_assembly(std::ostream& os) const {
  const std::string demangled_func =
      function_name.substr(1, function_name.find_last_of("_") - 1);
  os << ".globl " << demangled_func << '\n';
  os << ".type " << demangled_func << ", %function" << '\n';
  os << demangled_func << ":\n";
  // Allocate the stack and preserve the environment.

  // FIXME: There is one question left: whether we should allocate the stack
  //        size in advance or after every instruction within the function body
  //        is generated, since we may have to spill some data on the stack.
  // Hint:
  // 1. Save fp
  // 2. fp = sp
  // 3. Save callee saved register
  // 4. Allocate stack space for local variable.

  // Emit the preparation instructions.
  for (compiler::reg::Machine_instruction* const prologue : func_prologue) {
    prologue->emit_assembly(os);
  }

  // Traverse all the block in block_list to print assembly code.
  for (compiler::reg::Machine_block* const block : block_list) {
    block->emit_assembly(os);
  }
  os << '\n';
}

void compiler::reg::Machine_unit::emit_global(std::ostream& os) const {
  // Set global definitions.
  os << "\n.data";

  for (auto def : *global_defs->get_ir_list()) {
    if (def.get_op_type() == compiler::ir::GLOBAL_BEGIN) {
      os << '\n';
      const std::string name = escape_string(def.get_label());
      os << ".globl " << name << '\n';
      os << name << ":\n";
    }

    if (def.get_op_type() == compiler::ir::WORD) {
      os << ".word " << def.get_dst()->get_value() << "\n";
    } else if (def.get_op_type() == compiler::ir::SPACE &&
               def.get_dst()->get_value() != "0") {
      os << ".space " << def.get_dst()->get_value() << "\n";
    }
  }
  os << '\n';
}

void compiler::reg::Machine_unit::emit_assembly(std::ostream& os) const {
  // Emit ARM-v7 header template.
  os << compiler::reg::assembly_template;
  emit_global(os);

  for (compiler::reg::Machine_function* const func : func_list) {
    func->emit_assembly(os);
  }

  os << ".ident \"" << copyright << " "
     << std::chrono::seconds(std::time(NULL)).count() << "\"";
}