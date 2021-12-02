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
#include <backend/allocator.hh>
#include <backend/assembly.hh>
#include <common/utils.hh>

void compiler::reg::Allocator::set_free_register(const std::string& reg_name) {
  virtual_to_physical[std::move(reg_name)] = true;
  free_registers++;
}

compiler::reg::Allocator::Allocator(const compiler::ir::cfg& cfg_blocks)
    : cfg_blocks(cfg_blocks) {
  // Initialize all the registers to be free.
  for (auto reg : compiler::reg::general_registers) {
    register_free_map[reg] = true;
  }
  for (auto reg : compiler::reg::argument_registers) {
    register_free_map[reg] = true;
  }
}

// This function will analyze the control flow graph of each function
// and then allocate the physical registers to each virtual registers.
// ! IMPORTANT: You should prune the cfg block before sending it to the
// ! allocator.
void compiler::reg::Allocator::generate_code(std::ostream& os) {
  for (auto func : cfg_blocks) {
#ifdef COMPILER_DEBUG
    std::cout << __LINE__ << ": Start to analyze function block " << func.first
              << std::endl;
#endif
    // First we will need to analyze the live variable, i.e., the so-called
    // "def-use" chain.
    compiler::reg::compute_def_use(func.second);
  }
}