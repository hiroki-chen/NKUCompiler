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
#include <common/compile_excepts.hh>
#include <frontend/nodes/item_literal.hh>

void compiler::Item_literal::generate_ir(
    compiler::ir::IRContext* const ir_context,
    compiler::ir::ir_list& ir_list) const {
  // Literal does not have IR.
  throw compiler::unsupported_operation("Cannot generate IR for literal type!");
}

compiler::ir::Operand* compiler::Item_literal_int::eval_runtime_helper(
    compiler::ir::IRContext* const ir_context) const {
  return new compiler::ir::Operand(
      ir::var_type::i32, "", std::to_string(get_int()), false, false);
}

compiler::ir::Operand* compiler::Item_literal_char::eval_runtime_helper(
    compiler::ir::IRContext* const ir_context) const {
  return new compiler::ir::Operand(
      ir::var_type::i8, "", std::to_string(get_char()), false, false);
}

compiler::ir::Operand* compiler::Item_literal_real::eval_runtime_helper(
    compiler::ir::IRContext* const ir_context) const {
  return new compiler::ir::Operand(
      ir::var_type::DB, "", std::to_string(get_double()), false, false);
}