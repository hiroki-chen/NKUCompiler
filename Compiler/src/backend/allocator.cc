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
#include <common/compile_excepts.hh>
#include <memory>
#include <utility>

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
  // throw compiler::unimplemented_error("Error: Linear scan is not
  // implemented.");
  for (auto reg : compiler::reg::general_registers) {
    register_free_map[reg] = nullptr;
  }

  // std::cout << "==================" << std::endl;
  // std::cout << "hhh" << std::endl;
  bool res = true;
  compiler::reg::Interval* conflict = nullptr;
  for (auto& reg_usage : intervals) {
    // std::cout << reg_usage->start << " " << reg_usage->end << " " <<
    // std::endl; for (auto& i : reg_usage->defs) std::cout <<
    // i->get_register_name() << " "; std::cout << std::endl; for (auto& i :
    // reg_usage->uses) std::cout << i->get_register_name() << " "; std::cout <<
    // std::endl << "#####" << std::endl;  // for (auto& active_reg :
    // register_free_map)
    //   std::cout << active_reg.second << " ";
    // std::cout << std::endl;
    for (auto& active_reg : register_free_map) {
      if (!active_reg.second || active_reg.second->end <= reg_usage->start) {
        active_reg.second = reg_usage;
        reg_usage->phy_reg = active_reg.first;
        reg_usage->spill = false;
        break;
      } else {
        reg_usage->spill = true;
        conflict = active_reg.second;
      }
      // std::cout << active_reg.first << ": " << active_reg.second <<
      // std::endl;
    }
    if (res && reg_usage->spill) res = false;
  }
  if (!res) {
    conflict->spill = true;
  }
  return res;
}

void compiler::reg::Allocator::do_color_graphing(void) {
  // TODO: Implement me. Choose whatever you want.
}

void compiler::reg::Allocator::do_linear_scan(void) {
  for (compiler::reg::Machine_function* const f : *unit->get_function_list()) {
    func = f;
    bool success = false;
    // repeat until all vregs can be mapped
    int count = 0;
    while (!success) {
      count++;
      compute_live_intervals();

      // for(auto & interval : intervals) {
      // std::cout << interval->start << " " << interval->end << ": " <<
      // std::endl << "\tdef: "; for(auto & def : interval->defs) std::cout <<
      // def->get_register_name() << ", "; std::cout << "\n\tuse: "; for(auto
      // & use : interval->uses) std::cout << use->get_register_name() << ",
      // "; std::cout << std::endl;
      // }

      success = linear_scan_register_allocate();
      // genenrate_spilled_code();
      // compute_live_intervals();
      // for(auto & interval : intervals) {
      //   std::cout << interval->start << " " << interval->end << ": " <<
      //   std::endl << "\tdef: "; for(auto & def : interval->defs) std::cout <<
      //   def->get_register_name() << ", "; std::cout << "\n\tuse: ";
      //   for(auto& use : interval->uses) std::cout << use->get_register_name()
      //   << ","; std::cout << std::endl;
      // }
      // break;
      if (success) {
        // all vregs can be mapped to real regs
        // func->emit_assembly(std::cout << "funchhh==========\n");
        modify_code();

        reg::Machine_operand* const sp = new reg::Machine_operand(
            reg::operand_type::REG, reg::stack_pointer);
        reg::Machine_operand* const fp = new reg::Machine_operand(
            reg::operand_type::REG, reg::frame_pointer);
        reg::Machine_operand* const r14 =
            new reg::Machine_operand(reg::operand_type::REG, "r14");
        reg::Machine_operand* const offset = new reg::Machine_operand(
            reg::operand_type::IMM, std::to_string(stack_top_offset));
        reg::Machine_instruction_stack* const stack_fp =
            new reg::Machine_instruction_stack((*func->begin()),
                                               reg::stack_type::PUSH, fp);
        reg::Machine_instruction_stack* const stack_r14 =
            new reg::Machine_instruction_stack((*func->begin()),
                                               reg::stack_type::PUSH, r14);
        reg::Machine_instruction_mov* const mov_sp =
            new reg::Machine_instruction_mov((*func->begin()),
                                             reg::mov_type::MOV_N, fp, sp);
        reg::Machine_instruction_binary* const sub_sp =
            new reg::Machine_instruction_binary(
                (*func->begin()), reg::binary_type::SUB, sp, sp, offset);
        (*func->begin())
            ->get_instruction_list()
            ->insert((*func->begin())->begin(), sub_sp);
        (*func->begin())
            ->get_instruction_list()
            ->insert((*func->begin())->begin(), mov_sp);
        (*func->begin())
            ->get_instruction_list()
            ->insert((*func->begin())->begin(), stack_fp);
        for (auto reg : compiler::reg::general_registers) {
          reg::Machine_instruction_stack* const stack_r =
              new reg::Machine_instruction_stack(
                  (*func->begin()), reg::stack_type::PUSH,
                  new reg::Machine_operand(reg::operand_type::REG, reg));
          (*func->begin())
              ->get_instruction_list()
              ->insert((*func->begin())->begin(), stack_r);
        }
        (*func->begin())
            ->get_instruction_list()
            ->insert((*func->begin())->begin(), stack_r14);
      } else {
        // spill vregs that can't be mapped to real regs
        // break;
        genenrate_spilled_code();
        // func->emit_assembly(std::cout << "funchhh==========\n");
        // if (count == 2) break;
        // break;
      }
    }
  }
}

void compiler::reg::Allocator::make_du_chains(void) {
  du_chains.clear();
  loop_label_stack.clear();
  std::map<std::string, std::pair<std::set<Machine_operand*, Comparator>,
                                  std::set<Machine_operand*, Comparator>>>
      live_var;
  uint32_t num = 0;
  for (auto& block : *(func->get_blocks())) {
    if (block->get_label().find("LOOP_BODY") != -1) {
      loop_label_stack.emplace_back(num++, -1);
    } else if (block->get_label().find("LOOP_END") != -1) {
      for (auto i = loop_label_stack.rbegin(); i != loop_label_stack.rend();
           i++) {
        if (i->second == -1) {
          i->second = num++;
          break;
        }
      }
    }

    for (auto& inst : *(block->get_instruction_list())) {
      inst->set_no(num++);
      for (auto& def : *(inst->get_def()))
        if (def->is_vreg()) {
          auto& var = live_var[def->get_register_name()];
          // inst->emit_assembly(std::cout << "========\n"
          //                               << def->get_register_name());
          if (var.second.size()) {
            bool flag = true;
            for (auto loop = loop_label_stack.rbegin();
                 loop != loop_label_stack.rend(); loop++) {
              if (loop->second == -1) {
                for (auto& i : var.first) {
                  if (i->get_parent()->get_no() < loop->first) {
                    flag = false;
                    break;
                  }
                }
                break;
              }
            }
            if (flag) {
              du_chains.push_back(var);
              var.second.clear();
              var.first.clear();
            }
          }
          var.first.insert(def);
          //   std::cout << var.first.size();
          // for (auto& def : var.first)
          //   def->get_parent()->emit_assembly(std::cout << "def ");
          // for (auto& use : var.second)
          //   use->get_parent()->emit_assembly(std::cout << "use ");
        }
      for (auto& use : *(inst->get_use()))
        if (use->is_vreg()) {
          // auto& var = live_var[use->get_register_name()];
          // inst->emit_assembly(std::cout << "========\n"
          //                               << use->get_register_name());
          if (live_var[use->get_register_name()].first.size() == 0) throw;
          live_var[use->get_register_name()].second.insert(use);

          // for (auto& def : var.first)
          //   def->get_parent()->emit_assembly(std::cout << "def ");
          // for (auto& use : var.second)
          //   use->get_parent()->emit_assembly(std::cout << "use ");
        }
    }
  }
  for (auto& var : live_var) {
    du_chains.push_back(var.second);
  }
}

void compiler::reg::Allocator::compute_live_intervals(void) {
  make_du_chains();
  intervals.clear();

  for (auto& du_chain : du_chains) {
    int t = -1;
    int t_d = -1;
    // if (du_chain.first.empty()) {
    // std::cout << "\nlive interval\n";
    // for (auto& def : du_chain.first)
    //   def->get_parent()->emit_assembly(std::cout << " def");
    // for (auto& use : du_chain.second)
    //   use->get_parent()->emit_assembly(std::cout << " use");
    // }

    for (compiler::reg::Machine_operand* const use : du_chain.second) {
      const int no = use->get_parent()->get_no();
      t = std::max(t, no);
    }
    // std::cout << du_chain.first.size() << std::endl;
    for (compiler::reg::Machine_operand* const def : du_chain.first) {
      const int no = def->get_parent()->get_no();
      if (t_d == -1)
        t_d = no;
      else
        t_d = std::min(t_d, no);
    }

    compiler::reg::Interval* const interval =
        new compiler::reg::Interval(t_d, t, false, 0, "");
    interval->set_def(du_chain.first);
    interval->set_use(du_chain.second);
    intervals.emplace_back(interval);
  }
  for (auto& interval : intervals) {
    for (auto loop_iter = loop_label_stack.rbegin();
         loop_iter != loop_label_stack.rend(); loop_iter++) {
      auto loop = *loop_iter;
      if (interval->start < loop.first && interval->end > loop.first) {
        interval->end = loop.second;
      }
    }
  }

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
      // throw compiler::unimplemented_error("Error: Linear scan is not
      // implemented.");

      stack_top_offset += 4;  // alloc
      for (auto& use : interval->uses) {
        use->reset_register_name(spill_label +
                                 std::to_string(get_spil_available_id()));
        compiler::reg::Machine_block* block = use->get_parent()->get_parent();
        auto pos =
            std::find(block->get_instruction_list()->begin(),
                      block->get_instruction_list()->end(), use->get_parent());
        reg::Machine_operand* const fp = new reg::Machine_operand(
            reg::operand_type::REG, reg::frame_pointer);
        reg::Machine_operand* const offset = new reg::Machine_operand(
            reg::operand_type::IMM, std::to_string(-stack_top_offset));
        reg::Machine_instruction_load* const ldr =
            new reg::Machine_instruction_load(
                block, new reg::Machine_operand(*use), fp, offset);
        block->get_instruction_list()->insert(pos, ldr);
        // std::cout << use->get_register_name() << std::endl;
        // std::cout << "load add:" << std::endl;
        // block->emit_assembly(std::cout);
      }
      for (auto& def : interval->defs) {
        def->reset_register_name(spill_label +
                                 std::to_string(get_spil_available_id()));
        compiler::reg::Machine_block* block = def->get_parent()->get_parent();
        auto pos =
            std::find(block->get_instruction_list()->begin(),
                      block->get_instruction_list()->end(), def->get_parent());
        pos++;
        reg::Machine_operand* const fp = new reg::Machine_operand(
            reg::operand_type::REG, reg::frame_pointer);
        reg::Machine_operand* const offset = new reg::Machine_operand(
            reg::operand_type::IMM, std::to_string(-stack_top_offset));
        reg::Machine_instruction_store* const ldr =
            new reg::Machine_instruction_store(block, new Machine_operand(*def),
                                               fp, offset);
        block->get_instruction_list()->insert(pos, ldr);
        // std::cout << "store add:" << std::endl;
        // block->emit_assembly(std::cout);
      }
    }
  }
}

compiler::reg::Allocator::Allocator(Machine_unit* const machine_unit)
    : unit(machine_unit), stack_top_offset(0), spill_id(0) {
  // Initialize all the registers to be free.
  for (auto reg : compiler::reg::general_registers) {
    register_free_map[reg] = nullptr;
  }
  // for (auto reg : compiler::reg::argument_registers) {
  //   register_free_map[reg] = nullptr;
  // }

  // Reserve registers for function call.
  reserve_for_function_call();
}