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
#include <cstring>
#include <frontend/nodes/item_literal.hh>
#include <frontend/nodes/item_stmt.hh>
#include <sstream>

compiler::ir::Operand* compiler::Item_stmt::eval_runtime_helper(
    compiler::ir::IRContext* const ir_context,
    std::vector<compiler::ir::IR>& ir_list) const {
  generate_ir(ir_context, ir_list);
  return new compiler::ir::Operand();
}

void compiler::Item_block::generate_ir_helper(
    compiler::ir::IRContext* const ir_context,
    std::vector<compiler::ir::IR>& ir_list) const {
  try {
    ir_context->enter_scope();
    for (Item_stmt* const statement : statements) {
      statement->generate_ir(ir_context, ir_list);
    }
    ir_context->leave_scope();
  } catch (const compiler::fatal_error& e) {
    // Scope is invalid.
    std::cerr << "FATAL ERROR: " << e.what() << std::endl;
    std::terminate();
  }
}

void compiler::Item_stmt_void::generate_ir_helper(
    compiler::ir::IRContext* const ir_context,
    std::vector<compiler::ir::IR>& ir_list) const {
  return;
}

void compiler::Item_stmt_eif::generate_ir_helper(
    compiler::ir::IRContext* const ir_context,
    std::vector<compiler::ir::IR>& ir_list) const {
  try {
    ir_context->enter_scope();
    // Get the id of current scope.
    const uint32_t scope_uuid_cur =
        (uint32_t)(ir_context->get_symbol_table()->get_top_scope_uuid());
    const compiler::ir::BranchIR branch_ir =
        condition->eval_cond(ir_context, ir_list);

    // The if_branch is taken. Evaluated at runtime.
    if (branch_ir.first == compiler::ir::JMP) {
      if_branch->generate_ir(ir_context, ir_list);
      return;
    } else if (branch_ir.second == compiler::ir::JMP) {
      else_branch->generate_ir(ir_context, ir_list);
      return;
    }

    // If branches cannot be evaluated at runtime, we should create IRs for each
    // branch.
    std::ostringstream oss;
    oss << ".L." << scope_uuid_cur << "_eif";
    ir_list.emplace_back(branch_ir.second, oss.str());
    oss.str("");
    oss.flush();

    std::vector<compiler::ir::IR> ir_if, ir_else;
    compiler::ir::IRContext ir_context_if, ir_context_else;

    ir_context_if.enter_scope();
    if_branch->generate_ir(&ir_context_if, ir_if);
    ir_context_if.leave_scope();

    ir_context_else.enter_scope();
    else_branch->generate_ir(&ir_context_else, ir_else);
    ir_context_else.leave_scope();

    std::vector<compiler::ir::IR> ir_end;
    oss << ".L." << scope_uuid_cur << "_endif";
    ir_list.emplace_back(branch_ir.second, oss.str());
    ir_end.emplace_back(compiler::ir::op_type::LBL, oss.str());

    // The actual symbol table is wrapped twice.
    const auto& symbol_table =
        ir_context_if.get_symbol_table()->get_symbol_table();
    // Traverse the symbol table.
    for (auto iter = symbol_table.cend(); iter != symbol_table.cbegin();
         iter--) {
      compiler::symbol_table_type* const cur_table = (*iter)->get_block();

      for (auto& entry : *cur_table) {
        const std::string name = entry.second->get_name();
        // TODO: FIND VARIABLE.
      }
    }

    ir_context->leave_scope();
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    // FIXME: Determine which exception should be caught.
  }
}

void compiler::Item_stmt_assign::generate_ir_helper(
    compiler::ir::IRContext* const ir_context,
    std::vector<compiler::ir::IR>& ir_list) const {
  // We need to check the assigner and the assignee.
  const Item_ident::ident_type type = identifier->get_ident_type();

  // Case 1: This identifier is a variable.
  if (Item_ident::ident_type::VARIABLE == type) {
  } else if (Item_ident::ident_type::ARRAY == type) {
  }
}

void compiler::Item_stmt_while::generate_ir_helper(
    compiler::ir::IRContext* const ir_context,
    std::vector<compiler::ir::IR>& ir_list) const {
  try {
    // Enter a scope.
    ir_context->enter_scope();
    // Create a loop label.
    const uint32_t scope_id =
        ir_context->get_symbol_table()->get_top_scope_uuid();
    ir_context->add_loop_label(std::to_string(scope_id));

    // Step 1: Copy the previous context.
    const uint32_t size = sizeof(*ir_context);
    unsigned char* backup = new unsigned char[size];
    memcpy(backup, static_cast<void*>(ir_context), size);
    compiler::ir::IRContext* const ir_context_conditional =
        reinterpret_cast<compiler::ir::IRContext*>(backup);

    // Step 2: Create condition.
    std::vector<compiler::ir::IR> ir_conditional;
    ir_conditional.emplace_back(
        compiler::ir::op_type::LBL,
        ".L.LOOP_" + ir_context->get_top_loop_label() + "_BEGIN");
    const compiler::ir::BranchIR branch_ir =
        condition->eval_cond(ir_context_conditional, ir_conditional);

    // TODO: Step 3: DO Block...

    ir_context->leave_scope();
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}

void compiler::Item_stmt_postfix::generate_ir_helper(
    compiler::ir::IRContext* const ir_context,
    std::vector<compiler::ir::IR>& ir_list) const {
  // number ++ => number = number + 1;
  compiler::Item_literal* const number =
      new compiler::Item_literal_int(lineno, 1);
  compiler::Item_expr* const expr =
      new compiler::Item_expr_binary(lineno, type, identifier, number);
  compiler::Item_stmt* const assign =
      new compiler::Item_stmt_assign(lineno, identifier, expr);
  assign->generate_ir(ir_context, ir_list);

  // Cleanup
  delete assign;
  delete expr;
  delete number;
}

compiler::ir::Operand* compiler::Item_stmt_postfix::eval_runtime_helper(
    compiler::ir::IRContext* const ir_context,
    std::vector<compiler::ir::IR>& ir_list) const {
  compiler::Symbol* const sym =
      ir_context->get_symbol_table()->find_symbol(identifier->get_name());
  compiler::Item_literal* const number =
      new compiler::Item_literal_int(lineno, 1);
  compiler::Item_expr* const expr =
      new compiler::Item_expr_binary(lineno, type, identifier, number);
  compiler::Item_stmt* const assign =
      new compiler::Item_stmt_assign(lineno, identifier, expr);
  assign->eval_runtime(ir_context, ir_list);
  return new ir::Operand(sym->get_name());
}

compiler::ir::Operand* compiler::Item_stmt_postfix::eval_runtime_helper(
    compiler::ir::IRContext* const ir_context) const {
  if (identifier->get_ident_type() != compiler::Item_ident::ARRAY) {
    throw compiler::unsupported_operation("Local variable is forbiddent.");
  }
  ir::Operand* const res = identifier->eval_runtime(ir_context);
  compiler::Symbol* const sym =
      ir_context->get_symbol_table()->find_symbol(identifier->get_name());

  if (sym->get_name()[0] == '%' || sym->get_type() == ARRAY_TYPE) {
    throw compiler::unsupported_operation("Local variable is forbiddent.");
  }
  sym->set_name(
      "%" +
      std::to_string(ir_context->get_symbol_table()->get_top_scope_uuid()));

  // TODO: insert const assign.
  return res;
}