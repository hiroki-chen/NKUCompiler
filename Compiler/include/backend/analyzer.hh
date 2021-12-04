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
#ifndef ANALYZER_HH
#define ANALYZER_HH

#include <backend/assembly.hh>
#include <backend/units.hh>
#include <iostream>
#include <ir/cfg.hh>
#include <map>
#include <unordered_map>

namespace compiler::ir {
class CFG_block;
}  // namespace compiler::ir

// For ARM-v7 32-bit backend.

/**
 * @brief This class implements register allocation algorithms (linear-scan
 * alogrithm).
 * @ref   Poletto, Massimiliano, and Vivek Sarkar. "Linear scan register
 *        allocation." ACM Transactions on Programming Languages and Systems
 *       (TOPLAS) 21.5 (1999): 895-913.
 *
 * @author chb
 * So my thought is to generate machine code from cfg_blocks via the following
 * steps:
 * 1. Analyze each block and generate machine_instruction for each one.
 * 2. Generate the class Machine_block for each CFG_block and append this list
 * to the block.
 * 3. Generate the class Machine_function for each function.
 *
 * So there must be multiple intermediate output.
 *
 */
namespace compiler::reg {
// TODO: Add a class for LiveRange or LiveInternal which defines the "DEF-USE"
// CHAIN.
// TODO: Perform analysis over the CFG for each function.
/**
 * @brief A helper class that constructs the assemblt code for the CFG_block.
 *
 * @author YoungCoder et al.
 * @ref
 * https://github.com/Emanual20/2021NKUCS-Compilers-Lab/blob/lab7/include/AsmBuilder.h
 *
 */
typedef class Assembly_builder {
 private:
  // Variables...
  Machine_unit* machine_unit;          // Machine machine_unit
  Machine_function* machine_function;  // current machine code function
  Machine_block* machine_block;        // current machine code block
  cond_type compare_code;  // CmpInstruction opcode, for CondInstruction

  // Available id for virtual registers.
  // Note that this variable is used ONLY when we need temporary registers.
  // E.g.: ADD %t0, #1, #2 => MOV v0, #1     ADD %t0, v0, #2.
  // For our convenience, this variable keeps to grow until the compilation
  // ends.
  uint32_t id;

 public:
  Assembly_builder() : id(0) {}

  void set_unit(Machine_unit* const unit) { machine_unit = unit; }

  void set_function(Machine_function* const func) { machine_function = func; }

  void set_block(Machine_block* const block) { machine_block = block; }

  void set_compare_code(const cond_type& opcode) { compare_code = opcode; }

  Machine_unit* get_unit() { return machine_unit; }

  Machine_function* get_function() { return machine_function; }

  Machine_block* get_block() { return machine_block; }

  cond_type get_compare_code() { return compare_code; }

  uint32_t get_available_id(void) { return id++; }
} Assembly_builder;
/**
 * @brief This class defines pool for active registers.
 *
 */
typedef class Analyzer {
 private:
  Assembly_builder* asm_builder;

  /**
   * @brief A hash map that stores the availability of each registers of ARM.
   *
   */
  std::unordered_map<std::string, bool> register_free_map;

  /**
   * @brief A hash that stores the the mapping of virtual registers.
   *
   */
  std::unordered_map<std::string, std::string> virtual_to_physical;

  /**
   * @brief The inverse of compiler::reg::Allocator::virtual_to_physical.
   *
   */
  std::unordered_map<std::string, std::string> physical_to_virtual;

  /**
   * @brief Due to insufficient number of registers or some other reasons, some
   *        variables are stored on the stack. In order to retrieve them
   *        correctly, we need to know the offset.
   *
   * @note  If a virtual register is not bound to any registers, please refer to
   * this map.
   *
   */
  std::unordered_map<std::string, uint32_t> stack_offset;

  /**
   * @brief Records the number of free registers. If there is no free registers
   * anymore, we should spill virtual registers onto the stack.
   *
   */
  uint32_t free_registers;

  const std::map<std::string, std::vector<compiler::ir::CFG_block*>> cfg_blocks;

  //================= Functions====================
  void reserve_for_function_call(void);

  /**
   * @brief This function will transform a function (which is a group of basic
   *        blocks) into a machine function.
   *
   * @param func
   * @param func_name
   * @param parent
   */
  void generate(const std::vector<compiler::ir::CFG_block*>& function,
                const std::string& func_name);

  void generate(compiler::ir::CFG_block* const block);

 public:
  Analyzer() = delete;

  Analyzer(const std::map<std::string, std::vector<compiler::ir::CFG_block*>>&
               cfg_blocks);

  void generate_code(std::ostream& os = std::cerr);

  bool is_on_stack(const std::string& name) {
    return virtual_to_physical.count(name) == 0 &&
           stack_offset.count(name) != 0;
  }

 protected:
  /**
   * @brief Get a free register from the register pool.
   *
   * @return std::string
   */
  std::string get_free_register(void);

  /**
   * @brief Set an occupied register to be free.
   *
   * @param reg_name
   */
  void set_free_register(const std::string& reg_name);

  uint32_t free_num(void) { return free_registers; }

} Analyzer;
}  // namespace compiler::reg

#endif