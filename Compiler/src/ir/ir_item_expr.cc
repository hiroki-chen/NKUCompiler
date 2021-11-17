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
#include <frontend/nodes/item_expr.hh>

extern uint32_t opt_level;
extern compiler::NodeStack stack;

compiler::ir::BranchIR compiler::Item_expr::eval_cond_helper(
    compiler::ir::IRContext* const ir_context,
    std::vector<compiler::ir::IR>& ir_list) const {
  compiler::ir::BranchIR branch_ir;
  ir_list.emplace_back(compiler::ir::op_type::CMP, new compiler::ir::Operand(),
                       eval_runtime_helper(ir_context, ir_list));

  // Set jne and jmp.
  branch_ir.first = compiler::ir::op_type::JNE;
  branch_ir.second = compiler::ir::op_type::JMP;
  return branch_ir;
}

compiler::ir::Operand* compiler::Item_expr::eval_runtime_helper(
    compiler::ir::IRContext* const ir_context,
    std::vector<compiler::ir::IR>& ir_list) const {
  throw compiler::unsupported_operation(
      "Cannot evaluate this expression at runtime!");
}

compiler::ir::Operand* compiler::Item_expr::eval_runtime_helper(
    compiler::ir::IRContext* const ir_context) const {
  throw compiler::unsupported_operation(
      "Cannot evaluate this expression at runtime!");
}

compiler::ir::BranchIR compiler::Item_expr::eval_cond(
    compiler::ir::IRContext* const ir_context,
    std::vector<compiler::ir::IR>& ir_list) const {
  stack.push_back(
      static_cast<compiler::Item*>(const_cast<compiler::Item_expr*>(this)));
  try {
    const compiler::ir::BranchIR branch_ir =
        eval_cond_helper(ir_context, ir_list);
    stack.pop_back();
    return branch_ir;
  } catch (const std::exception& e) {
    stack.pop_back();
    throw e;
  }
}

compiler::ir::Operand* compiler::Item_expr::eval_runtime(
    compiler::ir::IRContext* const ir_context,
    std::vector<compiler::ir::IR>& ir_list) const {
  stack.push_back(
      static_cast<compiler::Item*>(const_cast<compiler::Item_expr*>(this)));
  try {
    compiler::ir::Operand* const operand =
        eval_runtime_helper(ir_context, ir_list);
    stack.pop_back();
    return operand;
  } catch (const std::exception& e) {
    stack.pop_back();
    throw e;
  }
}

compiler::ir::Operand* compiler::Item_expr::eval_runtime(
    compiler::ir::IRContext* const ir_context) const {
  stack.push_back(
      static_cast<compiler::Item*>(const_cast<compiler::Item_expr*>(this)));
  try {
    compiler::ir::Operand* const operand = eval_runtime_helper(ir_context);
    stack.pop_back();
    return operand;
  } catch (const std::exception& e) {
    stack.pop_back();
    throw e;
  }
}

compiler::ir::Operand* compiler::Item_expr_binary::eval_runtime_helper(
    compiler::ir::IRContext* const ir_context) const {
  // TODO:: Type check + new node creation.
  // There could multiple situations:
  // 1. numeric + numeric;
  // 2. numeric + pointer;
  // 3. pointer + pointer;
  // 4. Array cannot be added to any other types.
  compiler::ir::Operand* const expr_left = lhs->eval_runtime(ir_context);
  compiler::ir::Operand* const expr_right = rhs->eval_runtime(ir_context);
  // Check type compatibility.

  if (!compiler::ir::check_valid_binary(expr_left, expr_right)) {
    throw compiler::unsupported_operation("Type incompatible!");
  }

  switch (type) {
    case compiler::binary_type::ADD_TYPE: {
      const double lhs =
          compiler::ir::convert_from_string(expr_left->get_value());
      const double rhs =
          compiler::ir::convert_from_string(expr_right->get_value());
      const double res = lhs + rhs;
      const compiler::ir::var_type type =
          compiler::ir::get_type_priority(expr_left->get_type(),
                                          expr_right->get_type())
              ? expr_left->get_type()
              : expr_right->get_type();
      return new compiler::ir::Operand(
          type, "", compiler::ir::convert_from_double(res), false, false);
    }

    // TODO: Implement other types. Maybe we can add a utility function?
    default:
      throw compiler::unsupported_operation("Unknown binary type!");
  }
}

compiler::ir::BranchIR compiler::Item_expr_binary::eval_cond_helper(
    compiler::ir::IRContext* const ir_context,
    std::vector<compiler::ir::IR>& ir_list) const

{
  if (opt_level > 0) {
    auto cond_res = eval_runtime(ir_context);
    bool flag = std::stoi(cond_res->get_value(), 0, 16);

    if (flag == true) {
      return std::make_pair(ir::op_type::JMP, ir::op_type::NOP);
    } else {
      return std::make_pair(ir::op_type::NOP, ir::op_type::JMP);
    }
  } else {
    // TODO: Implement non-optimized version.
  }
}

compiler::ir::Operand* compiler::Item_expr_binary::eval_runtime_helper(
    compiler::ir::IRContext* const ir_context,
    std::vector<compiler::ir::IR>& ir_list) const {
  // First check the optimization level. If so, we calculate the expression at
  // runtime.
  if (opt_level > 0) {
    try {
      return eval_runtime_helper(ir_context);
    } catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
      throw e;
    }
  } else {
  }
}

compiler::ir::Operand* compiler::Item_expr_unary::eval_runtime_helper(
    compiler::ir::IRContext* const ir_context,
    std::vector<compiler::ir::IR>& ir_list) const {
  // TODO: implement this.
  return nullptr;
}

compiler::ir::Operand* compiler::Item_expr_unary::eval_runtime_helper(
    compiler::ir::IRContext* const ir_context) const {
  // TODO: implement this.
  return nullptr;
}

compiler::ir::BranchIR compiler::Item_expr_unary::eval_cond_helper(
    compiler::ir::IRContext* const ir_context,
    std::vector<compiler::ir::IR>& ir_list) const {
  if (opt_level > 0) {
    auto cond_res = eval_runtime(ir_context);
    bool flag = std::stoi(cond_res->get_value(), 0, 16);

    if (flag == true) {
      return std::make_pair(ir::op_type::JMP, ir::op_type::NOP);
    } else {
      return std::make_pair(ir::op_type::NOP, ir::op_type::JMP);
    }
  } else {
    // TODO: Implement non-optimized version.
  }
}

compiler::ir::Operand* compiler::Item_expr_comma::eval_runtime_helper(
    compiler::ir::IRContext* const ir_context,
    std::vector<compiler::ir::IR>& ir_list) const {
  compiler::ir::Operand* ans = nullptr;
  for (compiler::Item_expr* const expr : expressions) {
    ans = expr->eval_runtime(ir_context, ir_list);
  }
  return ans;
}