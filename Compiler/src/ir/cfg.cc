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
#include <ir/cfg.hh>

compiler::ir::CFG_builder::CFG_builder(
    const std::vector<compiler::ir::IR>& ir_list) {
  uint32_t i = 0, id = 0;
  do {
    if (ir_list[i].get_op_type() == BEGIN_FUNC ||
        ir_list[i].get_op_type() == LBL) {
      
      name_to_id[ir_list[i].get_label()] = id;
      ir::cfg_block block;

      uint32_t j = i + 1;
      while (j < ir_list.size() && ir_list[j].get_op_type() != LBL &&
             ir_list[j].get_op_type() != END_FUNC) {
        block.emplace_back(const_cast<ir::IR*>(&ir_list[j]));
        j++;
      }
      i = j;
      look_up_table[id++] = block;
    } else if (ir_list[i].get_op_type() == END_FUNC) {
      i++;
    }
  } while (i < ir_list.size());

}

void compiler::ir::CFG_builder::prettier_ir(std::ostream& out) { ; }