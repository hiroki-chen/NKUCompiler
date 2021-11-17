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
#include <frontend/nodes/item_func.hh>

void compiler::Item_func_def::generate_ir_helper(
    compiler::ir::IRContext* const ir_context,
    std::vector<compiler::ir::IR>& ir_list) const {
  ir_context->enter_scope();
  const size_t argument_number = parameter->get_arg_number();
  ir_list.emplace_back(
      ir::op_type::BEGIN_FUNC, nullptr,
      new ir::Operand(ir::var_type::NONE, "", std::to_string(argument_number)),
      identifier->get_name());

  // Get all the arguments.
  const std::vector<Item_func_def_arg*> arguments = parameter->get_arguments();
  for (size_t i = 0; i < argument_number; i++) {
    const compiler::Item_func_def_arg* const arg = arguments[i];
    const compiler::Item_ident* const identifier = arg->get_identifier();
  }

  ir_context->leave_scope();
}