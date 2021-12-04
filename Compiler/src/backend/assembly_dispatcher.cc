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
#include <backend/analyzer.hh>
#include <backend/assembly.hh>
#include <backend/assembly_dispatcher.hh>
#include <cassert>
#include <common/utils.hh>

static compiler::reg::branch_type to_branch_type(
    const compiler::ir::op_type& type) {
  switch (type) {
    case compiler::ir::op_type::JMP:
      return compiler::reg::branch_type::B;
    case compiler::ir::op_type::JEQ:
      return compiler::reg::branch_type::BEQ;
    case compiler::ir::op_type::JNE:
      return compiler::reg::branch_type::BNE;
    case compiler::ir::op_type::JG:
      return compiler::reg::branch_type::BGT;
    case compiler::ir::op_type::JGE:
      return compiler::reg::branch_type::BGE;
    case compiler::ir::op_type::JL:
      return compiler::reg::branch_type::BLT;
    case compiler::ir::op_type::JLE:
      return compiler::reg::branch_type::BLE;
    default:
      throw compiler::fatal_error("Error: Internal logic error.");
  }
}

static compiler::reg::mov_type to_move_type(const compiler::ir::op_type& type) {
  switch (type) {
    case compiler::ir::op_type::MOV:
    case compiler::ir::op_type::PHI:
      return compiler::reg::mov_type::MOV_N;
    case compiler::ir::op_type::MOVEQ:
      return compiler::reg::mov_type::MOVEQ;
    case compiler::ir::op_type::MOVGE:
      return compiler::reg::mov_type::MOVGE;
    case compiler::ir::op_type::MOVGT:
      return compiler::reg::mov_type::MOVGT;
    case compiler::ir::op_type::MOVLE:
      return compiler::reg::mov_type::MOVLE;
    case compiler::ir::op_type::MOVNE:
      return compiler::reg::mov_type::MOVNE;
    case compiler::ir::op_type::MOVLT:
      return compiler::reg::mov_type::MOVLT;
    default:
      throw compiler::fatal_error("Error: Internal logic error.");
  }
}

static compiler::reg::binary_type to_binary_type(
    const compiler::ir::op_type& type) {
  switch (type) {
    case compiler::ir::op_type::IADD: {
      return compiler::reg::binary_type::ADD;
    }
    case compiler::ir::op_type::ISUB: {
      return compiler::reg::binary_type::SUB;
    }
    case compiler::ir::op_type::IMUL: {
      return compiler::reg::binary_type::MUL;
    }
    case compiler::ir::op_type::IDIV: {
      return compiler::reg::binary_type::DIV;
    }
    case compiler::ir::op_type::IMOD: {
      return compiler::reg::binary_type::MOD;
    }
    case compiler::ir::op_type::BAND: {
      return compiler::reg::binary_type::BAND;
    }
    default:
      throw compiler::fatal_error("Error: Internal logic error.");
  }
}

compiler::Assembly_dispatcher* compiler::Assembly_dispatcher::dispatch(
    const compiler::ir::op_type& type, const ir::IR* const ir) {
  auto op_type = compiler::to_machine_type(type);

  switch (op_type) {
    case reg::inst_type::BINARY:
      return new compiler::Assembly_dispatcher_binary(type, ir);
    case reg::inst_type::BRANCH:
      return new compiler::Assembly_dispatcher_branch(type, ir);
    case reg::inst_type::UNARY:
      // Note that UMINUS and UADD are converted to binary types.
      return new compiler::Assembly_dispatcher_unary(type, ir);
    case reg::inst_type::CMP:
      return new compiler::Assembly_dispatcher_cmp(type, ir);
    case reg::inst_type::ALLOCA:
      return new compiler::Assembly_dispatcher_alloca(type, ir);
    case reg::inst_type::STACK:
      return new compiler::Assembly_dispatcher_stack(type, ir);
    case reg::inst_type::MOV:
      return new compiler::Assembly_dispatcher_mov(type, ir);
    case reg::inst_type::RET:
      return new compiler::Assembly_dispatcher_return(type, ir);
    case reg::inst_type::CALL:
      return new compiler::Assembly_dispatcher_call(type, ir);
    default:
      throw compiler::unsupported_operation("Error: This is not supported :(");
  }
}

void compiler::Assembly_dispatcher_binary::emit_machine_code(
    compiler::reg::Assembly_builder* const asm_builder) const {
  // Construct basic information.
  reg::Machine_block* const block = asm_builder->get_block();
  reg::Machine_operand* const dst = ir->get_dst()->emit_machine_operand();
  reg::Machine_operand* const operand_b = ir->get_op2()->emit_machine_operand();

  // Before simply generating machine instructions, we shall first check whether
  // the first operand is BOTH IMMEDIATE:
  // ADD r0, #1,  => This is forbidden in ARM assembly.
  reg::Machine_operand* operand_a = nullptr;
  if (false == ir->get_op1()->get_is_var()) {
    const std::string id = compiler::concatenate(
        reg::virtual_sign, asm_builder->get_available_id());
    // Insert an explicit MOV!
    reg::Machine_operand* const temp_virtual_reg =
        new reg::Machine_operand(reg::operand_type::VREG, id);
    reg::Machine_instruction* const m_inst_mov =
        new reg::Machine_instruction_mov(block, reg::mov_type::MOV_N,
                                         temp_virtual_reg,
                                         ir->get_op1()->emit_machine_operand());
    block->add_instruction(m_inst_mov);
    operand_a = new reg::Machine_operand(reg::operand_type::VREG, id);
  } else {
    operand_a = ir->get_op1()->emit_machine_operand();
  }

  compiler::reg::binary_type type_bin = to_binary_type(type);
  reg::Machine_instruction_binary* const m_inst =
      new reg::Machine_instruction_binary(block, type_bin, dst, operand_a,
                                          operand_b);

  block->add_instruction(m_inst);
}

// FIXME: Maybe this is not needed?...
void compiler::Assembly_dispatcher_unary::emit_machine_code(
    compiler::reg::Assembly_builder* const asm_builder) const {
  // This is not needed, but I keep it there.
  return;
}

void compiler::Assembly_dispatcher_cmp::emit_machine_code(
    compiler::reg::Assembly_builder* const asm_builder) const {
  // Construct basic information.
  reg::Machine_block* const block = asm_builder->get_block();
  reg::Machine_operand* const lhs = ir->get_op1()->emit_machine_operand();
  reg::Machine_operand* const rhs = ir->get_op2()->emit_machine_operand();

  reg::Machine_instruction_cmp* const m_inst =
      new reg::Machine_instruction_cmp(block, lhs, rhs);
  block->add_instruction(m_inst);
  m_inst->emit_assembly(std::cout);
}

void compiler::Assembly_dispatcher_branch::emit_machine_code(
    compiler::reg::Assembly_builder* const asm_builder) const {
  // Construct basic information.
  reg::Machine_block* const block = asm_builder->get_block();
  reg::Machine_operand* const label = new reg::Machine_operand(ir->get_label());

  reg::Machine_instruction_branch* const m_inst =
      new reg::Machine_instruction_branch(block, to_branch_type(type), label);
  m_inst->emit_assembly(std::cout);
  block->add_instruction(m_inst);
}

void compiler::Assembly_dispatcher_mov::emit_machine_code(
    compiler::reg::Assembly_builder* const asm_builder) const {
  // Construct basic information.
  reg::Machine_block* const block = asm_builder->get_block();
  reg::Machine_operand* const dst = ir->get_dst()->emit_machine_operand();
  reg::Machine_operand* const src = ir->get_op1()->emit_machine_operand();

  assert(dst->is_reg() || dst->is_vreg() && "Cannot move to non-register!");

  reg::Machine_instruction_mov* const m_inst =
      new reg::Machine_instruction_mov(block, to_move_type(type), dst, src);
  block->add_instruction(m_inst);
}

void compiler::Assembly_dispatcher_stack::emit_machine_code(
    compiler::reg::Assembly_builder* const asm_builder) const {
  // This should be the "push argument" statements.
}

void compiler::Assembly_dispatcher_alloca::emit_machine_code(
    compiler::reg::Assembly_builder* const asm_builder) const {
  return;
  // No need to emit anything.
}

void compiler::Assembly_dispatcher_call::emit_machine_code(
    compiler::reg::Assembly_builder* const asm_builder) const {
  // TODO: MOV arguments.
}

void compiler::Assembly_dispatcher_return::emit_machine_code(
    compiler::reg::Assembly_builder* const asm_builder) const {
  reg::Machine_block* const cur_block = asm_builder->get_block();
  // Handle return value. This should always be stored in r0.
  if (ir->get_dst() != nullptr) {
    reg::Machine_operand* const r0 =
        new reg::Machine_operand(reg::operand_type::REG, "r0");
    reg::Machine_operand* const return_value =
        ir->get_dst()->emit_machine_operand();
    reg::Machine_instruction_mov* const ret = new reg::Machine_instruction_mov(
        cur_block, reg::mov_type::MOV_N, r0, return_value);
    cur_block->add_instruction(ret);
  }

  // The callee should restore the envionment.
  // ldr r14, [sp,#0]
  reg::Machine_operand* const r14 =
      new reg::Machine_operand(reg::operand_type::REG, "r14");
  reg::Machine_operand* const sp =
      new reg::Machine_operand(reg::operand_type::REG, reg::stack_pointer);
  reg::Machine_operand* const offset =
      new reg::Machine_operand(reg::operand_type::IMM, "0");
  reg::Machine_instruction_load* const ldr =
      new reg::Machine_instruction_load(cur_block, r14, sp, offset);
  cur_block->add_instruction(ldr);

  // add sp, sp, #4
  const std::string size =
      std::to_string(ir->get_func_call_list().size() * 4 + 4);
  reg::Machine_operand* const stack_size =
      new reg::Machine_operand(reg::operand_type::IMM, size);
  reg::Machine_instruction_binary* const add =
      new reg::Machine_instruction_binary(cur_block, reg::binary_type::ADD, sp,
                                          sp, stack_size);
  cur_block->add_instruction(add);

  // mov pc, r14
  reg::Machine_operand* const pc =
      new reg::Machine_operand(reg::operand_type::REG, reg::program_counter);
  reg::Machine_instruction_mov* const mov = new reg::Machine_instruction_mov(
      cur_block, reg::mov_type::MOV_N, pc, r14);
  cur_block->add_instruction(mov);
}