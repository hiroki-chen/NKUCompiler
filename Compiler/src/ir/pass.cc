/*
 Copyright (c) 2021 Haobin Chen

 This program is free software: you can redistribute iter and/or modify
 iter under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that iter will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include <common/utils.hh>
#include <ir/pass.hh>

void compiler::ir::pass::Dead_code_pass::set_latest_use(IR* const ir) {
  if (ir->get_op_type() != ir::op_type::MALLOC) {
    // Take advantages of the callback function to analaze the data flow between
    // instruction. This handles normal types of instructions.
    ir->walk_ir([&, this](ir::Operand* const operand) {
      if (operand != nullptr && operand->get_is_var()) {
        const std::string name = operand->get_identifier();
        if (!var_latest_use_timestamp.count(name) ||
            name.find(ir::local_sign) == std::string::npos) {
          // Setup the correct mapping.
          var_latest_use_timestamp.insert(std::make_pair(name, ir_to_time[ir]));
          var_latest_use_timestamp_heap.insert(
              std::make_pair(ir_to_time[ir], name));
        }
      }
    });
  }

  // Case 1: Multiplication.
  if (ir->get_op_type() == ir::op_type::IMUL && ir->get_op1()->get_is_var()) {
    var_latest_use_timestamp[ir->get_op1()->get_identifier()]++;
  }

  // Case 2: Function argument setting.
  //  op  dst  op_a       op_b
  // PUSH /  <arg_no>  <var_name>
  if (ir->get_op_type() == ir::op_type::PUSH) {
    const uint32_t arg_no = std::stoul(ir->get_op1()->get_value());
    // If the argument register can fit this variable.
    if (arg_no <= 3ul) {
      compiler::ir::IR* const phi_ir = &(*ir->get_phi_block());
      const std::string name = std::move(
          compiler::concatenate(ir::arg_sign, arg_no, ir_to_time[phi_ir]));
      var_latest_use_timestamp.insert(std::make_pair(name, ir_to_time[phi_ir]));
      var_latest_use_timestamp_heap.insert(
          std::make_pair(ir_to_time[phi_ir], name));
    }
  }

  // Case 3: Function call.
  // Specially, division and modulo are performed by __aeabi_idiv and
  // __aeabi_idivmod abi functions, for what they should be treated as function
  // call as well. :)
  if (ir->get_op_type() == ir::op_type::CALL ||
      ir->get_op_type() == ir::op_type::IDIV ||
      ir->get_op_type() == ir::op_type::IMOD) {
    for (uint32_t i = 0; i < 4; i++) {
      // Concatenate the name for look-up.
      const std::string name =
          std::move(compiler::concatenate(ir::arg_sign, i, ir_to_time[ir]));
      var_latest_use_timestamp.insert(std::make_pair(name, ir_to_time[ir]));
      var_latest_use_timestamp_heap.insert(
          std::make_pair(ir_to_time[ir], name));
    }
  }
}

void compiler::ir::pass::Dead_code_pass::set_var_def(IR* const ir) {
  if (ir->get_op_type() != ir::op_type::MALLOC &&
      ir->get_op_type() != ir::op_type::PHI && ir->get_dst() != nullptr) {
    if (ir->get_dst()->get_is_var() &&
        !var_def_timestamp.count(ir->get_dst()->get_identifier())) {
      var_def_timestamp.insert(
          std::make_pair(ir->get_dst()->get_identifier(), ir_to_time[ir]));
      var_def_timestamp_heap.insert(
          std::make_pair(ir_to_time[ir], ir->get_dst()->get_identifier()));
    }
  } else if (ir->get_op_type() != ir::op_type::PHI &&
             ir->get_dst() != nullptr && ir->get_dst()->get_is_var()) {
    if (!var_def_timestamp.count(ir->get_dst()->get_identifier())) {
      const uint32_t phi_time = ir_to_time[&(*ir->get_phi_block())];
      const uint32_t cur_time = ir_to_time[ir];
      const uint32_t def_time = std::min(phi_time, cur_time);

      var_def_timestamp.insert(
          std::make_pair(ir->get_dst()->get_identifier(), def_time));
      var_def_timestamp_heap.insert(
          std::make_pair(def_time, ir->get_dst()->get_identifier()));
    }
  }

  if (ir->get_op_type() == ir::op_type::CALL ||
      ir->get_op_type() == ir::op_type::IDIV ||
      ir->get_op_type() == ir::op_type::IMOD) {
    for (uint32_t i = 0; i < 4; i++) {
      // Concatenate the name for look-up.
      const std::string name =
          std::move(compiler::concatenate(ir::arg_sign, i, ir_to_time[ir]));
      var_def_timestamp.insert(std::make_pair(name, ir_to_time[ir]));
      var_def_timestamp_heap.insert(std::make_pair(ir_to_time[ir], name));
    }
  }

  if (ir->get_op_type() == ir::op_type::PUSH) {
    const uint32_t arg_no = std::stoul(ir->get_op1()->get_value());
    // If the argument register can fit this variable.
    if (arg_no <= 3ul) {
      compiler::ir::IR* const phi_ir = &(*ir->get_phi_block());
      const std::string name = std::move(
          compiler::concatenate(ir::arg_sign, arg_no, ir_to_time[phi_ir]));
      var_def_timestamp.insert(std::make_pair(name, ir_to_time[phi_ir]));
      var_def_timestamp_heap.insert(std::make_pair(ir_to_time[phi_ir], name));
    }
  }
}

bool compiler::ir::pass::Dead_code_pass::do_pass(
    const std::vector<compiler::ir::IR*>& ir_list) {
  // This variable marks if the current IR list has been changed.
  bool change = false;
  // First iterate over the ir list and set the timestamp for each.
  for (auto ir : ir_list) {
    ir_to_time[ir] = timestamp++;
  }

  // Iterate the ir list in a backward manner to determine the usage of each
  // variable.
  for (auto iter = std::prev(ir_list.end()); iter != ir_list.begin(); iter--) {
    IR* const ir = *iter;
    // If this ir is dead, we ignore it.
    if (ir->get_is_dead()) {
      continue;
    }
    set_latest_use(ir);

    uint32_t cur_timestamp = ir_to_time[ir];
    if (ir->get_dst() != nullptr && ir->get_dst()->get_is_var() &&
        ir->get_dst()->get_identifier().substr(0, 2) == ir::local_sign &&
        // Cannot eliminate call / phi move since they are not related to the
        // variable. The data flow is altered by such instructions.
        ir->get_op_type() != ir::op_type::CALL &&
        ir->get_op_type() != ir::op_type::PHI) {
      const std::string var_name = ir->get_dst()->get_identifier();

      // Check if the variable is used.
      const bool is_dead = var_latest_use_timestamp.find(var_name) ==
                           var_latest_use_timestamp.end();

      // If a variable is no longer used or never appears in any future
      // instructions, then we can safely eliminate the whole instruction and
      // its successors, which is done by iteration.
      if (is_dead ||
          var_latest_use_timestamp[var_name] <= cur_timestamp /* Expired */) {
        std::cerr << "This is dead: \n";
        ir->emit_ir(std::cerr);
        change = true;
        ir->set_dead();
      }
    }
  }

  for (ir::IR* const ir : ir_list) {
    if (!ir->get_is_dead()) {
      set_var_def(ir);
    }
  }

  return change;
}

void compiler::ir::pass::Dead_code_pass::reset(void) {
  timestamp = 0ul;
  var_def_timestamp.clear();
  var_latest_use_timestamp.clear();
  var_def_timestamp_heap.clear();
  var_latest_use_timestamp_heap.clear();
}