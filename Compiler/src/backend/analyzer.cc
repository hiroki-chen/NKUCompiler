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
#include <common/utils.hh>
#include <map>

void compiler::reg::Analyzer::reserve_for_function_call(void) {
  // ARM-v7 has enforced that these four registers cannot be used to store
  // general variables.
  virtual_to_physical["$arg0"] = "r0";
  virtual_to_physical["$arg1"] = "r1";
  virtual_to_physical["$arg2"] = "r2";
  virtual_to_physical["$arg3"] = "r3";
}

void compiler::reg::Analyzer::set_free_register(const std::string& reg_name) {
  virtual_to_physical[std::move(reg_name)] = true;
  free_registers++;

  // Reserve registers for function call.
  reserve_for_function_call();
}

compiler::reg::Analyzer::Analyzer(
    const std::map<std::string, std::vector<compiler::ir::CFG_block*>>&
        cfg_blocks)
    : cfg_blocks(cfg_blocks) {
  // Create an empty Assembly_builder class for future usage :)
  asm_builder = new Assembly_builder();

  // Initialize all the registers to be free.
  for (auto reg : compiler::reg::general_registers) {
    register_free_map[reg] = true;
  }
  for (auto reg : compiler::reg::argument_registers) {
    register_free_map[reg] = true;
  }
}

void compiler::reg::Analyzer::generate_code(std::ostream& os) {
  // This function will analyze the control flow graph of each function
  // and then allocate the physical registers to each virtual registers.
  // Create an empty machine unit type.
  compiler::reg::Machine_unit* const machine_unit =
      new compiler::reg::Machine_unit();
  asm_builder->set_unit(machine_unit);

  // Traverse each functions.
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

  // TODO: Allocate registers.

  // Finally, we emit the assembly from machine unit.
  machine_unit->emit_assembly(os);
}

void compiler::reg::Analyzer::generate(
    const std::vector<compiler::ir::CFG_block*>& function,
    const std::string& func_name) {
  compiler::reg::Machine_unit* const unit_cur = asm_builder->get_unit();
  compiler::reg::Machine_function* const func_cur =
      new compiler::reg::Machine_function(unit_cur, func_name);

  const uint32_t stack_size =
      4 * (1 + std::stoul(func_name.substr(1 + func_name.find_last_of("_"))));
  func_cur->allocate_stack(stack_size);  // May be used later?

  // Hint:
  // 1. Save fp
  // 2. fp = sp
  // 3. Save callee saved register
  // 4. Allocate stack space for local variable. [We use explicit mov $arg... to
  // handle this.]

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
  bool allocate = true;
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

    // SUB sp, sp, #4
    // STR r14, [sp,#0]
    if (allocate == true) {
      reg::Machine_operand* const size = new reg::Machine_operand(
          reg::operand_type::IMM, std::to_string(stack_size));
      reg::Machine_operand* const sp =
          new reg::Machine_operand(reg::operand_type::REG, reg::stack_pointer);
      reg::Machine_instruction_binary* const sub =
          new reg::Machine_instruction_binary(
              machine_block, reg::binary_type::SUB, sp, sp, size);
      machine_block->add_instruction(sub);

      allocate = false;
    }
  }
}

void compiler::reg::Analyzer::generate(compiler::ir::CFG_block* const block) {
  compiler::reg::Machine_function* const cur_func = asm_builder->get_function();
  compiler::reg::Machine_block* const cur_block =
      new compiler::reg::Machine_block(cur_func, block->get_name());
  asm_builder->set_block(cur_block);

  for (compiler::ir::IR ir : *block->get_ir_list()) {
    ir.emit_machine_code(asm_builder);
  }

  cur_func->add_block(cur_block);
}