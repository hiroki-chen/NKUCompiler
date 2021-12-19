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
#include <algorithm>

#include <backend/allocator.hh>
#include <backend/analyzer.hh>
#include <backend/assembly.hh>
#include <common/utils.hh>
#include <map>

static bool check_dummy_move(
    compiler::reg::Machine_instruction* const instruction) {
  if (instruction->get_type() != compiler::reg::inst_type::MOV) {
    return false;
  }

  // Move a register into itself is useless.
  if (instruction->get_use()->front()->print() ==
      instruction->get_def()->front()->print()) {
    return true;
  }

  return false;
}

static bool check_dummy_binary(
    compiler::reg::Machine_instruction* const instruction) {
  if (instruction->get_type() != compiler::reg::inst_type::BINARY) {
    return false;
  }

  compiler::reg::Machine_instruction_binary* const binary =
      static_cast<compiler::reg::Machine_instruction_binary* const>(
          instruction);
  // ADD or SUB zero is useless.
  if ((binary->get_binary_type() == compiler::reg::binary_type::ADD ||
       binary->get_binary_type() == compiler::reg::binary_type::SUB) &&
      binary->get_use()->back()->print() == "#0") {
    return true;
  }

  return false;
}

compiler::reg::Analyzer::Analyzer(
    const std::map<std::string, std::vector<compiler::ir::CFG_block*>>&
        cfg_blocks,
    compiler::ir::CFG_block* const global_defs)
    : cfg_blocks(cfg_blocks), global_defs(global_defs) {
  // Create an empty Assembly_builder class for future usage :)
  asm_builder = std::make_unique<Assembly_builder>();
}

void compiler::reg::Analyzer::assembly_epilogue(
    compiler::reg::Machine_unit* const unit) {
  for (auto func : *unit->get_function_list()) {
    assembly_epilogue(func);
  }
}

void compiler::reg::Analyzer::assembly_epilogue(
    compiler::reg::Machine_function* const func) {
  for (auto blocks : *func->get_blocks()) {
    std::vector<reg::Machine_instruction*>* instructions =
        blocks->get_instruction_list();

    for (auto iter = instructions->begin(); iter != instructions->end();) {
      // Do some check.
      if (check_dummy_move(*iter) || check_dummy_binary(*iter)) {
        iter = instructions->erase(iter);
      } else {
        iter++;
      }
    }
  }
}

void compiler::reg::Analyzer::generate_code(std::ostream& os) {
  // This function will analyze the control flow graph of each function
  // and then allocate the physical registers to each virtual registers.
  // Create an empty machine unit type.
  compiler::reg::Machine_unit* const machine_unit =
      new compiler::reg::Machine_unit(global_defs);
  asm_builder->set_unit(machine_unit);

  // Traverse each function.
  for (auto func : cfg_blocks) {
    // First we will need to analyze the live variable, i.e., the so-called
    // "def-use" chain.
    // compiler::reg::compute_def_use(func.second);
    generate(func.second, func.first);
    // Append to the function list of the machine unit.
    compiler::reg::Machine_function* const machine_function =
        asm_builder->get_function();
    machine_unit->add_function(machine_function);
  }

  // You need to either implement the graph-colorin / linear-scan algorithm.
  // Use the class "Allocator" to do this job. If you need to add / modify /
  // delete some data structures, feel free to do it.
  const std::unique_ptr<compiler::reg::Allocator> allocator =
      std::make_unique<compiler::reg::Allocator>(machine_unit);

  try {
    allocator->do_linear_scan();
  } catch (const compiler::fatal_error& e) {
    std::cerr << "Error detected, dumping raw: " << std::endl;
    machine_unit->emit_assembly(std::cerr << '\n');

    throw e;
  }

  // Prune needless instructions.
  // assembly_epilogue(machine_unit);
  // Finally, we emit the assembly from machine unit.
  machine_unit->emit_assembly(os);
}

void compiler::reg::Analyzer::generate(
    const std::vector<compiler::ir::CFG_block*>& function,
    const std::string& func_name) {
  compiler::reg::Machine_unit* const unit_cur = asm_builder->get_unit();
  compiler::reg::Machine_function* const func_cur =
      new compiler::reg::Machine_function(unit_cur, func_name);

  asm_builder->set_function(func_cur);

  std::map<compiler::ir::CFG_block*, compiler::reg::Machine_block*>
      cfg_to_machine;

  for (compiler::ir::CFG_block* const block : function) {
    // Handle one block.
    // The new block will be stored in asm_builder. :)
    generate(block);
    cfg_to_machine[block] = asm_builder->get_block();
  }

  // Add preds and succs.
  for (compiler::ir::CFG_block* const block : function) {
    // Handle one block.
    compiler::reg::Machine_block* const machine_block = cfg_to_machine[block];

    const std::vector<compiler::ir::CFG_block*> preds = block->get_preds();
    const std::vector<compiler::ir::CFG_block*> succs = block->get_succs();
    for (auto pred = preds.begin(); pred != preds.end(); pred++) {
      machine_block->add_pred(cfg_to_machine[*pred]);
    }
    for (auto succ = succs.begin(); succ != succs.end(); succ++) {
      machine_block->add_succ(cfg_to_machine[*succ]);
    }
  }
}

void compiler::reg::Analyzer::generate(compiler::ir::CFG_block* const block) {
  compiler::reg::Machine_function* const cur_func = asm_builder->get_function();
  compiler::reg::Machine_block* const cur_block =
      new compiler::reg::Machine_block(cur_func, block->get_name());
  asm_builder->set_block(cur_block);

  for (compiler::ir::IR ir : *block->get_ir_list()) {
    ir.emit_machine_code(asm_builder.get());
  }

  cur_func->add_block(cur_block);
}

void compiler::reg::Live_variable_analyzer::compute_def_use(
    compiler::reg::Machine_function* const func) {
  for (compiler::reg::Machine_block* const block : *func->get_blocks()) {
    for (auto inst = (*block->get_instruction_list()).begin();
         inst != (*block->get_instruction_list()).end(); inst++) {
      auto user = *(*inst)->get_use();

      std::set<compiler::reg::Machine_operand*, Comparator> cur_set_user(
          user.begin(), user.end());
      // Compute the set differentce between use / def list.
      std::set_difference(cur_set_user.begin(), cur_set_user.end(),
                          def[block].begin(), def[block].end(),
                          std::inserter(use[block], use[block].end()));

      auto defs = *(*inst)->get_def();
      for (compiler::reg::Machine_operand* const item : defs) {
        // def[block].insert(all_uses[*item].begin(), all_uses[*item].end());
        def[block].insert(all_uses[item->get_register_name()].begin(),
                          all_uses[item->get_register_name()].end());
      }
    }
  }
}

void compiler::reg::Live_variable_analyzer::iterate(
    compiler::reg::Machine_function* const func) {
  for (compiler::reg::Machine_block* const block : *func->get_blocks()) {
    block->get_live_in()->clear();
  }

  // This variable marks if the current state is changing.
  // We need to iterate the interval until there is no change.
  bool change = true;
  while (change) {
    // Reset the variable.
    change = false;
    for (compiler::reg::Machine_block* const block : *func->get_blocks()) {
      block->get_live_out()->clear();

      // Fetch the old list in order to perform set difference for live variable
      // analysis.
      std::set<compiler::reg::Machine_operand*, Comparator>* const old =
          block->get_live_in();
      for (compiler::reg::Machine_block* const succ : *block->get_succs()) {
        block->get_live_out()->insert(succ->get_live_in()->begin(),
                                      succ->get_live_in()->end());
        *block->get_live_in() =
            std::set<compiler::reg::Machine_operand*, Comparator>(
                use[block].begin(), use[block].end());
        std::vector<compiler::reg::Machine_operand*> temp;

        std::set_difference(
            block->get_live_out()->begin(), block->get_live_out()->end(),
            def[block].begin(), def[block].end(),
            std::inserter(*block->get_live_in(), block->get_live_in()->end()));

        if (*old != *block->get_live_in()) {
          change = true;
        }
      }
    }
  }
}

void compiler::reg::Live_variable_analyzer::compute_use_pos(
    compiler::reg::Machine_function* const func) {
  for (compiler::reg::Machine_block* const block : *func->get_blocks()) {
    for (compiler::reg::Machine_instruction* const inst :
         *block->get_instruction_list()) {
      for (compiler::reg::Machine_operand* const use : *inst->get_use()) {
        // all_uses[*use].insert(use);
        all_uses[use->get_register_name()].insert(use);
      }
    }
  }
}

void compiler::reg::Live_variable_analyzer::pass(
    compiler::reg::Machine_unit* const unit) {
  for (compiler::reg::Machine_function* const func :
       *unit->get_function_list()) {
    // Construct the def-use chain.
    compute_use_pos(func);
    compute_def_use(func);
    iterate(func);
  }
}

void compiler::reg::Live_variable_analyzer::pass(
    compiler::reg::Machine_function* const func) {
  compute_use_pos(func);
  compute_def_use(func);
  iterate(func);
}

void compiler::reg::Assembly_builder::set_array_base(
    const std::string& array_name, const uint32_t& array_size) {
  array_base[machine_function][array_name] = 0;
  cur_sp += array_size;

  // Recalculate the offset for each array.
  for (auto& item : array_base[machine_function]) {
    if (item.first != array_name) {
      item.second += array_size;
    }
  }
}