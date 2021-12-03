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
#include <backend/assembly_dispatcher.hh>

compiler::Assembly_dispatcher* compiler::Assembly_dispatcher::dispatch(
    const compiler::ir::op_type& type) {
  switch (type) {
    case ir::op_type::IADD:
    case ir::op_type::ISUB:
    case ir::op_type::IMUL:
    case ir::op_type::IDIV:
    case ir::op_type::IMOD:
    case ir::op_type::BAND:
    case ir::op_type::BOR:
    case ir::op_type::BXOR:
      return new compiler::Assembly_dispatcher_binary();
    case ir::op_type::BNEG:
    case ir::op_type::LNOT:
      // Note that UMINUS and UADD are converted to binary types.
      return new compiler::Assembly_dispatcher_unary();
    case ir::op_type::JEQ:
    case ir::op_type::JNE:
    case ir::op_type::JG:
    case ir::op_type::JGE:
    case ir::op_type::JL:
    case ir::op_type::JLE:
    case ir::op_type::JMP:
      return new compiler::Assembly_dispatcher_branch();
    case ir::op_type::CMP:
      return new compiler::Assembly_dispatcher_cmp();
    case ir::op_type::MOV:
    case ir::op_type::MOVNE:
    case ir::op_type::MOVEQ:
    case ir::op_type::MOVGT:
    case ir::op_type::MOVGE:
    case ir::op_type::MOVLT:
    case ir::op_type::MOVLE:
      return new compiler::Assembly_dispatcher_mov();
    case ir::op_type::ALLOCA:
      return new compiler::Assembly_dispatcher_alloca();
    case ir::op_type::LDR:
    case ir::op_type::STR:
    case ir::op_type::PUSH:
      return new compiler::Assembly_dispatcher_stack();
  }
}

void compiler::Assembly_dispatcher_binary::emit_machine_code(
    compiler::reg::Assembly_builder* const asm_builder) const {}

// FIXME: Maybe this is not needed?...
void compiler::Assembly_dispatcher_unary::emit_machine_code(
    compiler::reg::Assembly_builder* const asm_builder) const {}

void compiler::Assembly_dispatcher_cmp::emit_machine_code(
    compiler::reg::Assembly_builder* const asm_builder) const {}

void compiler::Assembly_dispatcher_branch::emit_machine_code(
    compiler::reg::Assembly_builder* const asm_builder) const {}

void compiler::Assembly_dispatcher_mov::emit_machine_code(
    compiler::reg::Assembly_builder* const asm_builder) const {}

void compiler::Assembly_dispatcher_stack::emit_machine_code(
    compiler::reg::Assembly_builder* const asm_builder) const {}

void compiler::Assembly_dispatcher_alloca::emit_machine_code(
    compiler::reg::Assembly_builder* const asm_builder) const {}
