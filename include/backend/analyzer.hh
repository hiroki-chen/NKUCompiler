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
#include <memory>
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

  // For the stack frame analysis.
  uint32_t stack_size;

  // The current stack pointer.
  uint32_t cur_sp;

  // The number of overflown arguments.
  uint32_t overflown_arg;

  // A map that stores the base offset of each array.
  std::map<Machine_function*, std::map<std::string, uint32_t>> array_base;

  // A vector that temporarily stores the overflown args.
  std::vector<Machine_instruction*> overflown_args;

 public:
  Assembly_builder()
      : id(0ul), stack_size(0ul), cur_sp(0ul), overflown_arg(0ul) {}

  void add_overflown_arg(Machine_instruction* const inst) {
    overflown_args.emplace_back(inst);
  }

  void clear_overflown_args(void) { overflown_args.clear(); }

  void increment_overflown_arg(void) { overflown_arg++; }

  void reset_overflown_arg(void) { overflown_arg = 0ul; }

  void set_unit(Machine_unit* const unit) { machine_unit = unit; }

  void set_function(Machine_function* const func) {
    machine_function = func;
    cur_sp = 0ul;
  }

  void set_block(Machine_block* const block) { machine_block = block; }

  void set_compare_code(const cond_type& opcode) { compare_code = opcode; }

  void set_array_base(const std::string& array_name,
                      const uint32_t& array_size);

  void set_stack_size_cur(const uint32_t& stack_size) {
    this->stack_size = stack_size;
  }

  Machine_unit* get_unit() { return machine_unit; }

  Machine_function* get_function() { return machine_function; }

  Machine_block* get_block() { return machine_block; }

  std::vector<Machine_instruction*> get_overflown_args(void) {
    return overflown_args;
  }

  cond_type get_compare_code() { return compare_code; }

  uint32_t get_available_id(void) { return id++; }

  uint32_t get_stack_size(void) { return stack_size; }

  uint32_t get_overflown_arg(void) { return overflown_arg; }

  uint32_t get_array_base(void) { return cur_sp; }

  uint32_t get_array_base(const std::string& name) {
    return array_base[machine_function][name];
  }
} Assembly_builder;

/**
 * @brief This class defines pool for active registers.
 *
 */
typedef class Analyzer {
 private:
  std::unique_ptr<Assembly_builder> asm_builder;

  const std::map<std::string, std::vector<compiler::ir::CFG_block*>> cfg_blocks;

  compiler::ir::CFG_block* const global_defs;

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

  /**
   * @brief This function will prune unnecessary instructions.
   * 
   * @param unit 
   */
  void assembly_epilogue(Machine_unit* const unit);

  void assembly_epilogue(Machine_function* const func);

 public:
  Analyzer() = delete;

  Analyzer(const std::map<std::string, std::vector<compiler::ir::CFG_block*>>&
               cfg_blocks,
           compiler::ir::CFG_block* const global_defs);

  void generate_code(std::ostream& os = std::cerr);

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
} Analyzer;

/**
 * @brief A class that analyzes the live variable, which is used to analyze
 * the live interval so that we can alloacte registers to virtual ones.
 *
 * @author xjw
 *
 * TODO: This is for xjw.
 *
 */
typedef class Live_variable_analyzer final {
 private:
  // For def-use chain.
  // std::map<Machine_operand, std::set<Machine_operand*, Comparator>> all_uses;
  std::map<std::string, std::set<Machine_operand*, Comparator>> all_uses;
  std::map<Machine_block*, std::set<Machine_operand*, Comparator>> def, use;

  // ================ Functions ================//
  void compute_def_use(Machine_function* const func);

  void iterate(Machine_function* const func);

  void compute_use_pos(Machine_function* const func);

 public:
  void pass(Machine_unit* const unit);

  void pass(Machine_function* const func);

  // std::map<Machine_operand, std::set<Machine_operand*, Comparator>>*
  // get_all_uses(void) {
  //   return &all_uses;
  // }
  std::map<std::string, std::set<Machine_operand*, Comparator>>* get_all_uses(
      void) {
    return &all_uses;
  }
  // Add your definitions and implementations here.
} Live_variable_analyzer;
}  // namespace compiler::reg

#endif