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
#include <common/utils.hh>
#include <cstring>
#include <frontend/nodes/item_literal.hh>
#include <frontend/nodes/item_stmt.hh>
#include <sstream>

extern uint32_t opt_level;

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
    std::cerr << termcolor::red << termcolor::bold
              << "FATAL ERROR: " << e.what() << std::endl;
    exit(1);
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
    }
    if (branch_ir.second == compiler::ir::JMP) {
      else_branch->generate_ir(ir_context, ir_list);
      return;
    }

    // If branches cannot be evaluated at runtime, we should create IRs for each
    // branch.
    ir_list.emplace_back(
        branch_ir.second,
        compiler::concatenate(".LBB", scope_uuid_cur, "_ELSE"));
    ir_list.emplace_back(ir::op_type::JMP,
                         compiler::concatenate(".LBB", scope_uuid_cur, "_IF"));

    // Generate a label for if branch.
    ir_list.emplace_back(ir::op_type::LBL,
                         compiler::concatenate(".LBB", scope_uuid_cur, "_IF:"));

    std::vector<compiler::ir::IR> ir_if, ir_else;
    compiler::ir::IRContext ir_context_if(*ir_context);
    compiler::ir::IRContext ir_context_else(*ir_context);

    ir_context_if.enter_scope();
    if_branch->generate_ir(&ir_context_if, ir_if);
    ir_context_if.leave_scope();

    ir_context_else.get_symbol_table()->set_available_id(
        ir_context_if.get_symbol_table()->get_available_id());
    ir_context_else.enter_scope();
    else_branch->generate_ir(&ir_context_else, ir_else);
    ir_context_else.leave_scope();

    ir_context->get_symbol_table()->set_available_id(
        ir_context_else.get_symbol_table()->get_available_id());

    std::vector<compiler::ir::IR> ir_list_end;
    ir_list_end.emplace_back(
        compiler::ir::op_type::LBL,
        compiler::concatenate(".LBB", scope_uuid_cur, "_END_IF:"));

    const auto symbol_table_if =
        ir_context_if.get_symbol_table()->get_symbol_table();

    for (uint32_t i = 0; i < symbol_table_if.size(); i++) {
      const auto symbol_table =
          ir_context_else.get_symbol_table()->get_symbol_table()[i];
      for (auto symbol_pair : *(symbol_table_if[i]->get_block())) {
        // Check if this symbol is related to the else block.
        const auto symbol_else =
            symbol_table->get_block()->find(symbol_pair.first);

        if (/*symbol_else != symbol_table->get_block()->end() &&*/
            symbol_pair.second->get_name().compare(
                symbol_else->second->get_name()) != 0) {
          // Get name from the previous context.
          compiler::Symbol* const symbol =
              ir_context->get_symbol_table()->find_symbol(symbol_pair.first);

          if (symbol->get_is_pointer()) {
            throw compiler::fatal_error("PHI MOVE WITH POINTER TYPE.");
          }

          if (symbol->get_name()[0] == ir::local_sign[0]) {
            symbol->set_name(
                ir::local_sign +
                std::to_string(
                    ir_context->get_symbol_table()->get_available_id()));
          }

          // Set phi blocks.
          ir_if.emplace_back(ir::op_type::PHI,
                             new ir::Operand(symbol->get_name()),
                             new ir::Operand(symbol_pair.second->get_name()));
          ir_if.back().set_phi_block(ir_list_end.begin());
          ir_else.emplace_back(
              ir::op_type::PHI, new ir::Operand(symbol->get_name()),
              new ir::Operand(symbol_else->second->get_name()));
          ir_else.back().set_phi_block(ir_list_end.begin());
        }
      }
    }

    // Append to the ir_list.
    compiler::insert_with_move(ir_list, ir_if);
    if (ir_else.empty() == false) {
      ir_list.emplace_back(ir::op_type::JMP,
                           new ir::Operand(compiler::concatenate(
                               ".LBB", scope_uuid_cur, "_END_IF")));
    }
    ir_list.emplace_back(
        ir::op_type::LBL,
        compiler::concatenate(".LBB", scope_uuid_cur, "_ELSE:"));

    compiler::insert_with_move(ir_list, ir_else);
    ir_list.emplace_back(
        ir::op_type::JMP,
        compiler::concatenate(".LBB", scope_uuid_cur, "_END_IF:"));
    compiler::insert_with_move(ir_list, ir_list_end);

    ir_context->leave_scope();
  } catch (const std::exception& e) {
    std::cerr << termcolor::red << termcolor::bold << lineno << ": " << e.what()
              << termcolor::reset << std::endl;
  }
}

compiler::ir::Operand* compiler::Item_stmt_assign::eval_runtime_helper(
    compiler::ir::IRContext* const ir_context) const {
  try {
    // Cannot evaluate an array / global symbol.
    if (identifier->get_ident_type() ==
        compiler::Item_ident::ident_type::ARRAY) {
      throw compiler::unsupported_operation(
          "Error: Cannot evaluate an array type!");
    }
    compiler::Symbol* const symbol =
        ir_context->get_symbol_table()->find_symbol(identifier->get_name());
    if (symbol->get_name()[0] == ir::global_sign[0]) {
      throw compiler::unsupported_operation(
          "Error: Cannot evaluate a global symbol!");
    } else if (symbol->get_type() == compiler::symbol_type::ARRAY_TYPE) {
      throw compiler::unsupported_operation(
          "Error: Cannot evaluate an array type!");
    }

    ir::Operand* result = expression->eval_runtime(ir_context);
    compiler::Symbol_const* symbol_const = new compiler::Symbol_const(
        result->get_value(), compiler::symbol_type::VAR_TYPE,
        result->get_value(), false);
    const std::string symbol_name =
        ir::local_sign +
        std::to_string(ir_context->get_symbol_table()->get_available_id());
    symbol->set_name(symbol_name);
    ir_context->get_symbol_table()->assign_const(symbol_name, symbol_const);

    return result;
  } catch (const std::exception& e) {
    std::cerr << termcolor::red << termcolor::bold << e.what()
              << termcolor::reset << std::endl;
    exit(1);
  }
}

compiler::ir::Operand* compiler::Item_stmt_assign::eval_runtime_helper(
    compiler::ir::IRContext* const ir_context,
    std::vector<compiler::ir::IR>& ir_list) const {
  generate_ir(ir_context, ir_list);

  if (identifier->get_ident_type() == compiler::Item_ident::ident_type::ARRAY) {
    if (ir_list.back().get_op_type() != ir::op_type::STR) {
      throw compiler::fatal_error("Error: Unknown error!");
    }

  } else {
    if (ir_list.back().get_dst()->get_is_var() == false) {
      throw compiler::fatal_error("Error: Unknown error!");
    }
  }
  return ir_list.back().get_dst();
}

void compiler::Item_stmt_assign::generate_ir_helper(
    compiler::ir::IRContext* const ir_context,
    std::vector<compiler::ir::IR>& ir_list) const {
  // We need to check the assigner and the assignee.
  const Item_ident::ident_type type = identifier->get_ident_type();

  // Case 1: This identifier is a variable.
  if (Item_ident::ident_type::VARIABLE == type) {
    ir::Operand* const rhs = expression->eval_runtime(ir_context, ir_list);
    compiler::Symbol* const symbol =
        ir_context->get_symbol_table()->find_symbol(identifier->get_name());

    if (symbol->get_is_pointer() == true) {
      throw compiler::unsupported_operation(
          "Error: Cannot assign an expression to a pointer-like object!");
    }
    const std::string name = rhs->get_identifier();
    if (rhs->get_is_var() == true) {
      // Local <= Variable. ok. SSA update symbol name.
      if (name[0] == '%' &&
          (symbol->get_name()[0] == ir::local_sign[0] ||
           symbol->get_name().substr(0, 4) == ir::arg_sign) &&
          symbol->get_name()[0] != ir::global_sign[0]) {
        if (ir_context->is_loop_context()) {
        } else {
          symbol->set_name(name);
        }
      }
    } else if (rhs->get_identifier().front() == '@') /* Global variable. */ {
      symbol->set_name(rhs->get_identifier());
      ir_list.emplace_back(ir::op_type::MOV,
                           new ir::Operand(rhs->get_identifier()));
    } else /* Normal const expression. */ {
      symbol->set_name(
          ir::local_sign +
          std::to_string(ir_context->get_symbol_table()->get_available_id()));
      ir_list.emplace_back(
          ir::op_type::MOV,
          new ir::Operand(
              ir::local_sign +
              std::to_string(
                  ir_context->get_symbol_table()->get_available_id())),
          rhs);

      if (opt_level > 0) {
        compiler::Symbol_const* const assign = new compiler::Symbol_const(
            symbol->get_name(), compiler::symbol_type::VAR_TYPE, "");
        ir_context->get_symbol_table()->assign_const(identifier->get_name(),
                                                     assign);
      }
    }
  } else if (Item_ident::ident_type::ARRAY == type) {
    // Get result.
    ir::Operand* const res = identifier->eval_runtime(ir_context, ir_list);
    throw compiler::unimplemented_error("Sorry, this is not yet supported:(");
  }
}

// FIXME: phi move does not work.
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
    compiler::ir::IRContext* ir_context_backup =
        new compiler::ir::IRContext(*ir_context);
    std::vector<ir::IR> ir_list_backup;

    // Step 2: Create condition.
    compiler::ir::IRContext* ir_context_condition =
        new compiler::ir::IRContext(*ir_context_backup);
    std::vector<compiler::ir::IR> ir_list_condition;
    ir_list_condition.emplace_back(
        compiler::ir::op_type::LBL,
        ".LB" + ir_context->get_top_loop_label() + "_LOOP_BEGIN:");

    compiler::ir::BranchIR branch_ir =
        condition->eval_cond(ir_context_condition, ir_list_condition);

    // Step 3: Set up jump instruction.
    std::vector<compiler::ir::IR> ir_list_jump;
    ir_list_jump.emplace_back(
        branch_ir.second, compiler::concatenate(".LB", scope_id, ".LOOP_END"));

    // Step 4: Create the do body, and then generate ir from it.
    ir::IRContext* ir_context_do = new ir::IRContext(*ir_context_condition);
    std::vector<ir::IR> ir_list_do;
    ir_context_do->continue_symbol.push({});
    ir_context_do->break_symbol.push({});
    ir_context_do->continue_phi_block.push({});
    ir_context_do->break_phi_block.push({});
    statement->generate_ir(ir_context_do, ir_list_do);
    ir_context_do->continue_symbol.top().emplace_back(
        *ir_context_do->get_symbol_table());

    // Step 5: Real do body.
    ir::IRContext* ir_context_do_real =
        new ir::IRContext(*ir_context_condition);
    std::vector<ir::IR> ir_list_do_real;
    ir_context_do_real->continue_symbol.push({});
    ir_context_do_real->break_symbol.push({});
    ir_context_do_real->continue_phi_block.push({});
    ir_context_do_real->break_phi_block.push({});
    // Handle phi move.
    compiler::handle_phi_move(ir_context_do, ir_context_do, ir_context_do_real);
    compiler::handle_phi_move(ir_context_condition, ir_context_do,
                              ir_context_do_real);
    // Insert label.
    ir_list_do_real.emplace_back(
        ir::op_type::LBL,
        ".LB" + ir_context->get_top_loop_label() + "_LOOP_BODY:");
    statement->generate_ir(ir_context_do_real, ir_list_do_real);
    // Insert phi blocks.
    for (auto& phi_block : ir_context_do_real->continue_phi_block.top()) {
      auto table = ir_context_do_real->get_symbol_table()
                       ->get_symbol_table()[phi_block.first.first]
                       ->get_block();
      const std::string symbol_name =
          table->find(phi_block.first.second)->second->get_name();
      ir_list_do_real.emplace_back(ir::op_type::PHI,
                                   new ir::Operand(phi_block.second),
                                   new ir::Operand(symbol_name));
    }

    // Step 6: phi move with break and continue.
    compiler::handle_phi_move(ir_context_do_real, true);
    compiler::handle_phi_move(ir_context_do_real, false);

    // Step7: Pop them out.
    ir_context_do_real->break_phi_block.pop();
    ir_context_do_real->continue_phi_block.pop();
    ir_context_do_real->break_symbol.pop();
    ir_context_do_real->continue_symbol.pop();

    // Step 8: Continue statement.
    ir::IRContext* ir_context_continue = new ir::IRContext(*ir_context_do_real);
    std::vector<ir::IR> ir_list_continue;
    ir_list_continue.emplace_back(
        ir::op_type::JMP,
        ".LB" + ir_context->get_top_loop_label() + "_LOOP_CONTINUE");
    ir_list_condition.clear();
    ir_list_condition.emplace_back(
        ir::op_type::LBL,
        ".LB" + ir_context->get_top_loop_label() + "_LOOP_BEGIN:");
    // Handle phi move.
    auto symbol_table =
        ir_context_backup->get_symbol_table()->get_symbol_table();
    for (uint32_t i = 0; i < symbol_table.size(); i++) {
      for (auto symbol_prev : *symbol_table[i]->get_block()) {
        auto symbol_table_continue = ir_context_continue->get_symbol_table()
                                         ->get_symbol_table()[i]
                                         ->get_block();

        auto symbol_continue = symbol_table_continue->find(symbol_prev.first);
        if (symbol_continue == symbol_table_continue->end()) {
          throw compiler::fatal_error(
              "Error: Unknown error when generating phi blocks!");
        }
        if (symbol_continue->second->get_name() !=
            symbol_prev.second->get_name()) {
          const std::string symbol_name_new =
              ir::local_sign +
              std::to_string(
                  ir_context_backup->get_symbol_table()->get_available_id());
          ir_list_backup.emplace_back(
              ir::op_type::PHI, new ir::Operand(symbol_name_new),
              new ir::Operand(symbol_prev.second->get_name()));
          ir_list_backup.back().set_phi_block(ir_list_condition.begin());
          ir_list_continue.emplace_back(
              ir::op_type::PHI, new ir::Operand(symbol_name_new),
              new ir::Operand(symbol_continue->second->get_name()));
          auto symbol_table_backup = ir_context_backup->get_symbol_table()
                                         ->get_symbol_table()[i]
                                         ->get_block();
          symbol_table_backup->find(symbol_prev.first)
              ->second->set_name(symbol_name_new);
          ir_context_backup->add_loop_var(symbol_name_new);
        }
      }
    }

    ir_list_continue.emplace_back(
        ir::op_type::JMP,
        ".LB" + ir_context->get_top_loop_label() + "_LOOP_BEGIN");
    ir_list_continue.emplace_back(
        ir::op_type::LBL,
        ".LB" + ir_context->get_top_loop_label() + "_LOOP_END:");

    //============================= END PRE-PREPARATION
    //============================= BEGIN REAL WHILE STATEMENT
    // Step 1: WHILE CONDITION.
    delete ir_context_condition;
    ir_context_condition = new ir::IRContext(*ir_context_backup);
    branch_ir = condition->eval_cond(ir_context_condition, ir_list_condition);

    // Step 2: JUMP LABEL.
    ir_list_jump.clear();
    ir_list_jump.emplace_back(
        branch_ir.second,
        ".LB" + ir_context->get_top_loop_label() + "_LOOP_END");

    // Step 3: DO BODY.
    delete ir_context_do;
    ir_context_do = new ir::IRContext(*ir_context_condition);
    ir_list_do.clear();
    ir_context_do->continue_symbol.push({});
    ir_context_do->break_symbol.push({});
    ir_context_do->continue_phi_block.push({});
    ir_context_do->break_phi_block.push({});
    statement->generate_ir(ir_context_do, ir_list_do);
    ir_context_do->continue_symbol.top().emplace_back(
        *ir_context_do->get_symbol_table());

    // Step 4: REAL DO.
    delete ir_context_do_real;
    ir_context_do_real = new ir::IRContext(*ir_context_condition);
    ir_list_do_real.clear();
    ir_list_continue.clear();
    ir_list_continue.emplace_back(ir::op_type::NOP);
    std::vector<ir::IR> ir_list_end;
    ir_list_end.emplace_back(
        ir::op_type::LBL,
        ".LB" + ir_context->get_top_loop_label() + "_LOOP_END:");
    ir_context_do_real->continue_symbol.push({});
    ir_context_do_real->break_symbol.push({});
    ir_context_do_real->continue_phi_block.push({});
    ir_context_do_real->break_phi_block.push({});
    compiler::handle_phi_move(ir_context_do, ir_context_do, ir_context_do_real);
    compiler::handle_phi_move(ir_context_condition, ir_context_do,
                              ir_context_do_real);

    ir_list_do_real.emplace_back(
        ir::op_type::LBL,
        ".LB" + ir_context->get_top_loop_label() + "_LOOP_BODY:");
    statement->generate_ir(ir_context_do_real, ir_list_do_real);
    compiler::handle_phi_move(ir_context_do_real, true);
    compiler::handle_phi_move(ir_context_do_real, false);

    ir_context_do_real->break_phi_block.pop();
    ir_context_do_real->continue_phi_block.pop();
    ir_context_do_real->break_symbol.pop();
    ir_context_do_real->continue_symbol.pop();

    // Step 4: CONTINUE.
    delete ir_context_continue;
    ir_context_continue = new ir::IRContext(*ir_context_do_real);
    ir_list_continue.emplace_back(
        ir::op_type::LBL,
        new ir::Operand(".LB" + ir_context->get_top_loop_label() +
                        "_LOOP_CONTINUE:"));

    for (uint32_t i = 0; i < symbol_table.size(); i++) {
      for (auto symbol_prev : *symbol_table[i]->get_block()) {
        auto symbol_table_continue = ir_context_continue->get_symbol_table()
                                         ->get_symbol_table()[i]
                                         ->get_block();

        auto symbol_continue = symbol_table_continue->find(symbol_prev.first);
        if (symbol_continue == symbol_table_continue->end()) {
          throw compiler::fatal_error(
              "Error: Unknown error when generating phi blocks!");
        }
        if (symbol_continue->second->get_name() !=
            symbol_prev.second->get_name()) {
          ir_list_continue.emplace_back(
              ir::op_type::PHI, new ir::Operand(symbol_prev.second->get_name()),
              new ir::Operand(symbol_continue->second->get_name()));
          ir_list_continue.back().set_phi_block(ir_list_condition.begin());
        }
      }
    }

    ir_list_continue.emplace_back(
        ir::op_type::JMP,
        ".LB" + ir_context->get_top_loop_label() + "_LOOP_BEGIN");

    // TODO: Optimize loop.

    // Append to the ir_list.
    compiler::insert_with_move(ir_list, ir_list_backup);
    compiler::insert_with_move(ir_list, ir_list_condition);
    compiler::insert_with_move(ir_list, ir_list_jump);
    compiler::insert_with_move(ir_list, ir_list_do_real);
    compiler::insert_with_move(ir_list, ir_list_continue);
    compiler::insert_with_move(ir_list, ir_list_end);

    *ir_context = *ir_context_condition;
    ir_context->get_symbol_table()->set_available_id(
        ir_context_continue->get_symbol_table()->get_available_id());

    // Leave the scope.
    ir_context->pop_loop_var();
    ir_context->leave_scope();
  } catch (const std::exception& e) {
    std::cerr << termcolor::red << termcolor::bold << lineno << ": " << e.what()
              << termcolor::reset << std::endl;
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
    throw compiler::unsupported_operation("Local variable is forbidden.");
  }
  ir::Operand* const res = identifier->eval_runtime(ir_context);
  compiler::Symbol* const sym =
      ir_context->get_symbol_table()->find_symbol(identifier->get_name());

  if (sym->get_name()[0] == '%' || sym->get_type() == ARRAY_TYPE) {
    throw compiler::unsupported_operation("Local variable is forbidden.");
  }
  sym->set_name(
      ir::local_sign +
      std::to_string(ir_context->get_symbol_table()->get_available_id()));

  // TODO: insert const assign.
  return res;
}

void compiler::Item_stmt_return::generate_ir_helper(
    compiler::ir::IRContext* const ir_context,
    std::vector<compiler::ir::IR>& ir_list) const {
  if (expr != nullptr) {
    ir::Operand* const return_value = expr->eval_runtime(ir_context, ir_list);
    ir_list.emplace_back(ir::op_type::RET, return_value);
  } else {
    ir::Operand* const return_value =
        new ir::Operand(ir::var_type::NONE, "", "", false, false);
    ir_list.emplace_back(ir::op_type::RET, return_value);
  }
}

void compiler::Item_stmt_break::generate_ir_helper(
    compiler::ir::IRContext* const ir_context,
    std::vector<compiler::ir::IR>& ir_list) const {
  // Check if the context is correct. Break statement cannot break to a non-loop
  // envionment.
  if (ir_context->is_loop_context() == false) {
    throw compiler::unsupported_operation(
        "Error: Break statement in a non-loop envionment!");
  }

  ir_context->break_symbol.top().emplace_back(*ir_context->get_symbol_table());

  // Handle phi move.
  if (!ir_context->break_phi_block.empty()) {
    for (auto phi_block : ir_context->break_phi_block.top()) {
      // Get the symbol_table.
      auto symbol_table = ir_context->get_symbol_table()
                              ->get_symbol_table()[phi_block.first.first]
                              ->get_block();
      const std::string phi_name =
          symbol_table->find(phi_block.second)->second->get_name();

      ir_list.emplace_back(ir::op_type::MOV, new ir::Operand(phi_block.second),
                           new ir::Operand(phi_name));
    }
  }

  ir_list.emplace_back(ir::op_type::JMP,
                       ".LB" + ir_context->get_top_loop_label() + "_LOOP_END");
}

void compiler::Item_stmt_continue::generate_ir_helper(
    compiler::ir::IRContext* const ir_context,
    std::vector<compiler::ir::IR>& ir_list) const {
  if (ir_context->is_loop_context() == false) {
    throw compiler::unsupported_operation(
        "Error: Continue statement in a non-loop envionment!");
  }

  ir_context->continue_symbol.top().emplace_back(
      *ir_context->get_symbol_table());

  // Handle phi move.
  if (!ir_context->continue_phi_block.empty()) {
    for (auto phi_block : ir_context->continue_phi_block.top()) {
      // Get the symbol_table.
      auto symbol_table = ir_context->get_symbol_table()
                              ->get_symbol_table()[phi_block.first.first]
                              ->get_block();
      const std::string phi_name =
          symbol_table->find(phi_block.second)->second->get_name();

      ir_list.emplace_back(ir::op_type::MOV, new ir::Operand(phi_block.second),
                           new ir::Operand(phi_name));
    }
  }

  ir_list.emplace_back(
      ir::op_type::JMP,
      ".LB" + ir_context->get_top_loop_label() + "_LOOP_CONTINUE");
}

void compiler::handle_phi_move(ir::IRContext* const ir_context_a,
                               ir::IRContext* const ir_context_b,
                               ir::IRContext* const ir_context_dst) {
  const auto table = ir_context_a->get_symbol_table()->get_symbol_table();
  for (uint32_t i = 0; i < table.size(); i++) {
    for (auto symbol : *table[i]->get_block()) {
      auto table_temp = ir_context_b->continue_symbol.top();
      for (uint32_t j = 0; j < table_temp.size(); j++) {
        // Find in temporary symbol table.
        auto this_table = table_temp[j].get_symbol_table()[i]->get_block();
        const std::string symbol_name_cur = symbol.second->get_name();

        auto iter = this_table->find(symbol.first);
        if (iter == this_table->end()) {
          throw compiler::fatal_error(
              "Error: Unkown error when generating phi blocks");
        }
        // Same variable is assigned more than twice.
        if (symbol_name_cur.compare(iter->second->get_name()) != 0) {
          const auto tag_pair = std::make_pair(i, symbol.first);
          const auto phi_pair = std::make_pair(
              tag_pair,
              compiler::concatenate(
                  ir::local_sign,
                  ir_context_dst->get_symbol_table()->get_top_scope_uuid()));
          ir_context_dst->continue_phi_block.top().insert(phi_pair);
          break;
        }
      }
    }
  }
}

void compiler::handle_phi_move(compiler::ir::IRContext* const ir_context,
                               const bool& type) {
  ir::phi_tag phi = (type == true ? ir_context->continue_phi_block.top()
                                  : ir_context->break_phi_block.top());
  for (auto& phi_block : phi) {
    auto table = ir_context->get_symbol_table()
                     ->get_symbol_table()[phi_block.first.first]
                     ->get_block();
    compiler::Symbol* const symbol =
        table->find(phi_block.first.second)->second;
    symbol->set_name(phi_block.second);
  }
}