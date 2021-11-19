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
#include <common/utils.hh>
#include <frontend/nodes/item_func.hh>

void compiler::Item_func_def::generate_ir_helper(
    compiler::ir::IRContext* const ir_context,
    std::vector<compiler::ir::IR>& ir_list) const {
  ir_context->enter_scope();
  const size_t argument_number = parameter->get_arg_number();
  
  // BEGIN_FUNCTION.
  ir_list.emplace_back(
      ir::op_type::BEGIN_FUNC, nullptr,
      new ir::Operand(to_ir_type(return_type), "", std::to_string(argument_number), false, false),
      identifier->get_name());

  // Get all the arguments.
  const std::vector<Item_func_def_arg*> arguments = parameter->get_arguments();
  for (size_t i = 0; i < argument_number; i++) {
    const compiler::Item_func_def_arg* const arg = arguments[i];
    const compiler::Item_ident* const identifier = arg->get_identifier();
  }

  ir_list.emplace_back(ir::op_type::END_FUNC, identifier->get_name());
  ir_context->leave_scope();
}

compiler::ir::Operand* compiler::Item_func_call::eval_runtime_helper(
    compiler::ir::IRContext* const ir_context,
    std::vector<compiler::ir::IR>& ir_list) const {
  std::vector<ir::Operand*> operands;
  ir::Operand* const dst = new ir::Operand(
      "%" +
      std::to_string(ir_context->get_symbol_table()->get_top_scope_uuid()));

  const std::vector<compiler::Item_expr*> args = arguments->get_arguments();
  for (uint32_t i = 0; i < args.size(); i++) {
    operands.emplace_back(args[i]->eval_runtime(ir_context, ir_list));
  }

  // Set arguments.
  for (uint32_t i = 0; i < args.size(); i++) {
    ir::Operand* const arg_pos = new ir::Operand(ir::var_type::NONE, std::to_string(i), "", false, false);
    ir_list.emplace_back(ir::op_type::ARG, arg_pos, identifier->get_name());
  }

  ir_list.emplace_back(ir::op_type::CALL, dst, identifier->get_name());
  return dst;
}