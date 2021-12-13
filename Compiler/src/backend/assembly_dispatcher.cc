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

static void handle_mod_div(compiler::reg::Machine_block *const cur_block,
                           compiler::reg::Assembly_builder *const asm_builder,
                           compiler::ir::Operand *const dst,
                           compiler::reg::Machine_operand *const operand_a,
                           compiler::reg::Machine_operand *const operand_b,
                           const std::string &func_name) {
  using namespace compiler;
  // This will generate a function call.
  // mov r0, opa
  // mov r1, opb
  // bl __aeabi_idivxxx
  reg::Machine_operand *const r0 =
      new reg::Machine_operand(reg::operand_type::REG, "r0");
  reg::Machine_operand *const r1 =
      new reg::Machine_operand(reg::operand_type::REG, "r1");

  // Backup the arguments.
  // mov %v, r0
  // mov %v, r1
  reg::Machine_operand *const v0 = new reg::Machine_operand(
      reg::operand_type::VREG, std::to_string(asm_builder->get_available_id()));
  reg::Machine_operand *const v1 = new reg::Machine_operand(
      reg::operand_type::VREG, std::to_string(asm_builder->get_available_id()));

  {
    reg::Machine_instruction_mov *const mov1 = new reg::Machine_instruction_mov(
        cur_block, reg::mov_type::MOV_N, new reg::Machine_operand(*v0), r0);
    reg::Machine_instruction_mov *const mov2 = new reg::Machine_instruction_mov(
        cur_block, reg::mov_type::MOV_N, new reg::Machine_operand(*v1), r1);
    cur_block->add_instruction(mov1);
    cur_block->add_instruction(mov2);
  }

  {
    reg::Machine_instruction_mov *const mov1 = new reg::Machine_instruction_mov(
        cur_block, reg::mov_type::MOV_N, r0,
        operand_a);
    reg::Machine_instruction_mov *const mov2 = new reg::Machine_instruction_mov(
        cur_block, reg::mov_type::MOV_N, r1,
        operand_b);
    reg::Machine_operand *const func = new reg::Machine_operand(func_name);
    reg::Machine_instruction_branch *const call =
        new reg::Machine_instruction_branch(cur_block, reg::branch_type::BL,
                                            func);
    reg::Machine_instruction_mov *const ret = new reg::Machine_instruction_mov(
        cur_block, reg::mov_type::MOV_N, dst->emit_machine_operand(),
        r0);
    cur_block->add_instruction(mov1);
    cur_block->add_instruction(mov2);
    cur_block->add_instruction(call);
    cur_block->add_instruction(ret);
  }

  // Restore the operands.
  {
    reg::Machine_instruction_mov *const mov1 = new reg::Machine_instruction_mov(
        cur_block, reg::mov_type::MOV_N, new reg::Machine_operand(*r0),
        new reg::Machine_operand(*v0));
    reg::Machine_instruction_mov *const mov2 = new reg::Machine_instruction_mov(
        cur_block, reg::mov_type::MOV_N, new reg::Machine_operand(*r1),
        new reg::Machine_operand(*v1));
    cur_block->add_instruction(mov1);
    cur_block->add_instruction(mov2);
  }
}

// Global variables are like pointers in C language, they are represented by
// their unique addresses in the memory. Thus, to load global variables into
// their register, we should use ldr instruction. This can be done via macro
// definition: mov32: mov \reg16...
static compiler::reg::Machine_operand *handle_global(
    compiler::reg::Machine_block *const cur_block,
    compiler::reg::Assembly_builder *const asm_builder,
    compiler::ir::Operand *const raw_operand) {
  using namespace compiler;
  // CALL MOV32 + ldr.
  // mov32 r0, symbol
  // ldr r0, [r0]
  reg::Machine_operand *const tmp = new reg::Machine_operand(
      reg::operand_type::VREG,
      compiler::concatenate(reg::virtual_sign,
                            asm_builder->get_available_id()));
  reg::Machine_operand *const zero =
      new reg::Machine_operand(reg::operand_type::IMM, "0");
  reg::Machine_instruction_mov *const mov32 =
      new reg::Machine_instruction_mov(cur_block, reg::mov_type::MOV32, tmp,
                                       raw_operand->emit_machine_operand());
  reg::Machine_instruction_load *const ldr = new reg::Machine_instruction_load(
      cur_block, new reg::Machine_operand(*tmp), new reg::Machine_operand(*tmp),
      zero);
  cur_block->add_instruction(mov32);
  cur_block->add_instruction(ldr);

  return new reg::Machine_operand(*tmp);
}

static void handle_global_str(
    compiler::reg::Machine_block *const cur_block,
    compiler::reg::Assembly_builder *const asm_builder,
    compiler::reg::Machine_operand *const raw_operand,
    compiler::ir::Operand *const global_name) {
  using namespace compiler;
  // mov32 r0, symbol
  // str r1, [r0, #0]
  reg::Machine_operand *const tmp = new reg::Machine_operand(
      reg::operand_type::VREG,
      compiler::concatenate(reg::virtual_sign,
                            asm_builder->get_available_id()));
  reg::Machine_operand *const zero =
      new reg::Machine_operand(reg::operand_type::IMM, "0");
  reg::Machine_instruction_mov *const mov32 =
      new reg::Machine_instruction_mov(cur_block, reg::mov_type::MOV32, tmp,
                                       global_name->emit_machine_operand());
  reg::Machine_instruction_store *const str =
      new reg::Machine_instruction_store(cur_block, raw_operand,
                                         new reg::Machine_operand(*tmp), zero);
  cur_block->add_instruction(mov32);
  cur_block->add_instruction(str);
}

static compiler::reg::Machine_operand *handle_immediate(
    compiler::reg::Machine_block *const cur_block,
    compiler::reg::Assembly_builder *const asm_builder,
    compiler::ir::Operand *const raw_operand) {
  using namespace compiler;
  const std::string id =
      compiler::concatenate(reg::virtual_sign, asm_builder->get_available_id());
  // Insert an explicit MOV!
  reg::Machine_operand *const temp_virtual_reg =
      new reg::Machine_operand(reg::operand_type::VREG, id);
  reg::Machine_instruction *const m_inst_mov = new reg::Machine_instruction_mov(
      cur_block, reg::mov_type::MOV_N, temp_virtual_reg,
      raw_operand->emit_machine_operand());
  cur_block->add_instruction(m_inst_mov);

  // A new register.
  return new reg::Machine_operand(reg::operand_type::VREG, id);
}

// FIXME: Determine the size of the stack allocated by the function!
static void return_epilogue(compiler::reg::Machine_block *const cur_block,
                            const compiler::ir::IR *const ir) {
  using namespace compiler;
  reg::Machine_operand *const r14 =
      new reg::Machine_operand(reg::operand_type::REG, "r14");
  // reg::Machine_operand* const sp =
  //     new reg::Machine_operand(reg::operand_type::REG, reg::frame_pointer);
  // reg::Machine_operand* const offset =
  //     new reg::Machine_operand(reg::operand_type::IMM, "0");
  // reg::Machine_instruction_load* const ldr =
  //     new reg::Machine_instruction_load(cur_block, r14, sp, offset);
  // cur_block->add_instruction(ldr);

  // add sp, sp, #4
  // const std::string size =
  //     std::to_string(ir->get_func_call_list().size() * 4 + 4);
  // reg::Machine_operand* const stack_size =
  //     new reg::Machine_operand(reg::operand_type::IMM, size);
  // reg::Machine_instruction_binary* const add =
  //     new reg::Machine_instruction_binary(cur_block, reg::binary_type::ADD,
  //     sp,
  //                                         sp, stack_size);
  // cur_block->add_instruction(add);

  reg::Machine_operand *const sp =
      new reg::Machine_operand(reg::operand_type::REG, reg::stack_pointer);
  reg::Machine_operand *const fp =
      new reg::Machine_operand(reg::operand_type::REG, reg::frame_pointer);
  reg::Machine_instruction_stack *const stack_fp =
      new reg::Machine_instruction_stack(cur_block, reg::stack_type::POP, fp);
  reg::Machine_instruction_stack *const stack_r14 =
      new reg::Machine_instruction_stack(cur_block, reg::stack_type::POP, r14);
  reg::Machine_instruction_mov *const mov_fp =
      new reg::Machine_instruction_mov(cur_block, reg::mov_type::MOV_N, sp, fp);
  cur_block->add_instruction(mov_fp);
  cur_block->add_instruction(stack_fp);
  for (auto reg : compiler::reg::general_registers) {
    reg::Machine_instruction_stack *const stack_r =
        new reg::Machine_instruction_stack(
            cur_block, reg::stack_type::POP,
            new reg::Machine_operand(reg::operand_type::REG, reg));
    cur_block->add_instruction(stack_r);
  }
  cur_block->add_instruction(stack_r14);
  // mov pc, r14
  reg::Machine_operand *const pc =
      new reg::Machine_operand(reg::operand_type::REG, reg::program_counter);
  reg::Machine_instruction_mov *const mov = new reg::Machine_instruction_mov(
      cur_block, reg::mov_type::MOV_N, pc, r14);
  cur_block->add_instruction(mov);
}

static compiler::reg::branch_type to_branch_type(
    const compiler::ir::op_type &type) {
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

static compiler::reg::mov_type to_move_type(const compiler::ir::op_type &type) {
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
    const compiler::ir::op_type &type) {
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
    case compiler::ir::op_type::BOR: {
      return compiler::reg::binary_type::BOR;
    }
    case compiler::ir::op_type::BXOR: {
      return compiler::reg::binary_type::BXOR;
    }
    default:
      throw compiler::fatal_error("Error: Internal logic error.");
  }
}

compiler::Assembly_dispatcher *compiler::Assembly_dispatcher::dispatch(
    const compiler::ir::op_type &type, const ir::IR *const ir) {
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
    compiler::reg::Assembly_builder *const asm_builder) const {
  // Construct basic information.
  reg::Machine_block *const block = asm_builder->get_block();

  reg::Machine_operand *const dst = ir->get_dst()->emit_machine_operand();
  reg::Machine_operand *operand_a = nullptr;
  reg::Machine_operand *operand_b = nullptr;

  // Check if there is a movement from global variable to the register.
  if (ir->get_op1()->get_identifier().substr(0, 1) == ir::global_sign) {
    operand_a = handle_global(block, asm_builder, ir->get_op1());
  } else {
    operand_a = ir->get_op1()->emit_machine_operand();
  }

  if (ir->get_op2()->get_identifier().substr(0, 1) == ir::global_sign) {
    operand_b = handle_global(block, asm_builder, ir->get_op2());
  } else {
    operand_b = ir->get_op2()->emit_machine_operand();
  }

  // Before simply generating machine instructions, we shall first check whether
  // the first operand is IMMEDIATE:
  // ADD r0, #1,  => This is forbidden in ARM assembly.
  if (false == ir->get_op1()->get_is_var() &&
      ir->get_op1()->get_identifier().substr(0, 1) != ir::global_sign) {
    operand_a = handle_immediate(block, asm_builder, ir->get_op1());
  } else if (false == ir->get_op2()->get_is_var() &&
             ir->get_op2()->get_identifier().substr(0, 1) != ir::global_sign &&
             ir->get_op_type() == ir::op_type::IMUL) {
    // For multiplcation and division, the second operand cannot be immediate
    // either. So we need to transform it too.
    operand_b = handle_immediate(block, asm_builder, ir->get_op2());
  }

  // If this is a division.
  if (type == ir::op_type::IDIV) {
    handle_mod_div(block, asm_builder, ir->get_dst(), operand_a, operand_b,
                   reg::div_func);
    return;
  } else if (type == ir::op_type::IMOD) {
    handle_mod_div(block, asm_builder, ir->get_dst(), operand_a, operand_b,
                   reg::mod_func);
    return;
  }

  compiler::reg::binary_type type_bin = to_binary_type(type);
  reg::Machine_instruction_binary *const m_inst =
      new reg::Machine_instruction_binary(block, type_bin, dst, operand_a,
                                          operand_b);

  block->add_instruction(m_inst);
}

// FIXME: Maybe this is not needed?...
void compiler::Assembly_dispatcher_unary::emit_machine_code(
    compiler::reg::Assembly_builder *const asm_builder) const {
  // This is not needed, but I keep it there.
  return;
}

void compiler::Assembly_dispatcher_cmp::emit_machine_code(
    compiler::reg::Assembly_builder *const asm_builder) const {
  // Construct basic information.
  reg::Machine_block *const block = asm_builder->get_block();
  reg::Machine_operand *lhs = nullptr;
  reg::Machine_operand *rhs = nullptr;

  // Global type.
  if (ir->get_op1()->get_identifier().substr(0, 1).compare(ir::global_sign) ==
      0) {
    lhs = handle_global(block, asm_builder, ir->get_op1());
  } else {
    lhs = ir->get_op1()->emit_machine_operand();
  }

  if (ir->get_op2()->get_identifier().substr(0, 1).compare(ir::global_sign) ==
      0) {
    rhs = handle_global(block, asm_builder, ir->get_op2());
  } else {
    rhs = ir->get_op2()->emit_machine_operand();
  }

  // Before simply generating machine instructions, we shall first check whether
  // the first operand is IMMEDIATE:
  // ADD r0, #1,  => This is forbidden in ARM assembly.
  if (false == ir->get_op1()->get_is_var() &&
      ir->get_op1()->get_identifier().substr(0, 1) != ir::global_sign) {
    lhs = handle_immediate(block, asm_builder, ir->get_op1());
  } else if (false == ir->get_op2()->get_is_var() &&
             ir->get_op2()->get_identifier().substr(0, 1) != ir::global_sign) {
    // For multiplcation and division, the second operand cannot be immediate
    // either. So we need to transform it too.
    rhs = handle_immediate(block, asm_builder, ir->get_op2());
  }

  reg::Machine_instruction_cmp *const m_inst =
      new reg::Machine_instruction_cmp(block, lhs, rhs);
  block->add_instruction(m_inst);
}

void compiler::Assembly_dispatcher_branch::emit_machine_code(
    compiler::reg::Assembly_builder *const asm_builder) const {
  // Construct basic information.
  reg::Machine_block *const block = asm_builder->get_block();
  reg::Machine_operand *const label = new reg::Machine_operand(ir->get_label());

  reg::Machine_instruction_branch *const m_inst =
      new reg::Machine_instruction_branch(block, to_branch_type(type), label);
  block->add_instruction(m_inst);
}

void compiler::Assembly_dispatcher_mov::emit_machine_code(
    compiler::reg::Assembly_builder *const asm_builder) const {
  // Construct basic information.
  reg::Machine_block *const block = asm_builder->get_block();
  reg::Machine_operand *dst = nullptr;
  // Need further process.
  reg::Machine_operand *src = nullptr;

  // We cannot move an address to the register. We need the value.
  if (ir->get_op1()->get_identifier().substr(0, 1) == ir::global_sign) {
    src = handle_global(block, asm_builder, ir->get_op1());
  } else {
    src = ir->get_op1()->emit_machine_operand();
  }

  // If the destination is a global variable.
  bool dst_global =
      ir->get_dst()->get_identifier().substr(0, 1) == ir::global_sign;
  if (dst_global) {
    dst = handle_global(block, asm_builder, ir->get_dst());
  } else {
    dst = ir->get_dst()->emit_machine_operand();
  }

  assert(dst->is_reg() || dst->is_vreg() && "Cannot move to non-register!");

  reg::Machine_instruction_mov *const m_inst =
      new reg::Machine_instruction_mov(block, to_move_type(type), dst, src);
  block->add_instruction(m_inst);

  // Store the global variable.
  if (dst_global) {
    handle_global_str(block, asm_builder,
                      new compiler::reg::Machine_operand(*dst), ir->get_dst());
  }
}

void compiler::Assembly_dispatcher_stack::emit_machine_code(
    compiler::reg::Assembly_builder *const asm_builder) const {
  reg::Machine_block *const cur_block = asm_builder->get_block();
  // This should be the "push argument" statements.
  // PUSH 0, %t1    =>    mov r0, %1
  // Note that r0 should be protected, if r0 currently contains different data.
  //    This can be done when you allocate the registers.
  // Also note that the argument number can be rather big. In such cases, we
  //    store the arguments on the stack.
  if (type == ir::op_type::PUSH) {
    const uint32_t arg_no = std::stoul(ir->get_op1()->get_value());
    if (arg_no <= 3ul) {
      reg::Machine_operand *const reg = new reg::Machine_operand(
          reg::operand_type::REG,
          compiler::concatenate("r", ir->get_op1()->get_value()));
      reg::Machine_operand *const src = ir->get_op2()->emit_machine_operand();
      reg::Machine_instruction_mov *const m_inst =
          new reg::Machine_instruction_mov(cur_block, reg::mov_type::MOV_N, reg,
                                           src);
      cur_block->add_instruction(m_inst);
    } else {
      const std::string overflow = std::to_string((arg_no - 3) * 4);
      // In ARM-v7 assembly language, the arguments are stored in r0-r3.
      // If the argument number is too large, then we have to store the
      // overflown arguments on the stack. To this end, we calculate the offset
      // and then push them onto the stack.
      reg::Machine_operand *const sp =
          new reg::Machine_operand(reg::operand_type::REG, reg::stack_pointer);
      reg::Machine_operand *const offset =
          new reg::Machine_operand(reg::operand_type::IMM, overflow);
      reg::Machine_instruction_store *const store =
          new reg::Machine_instruction_store(
              cur_block, ir->get_op2()->emit_machine_operand(), sp, offset);
      cur_block->add_instruction(store);
      // How to retrieve these arguments from the stack?
    }
  } else {
    throw compiler::unimplemented_error("Error: Not yet implemented :(");
  }
}

void compiler::Assembly_dispatcher_alloca::emit_machine_code(
    compiler::reg::Assembly_builder *const asm_builder) const {
  return;
  // No need to emit anything.
}

void compiler::Assembly_dispatcher_call::emit_machine_code(
    compiler::reg::Assembly_builder *const asm_builder) const {
  // The arguments are already pushed onto the stack by the stack dispatcher.
  // We only need to generate a single BL instruction.
  reg::Machine_block *const cur_block = asm_builder->get_block();
  reg::Machine_operand *const func_name =
      new reg::Machine_operand(ir->get_label());
  reg::Machine_instruction_branch *const func_call =
      new reg::Machine_instruction_branch(cur_block, reg::branch_type::BL,
                                          func_name);

  cur_block->add_instruction(func_call);

  // Then we should add the return value...
  if (reg != nullptr) {
    reg::Machine_operand *const r0 =
        new reg::Machine_operand(reg::operand_type::REG, "r0");
    reg::Machine_operand *const dst = reg->emit_machine_operand();
    reg::Machine_instruction_mov *const mov = new reg::Machine_instruction_mov(
        cur_block, reg::mov_type::MOV_N, dst, r0);
    cur_block->add_instruction(mov);
  }
}

void compiler::Assembly_dispatcher_return::emit_machine_code(
    compiler::reg::Assembly_builder *const asm_builder) const {
  reg::Machine_block *const cur_block = asm_builder->get_block();
  // Handle return value. This should always be stored in r0.
  reg::Machine_operand *return_value = nullptr;
  if (ir->get_dst() != nullptr) {
    reg::Machine_operand *const r0 =
        new reg::Machine_operand(reg::operand_type::REG, "r0");

    if (ir->get_dst()->get_identifier().substr(0, 1) == ir::global_sign) {
      return_value = handle_global(cur_block, asm_builder, ir->get_dst());
    } else {
      return_value = ir->get_dst()->emit_machine_operand();
    }
    // std::cout << return_value->print() << std::endl;
    reg::Machine_instruction_mov *const ret = new reg::Machine_instruction_mov(
        cur_block, reg::mov_type::MOV_N, r0, return_value);
    cur_block->add_instruction(ret);
  }

  // The callee should restore the envionment.
  // ldr r14, [sp,#0]
  return_epilogue(cur_block, ir);
}