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
 public:
  Assembly_dispatcher() = default;
  /**
   * @brief Get a dispatcher based on the operation type.
   *
   * @param type
   * @return Assembly_dispatcher*
   */
  static Assembly_dispatcher* dispatch(const ir::op_type& type);

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
  Assembly_dispatcher_binary() = default;

  virtual void emit_machine_code(
      reg::Assembly_builder* const asm_builder) const override;
} Assembly_dispatcher_binary;

typedef class Assembly_dispatcher_stack final : public Assembly_dispatcher {
 public:
  Assembly_dispatcher_stack() = default;

  virtual void emit_machine_code(
      reg::Assembly_builder* const asm_builder) const override;
} Assembly_dispatcher_stack;

typedef class Assembly_dispatcher_cmp final : public Assembly_dispatcher {
 public:
  Assembly_dispatcher_cmp() = default;

  virtual void emit_machine_code(
      reg::Assembly_builder* const asm_builder) const override;
} Assembly_dispatcher_cmp;

typedef class Assembly_dispatcher_mov final : public Assembly_dispatcher {
 public:
  Assembly_dispatcher_mov() = default;

  virtual void emit_machine_code(
      reg::Assembly_builder* const asm_builder) const override;
} Assembly_dispatcher_mov;

typedef class Assembly_dispatcher_unary final : public Assembly_dispatcher {
 public:
  Assembly_dispatcher_unary() = default;

  virtual void emit_machine_code(
      reg::Assembly_builder* const asm_builder) const override;
} Assembly_dispatcher_unary;

typedef class Assembly_dispatcher_branch final : public Assembly_dispatcher {
 public:
  Assembly_dispatcher_branch() = default;

  virtual void emit_machine_code(
      reg::Assembly_builder* const asm_builder) const override;
} Assembly_dispatcher_branch;

typedef class Assembly_dispatcher_alloca final : public Assembly_dispatcher {
 public:
  Assembly_dispatcher_alloca() = default;

  virtual void emit_machine_code(
      reg::Assembly_builder* const asm_builder) const override;
} Assembly_dispatcher_alloca;
}  // namespace compiler

#endif