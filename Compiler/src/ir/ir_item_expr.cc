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
#include <common/termcolor.hh>
#include <frontend/nodes/item_expr.hh>

// TODO: Type check unary / binary expressions.

extern uint32_t opt_level;
extern compiler::NodeStack stack;

compiler::ir::BranchIR compiler::Item_expr::eval_cond_helper(
    compiler::ir::IRContext* const ir_context,
    std::vector<compiler::ir::IR>& ir_list) const {
  compiler::ir::BranchIR branch_ir;
  ir_list.emplace_back(
      compiler::ir::op_type::CMP, eval_runtime_helper(ir_context, ir_list),
      new compiler::ir::Operand(ir::var_type::i32, "", "0", false, false));

  // Set jne and jeq.
  branch_ir.first = compiler::ir::op_type::JNE;
  branch_ir.second = compiler::ir::op_type::JEQ;
  return branch_ir;
}

// If this virtual function of some expression is not implemented, an error will
// be thrown.
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
    std::cerr << termcolor::red << termcolor::bold << lineno << ": " << e.what()
              << termcolor::reset << std::endl;
    stack.pop_back();
    exit(1);
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
    std::cerr << termcolor::red << termcolor::bold << lineno << ": " << e.what()
              << termcolor::reset << std::endl;
    stack.pop_back();
    exit(1);
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
    std::cerr << termcolor::red << termcolor::bold << lineno << ": " << e.what()
              << termcolor::reset << std::endl;
    stack.pop_back();
    exit(1);
  }
}

compiler::ir::Operand* compiler::Item_expr_binary::eval_runtime_helper(
    compiler::ir::IRContext* const ir_context) const {
  // TODO:: Type check + new node creation.
  // There could multiple situations:
  // 1. numeric + numeric;
  // 2. numeric + pointer;
  // 3. pointer + pointer;
  // 4. Array cannot be added to any other types, unless it is access through
  // indexing.
  compiler::ir::Operand* const expr_left = lhs->eval_runtime(ir_context);
  compiler::ir::Operand* const expr_right = rhs->eval_runtime(ir_context);
  // Check type compatibility.

  if (!compiler::ir::check_valid_binary(expr_left, expr_right)) {
    throw compiler::unsupported_operation(
        "Error: Operand types are incompatible!");
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


compiler::ir::Operand* compiler::Item_expr_binary::eval_runtime_helper(
    compiler::ir::IRContext* const ir_context,
    std::vector<compiler::ir::IR>& ir_list) const {
  // First check the optimization level. If so, we calculate the expression at
  // runtime.
  if (opt_level > 0) {
    try {
      return eval_runtime_helper(ir_context);
    } catch (const std::exception& e) {
      std::cerr << termcolor::red << termcolor::bold << e.what()
                << termcolor::reset << std::endl;
      exit(1);
    }
    // Generate IR.
  } else {
    ir::Operand* const dst = new ir::Operand(
        ir::local_sign +
        std::to_string(ir_context->get_symbol_table()->get_available_id()));
    ir::Operand* left = nullptr;
    ir::Operand* right = nullptr;

    if (type != LAND_TYPE && type != LOR_TYPE) {
      if (opt_level > 0) {
        left = lhs->eval_runtime(ir_context);
        right = rhs->eval_runtime(ir_context);
      } else {
        left = lhs->eval_runtime(ir_context, ir_list);
        right = rhs->eval_runtime(ir_context, ir_list);
      }
    }

    switch (type) {
      // TODO: Implement implicit type convertion.
      case ADD_TYPE: {
        ir_list.emplace_back(ir::op_type::IADD, dst, left, right);
        break;
      }
      case SUB_TYPE: {
        ir_list.emplace_back(ir::op_type::ISUB, dst, left, right);
        break;
      }
      case MUL_TYPE: {
        // Can do optimization.
        ir_list.emplace_back(ir::op_type::IMUL, dst, left, right);
        break;
      }
      case DIV_TYPE: {
        // Can do optimization.
        ir_list.emplace_back(ir::op_type::IDIV, dst, left, right);
        break;
      }
      case MOD_TYPE: {
        // a mod b => a - ceil(a / b) * b.
        ir_list.emplace_back(ir::op_type::IMOD, dst, left, right);
        break;
      }
      case NEQ_TYPE: {
        ir_list.emplace_back(ir::op_type::CMP, nullptr, left, right);
        ir_list.emplace_back(ir::op_type::MOVNE, dst, OPERAND_VALUE("1"),
                             OPERAND_VALUE("0"));
        break;
      }
      case EQ_TYPE: {
        ir_list.emplace_back(ir::op_type::CMP, nullptr, left, right);
        ir_list.emplace_back(ir::op_type::MOVEQ, dst, OPERAND_VALUE("1"),
                             OPERAND_VALUE("0"));
        break;
      }
      case G_TYPE: {
        ir_list.emplace_back(ir::op_type::CMP, nullptr, left, right);
        ir_list.emplace_back(ir::op_type::MOVGT, dst, OPERAND_VALUE("1"),
                             OPERAND_VALUE("0"));
        break;
      }
      case L_TYPE: {
        ir_list.emplace_back(ir::op_type::CMP, nullptr, left, right);
        ir_list.emplace_back(ir::op_type::MOVLT, dst, OPERAND_VALUE("1"),
                             OPERAND_VALUE("0"));
        break;
      }
      case LE_TYPE: {
        ir_list.emplace_back(ir::op_type::CMP, nullptr, left, right);
        ir_list.emplace_back(ir::op_type::MOVLE, dst, OPERAND_VALUE("1"),
                             OPERAND_VALUE("0"));
        break;
      }
      case GE_TYPE: {
        ir_list.emplace_back(ir::op_type::CMP, nullptr, left, right);
        ir_list.emplace_back(ir::op_type::MOVGE, dst, OPERAND_VALUE("1"),
                             OPERAND_VALUE("0"));
        break;
      }
      case BITAND_TYPE: {
        ir_list.emplace_back(ir::op_type::BAND, dst, left, right);
        break;
      }
      case BITOR_TYPE: {
        ir_list.emplace_back(ir::op_type::BOR, dst, left, right);
        break;
      }
      case BITXOR_TYPE: {
        ir_list.emplace_back(ir::op_type::BXOR, dst, left, right);
        break;
      }

      default:
        throw compiler::unsupported_operation(
            "Error: Unrecognized binary type!");
    }
    return dst;
  }
}

compiler::ir::Operand* compiler::Item_expr_unary::eval_runtime_helper(
    compiler::ir::IRContext* const ir_context,
    std::vector<compiler::ir::IR>& ir_list) const {
  if (opt_level > 0) {
    return eval_runtime_helper(ir_context);
  } else {
    // Create a dst operand.
    ir::Operand* const dst = new ir::Operand(
        ir::local_sign +
        std::to_string(ir_context->get_symbol_table()->get_available_id()));

    switch (type) {
      case LNOT_TYPE: {
        ir_list.emplace_back(ir::op_type::CMP, nullptr, OPERAND_VALUE("1"),
                             expr->eval_runtime(ir_context, ir_list));
        ir_list.emplace_back(ir::op_type::MOVNE, dst, OPERAND_VALUE("1"),
                             OPERAND_VALUE("1"));
        break;
      }
      case BITNEG_TYPE: {
        ir_list.emplace_back(ir::op_type::BNEG, dst,
                             expr->eval_runtime(ir_context, ir_list));
        break;
      }
      case UMINUS_TYPE: {
        ir_list.emplace_back(ir::op_type::ISUB, dst, OPERAND_VALUE("1"),
                             expr->eval_runtime(ir_context, ir_list));
        break;
      }
      case UADD_TYPE: {
        // No need to generate any IR for it.
        break;
      }
      default: {
        throw compiler::fatal_error("Error: Unknown Unary expression type!");
      }
    }
    return dst;
  }
}

compiler::ir::Operand* compiler::Item_expr_unary::eval_runtime_helper(
    compiler::ir::IRContext* const ir_context) const {
  // TODO: implement this. The same as the type "ADD".
  return nullptr;
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

compiler::ir::Operand* compiler::Item_expr_comma::eval_runtime_helper(
    compiler::ir::IRContext* const ir_context) const {
  compiler::ir::Operand* ans = nullptr;
  for (compiler::Item_expr* const expr : expressions) {
    ans = expr->eval_runtime(ir_context);
  }
  return ans;
}