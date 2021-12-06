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
#include <backend/allocator.hh>

void compiler::reg::Allocator::reserve_for_function_call(void) {
  // ARM-v7 has enforced that these four registers cannot be used to store
  // general variables.
  virtual_to_physical["$arg0"] = "r0";
  virtual_to_physical["$arg1"] = "r1";
  virtual_to_physical["$arg2"] = "r2";
  virtual_to_physical["$arg3"] = "r3";
}

void compiler::reg::Allocator::set_free_register(const std::string& reg_name) {
  virtual_to_physical[std::move(reg_name)] = true;
  free_registers++;
}

// chb:
// Your jobs may include:
// 1. Allocate registers;
// 2. Spill overflown registers onto the stack.
// 3. Determine the stack frame of the function and set the stack size / saved registers.
// 4. (Optional) Do some optimizations.
void compiler::reg::Allocator::do_color_graphing(void) {
  // TODO: Implement me. Choose whatever you want.
}

void compiler::reg::Allocator::do_linear_scan(void) {
  // TODO: Implement me. Choose whatever you want.
}

compiler::reg::Allocator::Allocator(Machine_unit* const machine_unit)
    : unit(machine_unit) {
  // Initialize all the registers to be free.
  for (auto reg : compiler::reg::general_registers) {
    register_free_map[reg] = true;
  }
  for (auto reg : compiler::reg::argument_registers) {
    register_free_map[reg] = true;
  }

  // Reserve registers for function call.
  reserve_for_function_call();
}