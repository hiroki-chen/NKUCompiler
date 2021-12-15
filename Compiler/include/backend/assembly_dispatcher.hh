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
#ifndef ASSEMBLY_DISPATCHER
#define ASSEMBLY_DISPATCHER
#include <ir/ir.hh>

namespace compiler {
/**
 * @brief This is the basic class for generating machine code for every
 *        instruction.
 *
 */
typedef class Assembly_dispatcher {
 protected:
  const ir::op_type type;

  const ir::IR* const ir;

 public:
  Assembly_dispatcher() = delete;

  Assembly_dispatcher(const ir::op_type& type, const ir::IR* const ir)
      : type(type), ir(ir) {}
  /**
   * @brief Get a dispatcher based on the operation type.
   *
   * @param type
   * @param ir
   * @return Assembly_dispatcher*
   */
  static Assembly_dispatcher* dispatch(const ir::op_type& type,
                                       const ir::IR* const ir);

  /**
   * @brief Generate the corresponding machine code for each instructions.
   *
   * @param asm_builder
   */
  virtual void emit_machine_code(
      reg::Assembly_builder* const asm_builder) const = 0;
} Assembly_dispatcher;

typedef class Assembly_dispatcher_binary final : public Assembly_dispatcher {
 public:
  Assembly_dispatcher_binary() = delete;

  Assembly_dispatcher_binary(const ir::op_type& type, const ir::IR* const ir)
      : Assembly_dispatcher(type, ir) {}

  virtual void emit_machine_code(
      reg::Assembly_builder* const asm_builder) const override;
} Assembly_dispatcher_binary;

typedef class Assembly_dispatcher_call final : public Assembly_dispatcher {
 protected:
  ir::Operand* reg;

 public:
  Assembly_dispatcher_call() = delete;

  Assembly_dispatcher_call(const ir::op_type& type, const ir::IR* const ir)
      : Assembly_dispatcher(type, ir) {}

  virtual void emit_machine_code(
      reg::Assembly_builder* const asm_builder) const override;

  virtual void set_return_virtual_reg(ir::Operand* const reg) {
    this->reg = reg;
  };
} Assembly_dispatcher_call;

typedef class Assembly_dispatcher_stack final : public Assembly_dispatcher {
 public:
  Assembly_dispatcher_stack() = delete;

  Assembly_dispatcher_stack(const ir::op_type& type, const ir::IR* const ir)
      : Assembly_dispatcher(type, ir) {}

  virtual void emit_machine_code(
      reg::Assembly_builder* const asm_builder) const override;
} Assembly_dispatcher_stack;

typedef class Assembly_dispatcher_cmp final : public Assembly_dispatcher {
 public:
  Assembly_dispatcher_cmp() = delete;

  Assembly_dispatcher_cmp(const ir::op_type& type, const ir::IR* const ir)
      : Assembly_dispatcher(type, ir) {}

  virtual void emit_machine_code(
      reg::Assembly_builder* const asm_builder) const override;
} Assembly_dispatcher_cmp;

typedef class Assembly_dispatcher_mov final : public Assembly_dispatcher {
 public:
  Assembly_dispatcher_mov() = delete;

  Assembly_dispatcher_mov(const ir::op_type& type, const ir::IR* const ir)
      : Assembly_dispatcher(type, ir) {}

  virtual void emit_machine_code(
      reg::Assembly_builder* const asm_builder) const override;
} Assembly_dispatcher_mov;

typedef class Assembly_dispatcher_unary final : public Assembly_dispatcher {
 public:
  Assembly_dispatcher_unary() = delete;

  Assembly_dispatcher_unary(const ir::op_type& type, const ir::IR* const ir)
      : Assembly_dispatcher(type, ir) {}

  virtual void emit_machine_code(
      reg::Assembly_builder* const asm_builder) const override;
} Assembly_dispatcher_unary;

typedef class Assembly_dispatcher_return final : public Assembly_dispatcher {
 public:
  Assembly_dispatcher_return() = delete;

  Assembly_dispatcher_return(const ir::op_type& type, const ir::IR* const ir)
      : Assembly_dispatcher(type, ir) {}

  virtual void emit_machine_code(
      reg::Assembly_builder* const asm_builder) const override;
} Assembly_dispatcher_return;

typedef class Assembly_dispatcher_branch final : public Assembly_dispatcher {
 public:
  Assembly_dispatcher_branch() = delete;

  Assembly_dispatcher_branch(const ir::op_type& type, const ir::IR* const ir)
      : Assembly_dispatcher(type, ir) {}

  virtual void emit_machine_code(
      reg::Assembly_builder* const asm_builder) const override;
} Assembly_dispatcher_branch;

typedef class Assembly_dispatcher_alloca final : public Assembly_dispatcher {
 public:
  Assembly_dispatcher_alloca() = delete;

  Assembly_dispatcher_alloca(const ir::op_type& type, const ir::IR* const ir)
      : Assembly_dispatcher(type, ir) {}

  virtual void emit_machine_code(
      reg::Assembly_builder* const asm_builder) const override;
} Assembly_dispatcher_alloca;
}  // namespace compiler

#endif