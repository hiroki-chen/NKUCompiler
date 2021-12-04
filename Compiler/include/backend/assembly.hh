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
#ifndef ASSEMBLY_HH
#define ASSEMBLY_HH

#include <backend/units.hh>
#include <iostream>
#include <ir/cfg.hh>
#include <string>
#include <vector>

namespace compiler::reg {
// Forward declarations.
class Machine_block;
class Machine_operand;
/**
 * @brief This is a auto-generated ARM-v7 assebmly template for every output
 *        file.
 *
 */
static const std::string assembly_template =
    ".macro mov32, reg, val\n"
    " \tmovw \\reg, #:lower16:\\val\n"
    " \tmovt \\reg, #:upper16:\\val\n"
    ".endm\n"
    ".macro cpu_id, rd\n"
    " \tmrc	p15, 0, \\rd, c0, c0, 5\n"
    " \tand	\\rd, \\rd, #0xF\n"
    ".endm\n"
    ".text\n"
    ".syntax unified\n"
    ".cpu    arm7tdmi\n";

typedef enum inst_type {
  BINARY,
  LOAD,
  STORE,
  MOV,
  BRANCH,
  CMP,
  STACK,
  UNARY,
  ALLOCA,
  RET,
  CALL,
} inst_type;

typedef enum branch_type {
  B,
  BL,
  BX,
  BEQ,
  BNE,
  BLT,
  BGT,
  BLE,
  BGE
} branch_type;

typedef enum cond_type { EQ, NE, LT, LE, GT, GE, NONE } cond_type;

typedef enum binary_type {
  ADD,
  SUB,
  MUL,
  DIV,
  MOD,
  LAND,
  LOR,
  BXOR,
  BAND,
  BOR,
  INVALID,
} binary_type;

typedef enum operand_type { IMM, VREG, REG, LABEL } operand_type;

typedef enum stack_type { PUSH, POP } stack_type;

typedef enum mov_type {  // MOV CONDITIONAL.
  MOVNE,
  MOVEQ,
  MOVGT,
  MOVLT,
  MOVGE,
  MOVLE,
  MOV_N,  // normal
} mov_type;

/**
 * @brief ARM-v7 registers that are callee-saved. They can be regarded as the
 *        general-purposed registers in x86 assembly.
 *
 */
static const std::string general_registers[8] = {"r4", "r5", "r6",  "r7",
                                                 "r8", "r9", "r10", "r11"};

static const std::string program_counter = "pc";

static const std::string stack_pointer = "sp";

/**
 * @brief ARM-v7 Registers that are NOT callee-saved. I.e., they are used when a
 *        procedure is called.
 *
 */
static const std::string argument_registers[4] = {"r0", "r1", "r2", "r3"};

static const std::string virtual_sign = "%v";

/**
 * @brief Basic class for machine instructions.
 *
 * @note  THIS IS AN ABSTRACT CLASS. NEVER CREATE AN INSTANCE FROM IT.
 *
 */
typedef class Machine_instruction {
 protected:
  Machine_block* parent;  // To which it belongs.

  uint32_t no;  // Instruction location

  inst_type type;  // Instruction type

  cond_type cond = cond_type::NONE;  // Instruction condition

  // Instruction operand list sorted by the appearance of the operands.
  std::vector<Machine_operand*> def_list;
  // Use list.
  std::vector<Machine_operand*> use_list;

  void add_def(Machine_operand* operand) {
    this->def_list.emplace_back(operand);
  }

  void add_use(Machine_operand* operand) {
    this->use_list.emplace_back(operand);
  }

#ifdef COMPILER_DEBUG
  // For debugging.
  void print_cond();
#endif

 public:
  Machine_instruction() = default;
  /**
   * @brief A pure virtual interface that should be implemented in each
   * 				inherited sub-classes. This function is used to
   *generate assembly code.
   *
   * @param os
   */
  virtual void emit_assembly(std::ostream& os = std::cerr) const = 0;

  virtual void set_no(const uint32_t& no) { this->no = no; }

  virtual uint32_t get_no(void) const { return no; }

  std::vector<Machine_operand*> get_use(void) const { return use_list; }

  std::vector<Machine_operand*> get_def(void) const { return def_list; }
} Machine_instruction;

/**
 * @brief Class for binary machine instructions.
 *
 */
typedef class Machine_instruction_binary final : public Machine_instruction {
 protected:
  binary_type op;

 public:
  Machine_instruction_binary(Machine_block* const parent, const binary_type& op,
                             Machine_operand* const dst,
                             Machine_operand* const operand_a,
                             Machine_operand* const operand_b,
                             const cond_type& cond = cond_type::NONE);

  virtual void emit_assembly(std::ostream& os = std::cerr) const override;
} Machine_instruction_binary;

typedef class Machine_instruction_branch final : public Machine_instruction {
 protected:
  branch_type op;

 public:
  Machine_instruction_branch(Machine_block* const parent, const branch_type& op,
                             Machine_operand* const label,
                             const cond_type& cond = cond_type::NONE);

  virtual void emit_assembly(std::ostream& os = std::cerr) const override;
} Machine_instruction_branch;

typedef class Machine_instruction_load final : public Machine_instruction {
 public:
  Machine_instruction_load(Machine_block* const parent,
                           Machine_operand* const dst,
                           Machine_operand* const operand_a,
                           Machine_operand* const operand_b = nullptr,
                           const cond_type& cond = cond_type::NONE);

  virtual void emit_assembly(std::ostream& os = std::cerr) const override;
} Machine_instruction_load;

typedef class Machine_instruction_store final : public Machine_instruction {
 public:
  Machine_instruction_store(Machine_block* const parent,
                            Machine_operand* const operand_a,
                            Machine_operand* const operand_b,
                            Machine_operand* const operand_c = nullptr,
                            const cond_type& cond = cond_type::NONE);

  virtual void emit_assembly(std::ostream& os = std::cerr) const override;
} Machine_instruction_store;

typedef class Machine_instruction_mov final : public Machine_instruction {
 protected:
  mov_type op;

 public:
  Machine_instruction_mov(Machine_block* const parent, const mov_type& op,
                          Machine_operand* const dst,
                          Machine_operand* const src,
                          const cond_type& cond = cond_type::NONE);

  virtual void emit_assembly(std::ostream& os = std::cerr) const override;
} Machine_instruction_mov;

typedef class Machine_instruction_cmp final : public Machine_instruction {
 public:
  Machine_instruction_cmp(Machine_block* const parent,
                          Machine_operand* const operand_a,
                          Machine_operand* const operand_b,
                          const cond_type& cond = cond_type::NONE);

  virtual void emit_assembly(std::ostream& os = std::cerr) const override;
} Machine_instruction_cmp;

typedef class Machine_instruction_stack final : public Machine_instruction {
 protected:
  stack_type op;

 public:
  Machine_instruction_stack(Machine_block* const parent, const stack_type& op,
                            Machine_operand* const src,
                            const cond_type& cond = cond_type::NONE);

  virtual void emit_assembly(std::ostream& os = std::cerr) const override;
} Machine_instruction_stack;

typedef class Machine_operand {
 private:
  Machine_instruction* parent;

  operand_type type;

  std::string val;  // The value of immediate number

  std::string register_name;  // The name of the allocated register.

  std::string label;  // The label of the address.

 public:
  Machine_operand(const operand_type& type, const std::string& val);

  Machine_operand(const std::string& label);

  bool operator==(const Machine_operand& rhs) const;

  bool operator<(const Machine_operand& rhs) const;

  bool is_imm() { return type == IMM; };

  bool is_reg() { return type == REG; };

  bool is_vreg() { return type == VREG; };

  bool is_label() { return type == LABEL; };

  std::string get_value(void) const { return val; };

  std::string get_register_name(void) const { return register_name; };

  std::string print(void) const;

  void set_register_name(const std::string& register_name);

  void set_parent(Machine_instruction* const parent) { this->parent = parent; };

  std::string get_label() { return label; };

  Machine_instruction* get_parent(void) const { return parent; };

} Machine_operand;
}  // namespace compiler::reg

#endif