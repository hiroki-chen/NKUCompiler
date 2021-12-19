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
#ifndef UNITS_HH
#define UNITS_HH

#include <backend/assembly.hh>
#include <iostream>
#include <ir/cfg.hh>
#include <set>
#include <string>
#include <vector>

namespace compiler::reg {
// Forward declarations.
class Machine_operand;
class Machine_instruction;
class Machine_unit;
class Machine_function;
class Machine_block;
// class Machine_instruction;

struct Comparator {
  bool operator()(const Machine_operand* lhs, const Machine_operand* rhs) const;
};

typedef class Machine_block {
 private:
  Machine_function* parent;

  std::string label;

  std::vector<Machine_block*> pred, succ;

  std::vector<Machine_instruction*> inst_list;

  std::set<Machine_operand*, Comparator> live_in;

  std::set<Machine_operand*, Comparator> live_out;

 public:
  std::vector<Machine_instruction*>* get_instruction_list() {
    return &inst_list;
  }

  std::vector<Machine_instruction*>::iterator begin() {
    return inst_list.begin();
  }

  std::vector<Machine_instruction*>::iterator end() { return inst_list.end(); }

  Machine_block() = delete;

  Machine_block(Machine_function* const parent, const std::string& label)
      : parent(parent), label(label) {}

  void add_instruction(Machine_instruction* const instruction) {
    inst_list.emplace_back(instruction);
  }

  void add_pred(Machine_block* const p) { pred.emplace_back(p); }

  void add_succ(Machine_block* const s) { succ.emplace_back(s); }

  std::set<Machine_operand*, Comparator>* get_live_in() { return &live_in; }

  std::set<Machine_operand*, Comparator>* get_live_out() { return &live_out; }

  std::vector<Machine_block*>* get_preds() { return &pred; }

  std::vector<Machine_block*>* get_succs() { return &succ; }

  void emit_assembly(std::ostream& os = std::cerr) const;

  std::string get_label() const { return label; }

  Machine_function* get_parent() { return parent; }
} Machine_block;

typedef class Machine_function {
 private:
  Machine_unit* parent;

  std::vector<Machine_block*> block_list;

  uint32_t stack_size;

  /**
   * @brief This vector saves the registers of the previous function.
   *
   */
  std::set<std::string> saved_regs;

  std::string function_name;

  /**
   * @brief This stores the instructions for preparation of a function frame.
   *
   */
  std::vector<Machine_instruction*> func_prologue;

 public:
  Machine_function() = delete;

  Machine_function(Machine_unit* const parent, const std::string function_name)
      : parent(parent), function_name(function_name), stack_size(0ul) {}

  std::vector<Machine_block*>* get_blocks() { return &block_list; }

  std::vector<Machine_block*>::iterator begin() { return block_list.begin(); }

  std::vector<Machine_block*>::iterator end() { return block_list.end(); }

  uint32_t allocate_stack(const uint32_t& size) { return (stack_size += size); }

  void add_block(Machine_block* const block) { block_list.emplace_back(block); }

  void add_func_prologue_instruction(Machine_instruction* const instruction) {
    func_prologue.emplace_back(instruction);
  }

  // What is this used for?
  void add_saved_regs(const std::string& register_name) {
    saved_regs.insert(register_name);
  }

  void backup_registers(void);
  std::string get_func_name() const { return function_name; }

  void emit_assembly(std::ostream& os = std::cerr) const;
} Machine_function;

typedef class Machine_unit {
 private:
  std::vector<Machine_function*> func_list;

  compiler::ir::CFG_block* const global_defs;

  void emit_global(std::ostream& os = std::cerr) const;

 public:
  Machine_unit() = delete;

  Machine_unit(compiler::ir::CFG_block* const global_defs)
      : global_defs(global_defs) {}

  std::vector<Machine_function*>* get_function_list() { return &func_list; }

  std::vector<Machine_function*>::iterator begin() { return func_list.begin(); }

  std::vector<Machine_function*>::iterator end() { return func_list.end(); }

  void add_function(Machine_function* const func) {
    func_list.emplace_back(func);
  }

  void emit_assembly(std::ostream& os = std::cerr) const;
} Machine_unit;
}  // namespace compiler::reg

#endif