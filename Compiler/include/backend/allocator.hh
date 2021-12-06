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
#ifndef ALLOCATOR_HH
#define ALLOCATOR_HH

#include <backend/interval.hh>
#include <backend/units.hh>
#include <string>
#include <unordered_map>
#include <vector>

namespace compiler::reg {
/**
 * @brief A class that analyzes the def-use chain and then perform register
 *        allocations for each machine instruction where each register is
 *        virtual.
 *
 * @author xjw
 *
 */
typedef class Allocator final {
 private:
  /**
   * @brief The define-use chain data structure.
   *
   */
  std::map<Machine_operand*, std::set<Machine_operand*, Comparator>> du_chains;

  std::vector<Interval*> intervals;

  Machine_unit* unit;

  Machine_function* func;

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

  // =================== Functions ===================== //
  void reserve_for_function_call(void);

  void set_free_register(const std::string& name);

  static bool compare_start(Interval* const lhs, Interval* const rhs);

  void expre_old_intervals(Interval* const interval);

  void spill_at_interval(Interval* const interval);

  void make_du_chains(void);

  void compute_live_intervals(void);

  bool linear_scan_register_allicate(void);

  void modify_code(void);

  void genenrate_spilled_code(void);

 public:
  Allocator() = delete;

  Allocator(Machine_unit* const machine_unit);

  void do_linear_scan(void);

  void do_color_graphing(void);

  bool is_on_stack(const std::string& name) {
    return virtual_to_physical.count(name) == 0 &&
           stack_offset.count(name) != 0;
  }

} Allocator;
}  // namespace compiler::reg

#endif