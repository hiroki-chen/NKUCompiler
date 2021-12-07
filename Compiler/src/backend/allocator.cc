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
#include <backend/analyzer.hh>
#include <common/compile_excepts.hh>
#include <memory>

static const auto interval_compare =
    [](compiler::reg::Interval* const lhs,
       compiler::reg::Interval* const rhs) -> bool {
  return lhs->start < rhs->start;
};

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

void compiler::reg::Allocator::modify_code(void) {
  for (compiler::reg::Interval* const interval : intervals) {
    func->add_saved_regs(interval->phy_reg);

    for (compiler::reg::Machine_operand* const def : interval->defs) {
      def->set_register_name(interval->phy_reg);
    }
    for (compiler::reg::Machine_operand* const use : interval->uses) {
      use->set_register_name(interval->phy_reg);
    }
  }
}

// chb:
// Your jobs may include:
// 1. Allocate registers;
// 2. Spill overflown registers onto the stack.
// 3. Determine the stack frame of the function and set the stack size / saved
// registers.
// 4. (Optional) Do some optimizations.
bool compiler::reg::Allocator::linear_scan_register_allocate(void) {
  // TODO:
  throw compiler::unimplemented_error("Error: Linear scan is not implemented.");
}

void compiler::reg::Allocator::do_color_graphing(void) {
  // TODO: Implement me. Choose whatever you want.
}

void compiler::reg::Allocator::do_linear_scan(void) {
  for (compiler::reg::Machine_function* const f : *unit->get_function_list()) {
    func = f;
    bool success = false;
    // repeat until all vregs can be mapped
    while (!success) {
      compute_live_intervals();
      success = linear_scan_register_allocate();
      if (success) {
        // all vregs can be mapped to real regs
        modify_code();
      } else {
        // spill vregs that can't be mapped to real regs
        genenrate_spilled_code();
      }
    }
  }
}

void compiler::reg::Allocator::make_du_chains(void) {
  const std::unique_ptr<compiler::reg::Live_variable_analyzer> analyzer =
      std::make_unique<compiler::reg::Live_variable_analyzer>();
  analyzer->pass(func);
  du_chains.clear();
  uint32_t i = 0;
  std::map<compiler::reg::Machine_operand,
           std::set<Machine_operand*, Comparator>>
      live_var;

  for (compiler::reg::Machine_block* const block : *func->get_blocks()) {
    live_var.clear();
    for (compiler::reg::Machine_operand* const t : *block->get_live_out()) {
      live_var[*t].insert(t);
    }

    i = block->get_instruction_list()->size() + i;
    uint32_t no = i;

    for (auto inst = block->get_instruction_list()->rbegin();
         inst != block->get_instruction_list()->rend(); inst++) {
      (*inst)->set_no(no--);

      for (compiler::reg::Machine_operand* const def : *(*inst)->get_def()) {
        if (def->is_vreg()) {
          auto& uses = live_var[*def];
          du_chains[def].insert(uses.begin(), uses.end());
          auto& kill = (*analyzer->get_all_uses())[*def];

          std::set<compiler::reg::Machine_operand*, Comparator> res;
          std::set_difference(uses.begin(), uses.end(), kill.begin(),
                              kill.end(), std::inserter(res, res.end()));
          live_var[*def] = res;
        }
      }

      for (compiler::reg::Machine_operand* const use : *(*inst)->get_use()) {
        if (use->is_vreg()) {
          live_var[*use].insert(use);
        }
      }
    }
  }
}

void compiler::reg::Allocator::compute_live_intervals(void) {
  make_du_chains();
  intervals.clear();

  for (auto& du_chain : du_chains) {
    int t = -1;
    for (compiler::reg::Machine_operand* const use : du_chain.second) {
      const int no = use->get_parent()->get_no();
      t = std::max(t, no);
    }

    compiler::reg::Interval* const interval = new compiler::reg::Interval(
        du_chain.first->get_parent()->get_no(), t, false, 0, "");
    interval->set_def({du_chain.first});
    interval->set_use(du_chain.second);
    intervals.emplace_back(interval);
  }

  do_compute_live_intervals();
}

void compiler::reg::Allocator::do_compute_live_intervals(void) {
  bool change = true;
  while (change) {
    change = false;

    std::vector<compiler::reg::Interval*> t(intervals.begin(), intervals.end());
    for (size_t i = 0; i < t.size(); i++) {
      for (size_t j = i + 1; j < t.size(); j++) {
        compiler::reg::Interval *const w1 = t[i], *const w2 = t[j];
        // Do a set difference to compute the overlap of each interval and we
        // can actually merge some intervals with overlaps.
        if (**w1->defs.begin() == **w2->defs.begin()) {
          std::set<compiler::reg::Machine_operand*, Comparator> set;
          std::set_intersection(w1->uses.begin(), w1->uses.end(),
                                w2->uses.begin(), w2->uses.end(),
                                std::inserter(set, set.end()));

          if (!set.empty()) {
            // Merge overlapping intervals.
            change = true;
            w1->defs.insert(w2->defs.begin(), w2->defs.end());
            w1->uses.insert(w2->uses.begin(), w2->uses.end());
            
            // Determine the start and end point.
            w1->start = std::min(w1->start, w2->start);
            w1->end = std::max(w1->end, w2->end);
            auto iter = std::find(intervals.begin(), intervals.end(), w2);
            if (iter != intervals.end()) {
              intervals.erase(iter);
            }
          }
        }
      }
    }
  }

  // Sort the intervals by their start point.
  std::sort(intervals.begin(), intervals.end(), interval_compare);
}

void compiler::reg::Allocator::expre_old_intervals(Interval* const interval) {
  // Todo
}

void compiler::reg::Allocator::spill_at_interval(Interval* const interval) {
  // Todo
}

void compiler::reg::Allocator::genenrate_spilled_code(void) {
  for (compiler::reg::Interval* const interval : intervals) {
    if (!interval->spill) {
      continue;
    } else {
      // TODO
      /* HINT:
        The vreg should be spilled to memory.
        1. insert ldr inst before the use of vreg
        2. insert str inst after the def of vreg
       */
    }
  }
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