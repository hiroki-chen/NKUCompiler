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

  // Traverse each functions.
  for (auto func : cfg_blocks) {
    // First we will need to analyze the live variable, i.e., the so-called
    // "def-use" chain.
    // compiler::reg::compute_def_use(func.second);
    compiler::reg::Machine_function* const machine_function =
        generate(func.second, func.first, machine_unit);
    // Append to the function list of the machine unit.
    machine_unit->add_function(machine_function);
  }

  // TODO: Allocate registers.

  // Finally, we emit the assembly from machine unit.
  machine_unit->emit_assembly(os);
}

compiler::reg::Machine_function* compiler::reg::Analyzer::generate(
    const std::vector<compiler::ir::CFG_block*>& function,
    const std::string& func_name, compiler::reg::Machine_unit* const parent) {
  compiler::reg::Machine_function* const machine_function =
      new compiler::reg::Machine_function(parent, func_name);

  for (compiler::ir::CFG_block* const block : function) {
    // Handle one block.
    compiler::reg::Machine_block* const machine_block =
        generate(block, machine_function);
    machine_function->add_block(machine_block);
  }

  return machine_function;
}

compiler::reg::Machine_block* compiler::reg::Analyzer::generate(
    compiler::ir::CFG_block* const block,
    compiler::reg::Machine_function* const parent) {
  compiler::reg::Machine_block* const machine_block =
      new compiler::reg::Machine_block(parent, block->get_id());

  compiler::ir::ir_list* const ir_list = block->get_ir_list();

  // Do translation.
  for (compiler::ir::IR ir : *ir_list) {
    // TODO...
    // ? HOW TO HANDLE JUMP -> Control flow is changed.
  }

  return machine_block;
}