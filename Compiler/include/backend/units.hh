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
#include <set>
#include <vector>

namespace compiler::reg {
// Forward declarations.
class Machine_operand;
class Machine_instruction;
class Machine_unit;
class Machine_function;
class Machine_block;
class Machine_instruction;

typedef class Machine_block {
 private:
  Machine_function* parent;

  uint32_t no;

  std::vector<Machine_block*> pred, succ;

  std::vector<Machine_instruction*> inst_list;

  std::set<Machine_operand*> live_in;

  std::set<Machine_operand*> live_out;

 public:
  std::vector<Machine_instruction*>* get_instruction_list() {
    return &inst_list;
  }

  std::vector<Machine_instruction*>::iterator begin() {
    return inst_list.begin();
  }

  std::vector<Machine_instruction*>::iterator end() { return inst_list.end(); }

  Machine_block() = delete;

  Machine_block(Machine_function* const parent, const uint32_t& no)
      : parent(parent), no(no) {}

  void add_instruction(Machine_instruction* const instruction) {
    inst_list.emplace_back(instruction);
  }

  void add_pred(Machine_block* const p) { pred.emplace_back(p); }

  void add_succ(Machine_block* const s) { succ.emplace_back(s); }

  std::set<Machine_operand*>* get_live_in() { return &live_in; }

  std::set<Machine_operand*>* get_live_out() { return &live_out; }

  std::vector<Machine_block*>* get_preds() { return &pred; }

  std::vector<Machine_block*>* get_succs() { return &succ; }

  void emit_assembly(std::ostream& os = std::cerr) const;
} Machine_block;

typedef class Machine_function {
 private:
  Machine_unit* parent;

  std::vector<Machine_block*> block_list;

  uint32_t stack_size;

  std::set<std::string> saved_regs;

  std::string function_name;

 public:
  Machine_function() = delete;

  Machine_function(Machine_unit* const parent, const std::string function_name)
      : parent(parent), function_name(function_name), stack_size(0ul) {}

  std::vector<Machine_block*>* get_blocks() { return &block_list; }

  std::vector<Machine_block*>::iterator begin() { return block_list.begin(); }

  std::vector<Machine_block*>::iterator end() { return block_list.end(); }

  uint32_t allocate_stack(const uint32_t& size) { return (stack_size += size); }

  void add_block(Machine_block* const block) {
    block_list.emplace_back(block);
  }
  void add_saved_regs(const std::string& register_name) {
    saved_regs.insert(register_name);
  }

  void emit_assembly(std::ostream& os = std::cerr) const;
} Machine_function;

typedef class Machine_unit {
 private:
  std::vector<Machine_function*> func_list;

  void emit_global(std::ostream& os = std::cerr) const;

 public:
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