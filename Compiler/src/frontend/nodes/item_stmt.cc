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
#include <frontend/nodes/item_stmt.hh>
#include <sstream>
#include <string>

compiler::Item_stmt::Item_stmt(const uint32_t& lineno) : Item_expr(lineno) {}

compiler::Item_stmt_assign::Item_stmt_assign(const uint32_t& lineno,
                                             Item_ident* const identifier,
                                             Item_expr* const expression)
    : Item_stmt(lineno), identifier(identifier), expression(expression) {}

compiler::Item_stmt_eval::Item_stmt_eval(const uint32_t& lineno,
                                         Item_expr* const expression)
    : Item_stmt(lineno), expression(expression) {}

compiler::Item_stmt_eif::Item_stmt_eif(const uint32_t& lineno,
                                       Item_expr_cond* const condition,
                                       Item_stmt* const if_branch,
                                       Item_stmt* const else_branch)
    : Item_stmt(lineno),
      condition(condition),
      if_branch(if_branch),
      else_branch(else_branch) {}

compiler::Item_stmt_while::Item_stmt_while(const uint32_t& lineno,
                                           Item_expr_cond* const condition,
                                           Item_stmt* const statement,
                                           const bool& is_do_while)
    : Item_stmt(lineno),
      condition(condition),
      statement(statement),
      is_do_while(is_do_while) {}

compiler::Item_stmt_break::Item_stmt_break(const uint32_t& lineno)
    : Item_stmt(lineno) {}

compiler::Item_stmt_continue::Item_stmt_continue(const uint32_t& lineno)
    : Item_stmt(lineno) {}

compiler::Item_stmt_return::Item_stmt_return(const uint32_t& lineno,
                                             Item_expr* const expr)
    : Item_stmt(lineno), expr(expr) {}

compiler::Item_stmt_postfix::Item_stmt_postfix(const uint32_t& lineno,
                                               Item_ident* const identifier,
                                               const binary_type& type)
    : Item_stmt(lineno), identifier(identifier), type(type) {}

compiler::Item_block::Item_block(const uint32_t& lineno) : Item_stmt(lineno) {}

compiler::Item_stmt_void::Item_stmt_void(const uint32_t& lineno)
    : Item_stmt(lineno) {}

void compiler::Item_block::add_item(Item_stmt* const statement) {
  statements.emplace_back(statement);
}

std::string compiler::Item_stmt_assign::print_result(const uint32_t& indent,
                                                     const bool& leaf) const {
  std::ostringstream oss;
  print_indent(indent, leaf, oss);
  oss << " Assignment Statement" << std::endl;
  oss << identifier->print_result(indent + 2, true);
  oss << expression->print_result(indent + 2, false);
  return oss.str();
}

std::string compiler::Item_stmt_break::print_result(const uint32_t& indent,
                                                    const bool& leaf) const {
  std::ostringstream oss;
  print_indent(indent, leaf, oss);
  oss << " Break Statement" << std::endl;
  return oss.str();
}

std::string compiler::Item_stmt_continue::print_result(const uint32_t& indent,
                                                       const bool& leaf) const {
  std::ostringstream oss;
  print_indent(indent, leaf, oss);
  oss << " Continue Statement" << std::endl;
  return oss.str();
}

std::string compiler::Item_stmt_eif::print_result(const uint32_t& indent,
                                                  const bool& leaf) const {
  std::ostringstream oss;
  print_indent(indent, leaf, oss);
  oss << " If-else Statement" << std::endl;
  oss << condition->print_result(indent + 2, false);

  // There could be no else statement at all.
  if (else_branch != nullptr) {
    oss << if_branch->print_result(indent + 2, false);
    oss << else_branch->print_result(indent + 2, true);
  } else {
    oss << if_branch->print_result(indent + 2, true);
  }
  return oss.str();
}

std::string compiler::Item_stmt_while::print_result(const uint32_t& indent,
                                                    const bool& leaf) const {
  std::ostringstream oss;
  print_indent(indent, leaf, oss);
  oss << (is_do_while ? "Do While Statement" : " While Statement") << std::endl;
  oss << condition->print_result(indent + 2, false);
  oss << statement->print_result(indent + 2, true);
  return oss.str();
}

std::string compiler::Item_stmt_postfix::print_result(const uint32_t& indent,
                                                      const bool& leaf) const {
  std::ostringstream oss;
  print_indent(indent, leaf, oss);
  oss << " Postfix Statement with identifier"
      << identifier->print_result(indent + 2, true) << std::endl;
  return oss.str();
}

std::string compiler::Item_stmt_void::print_result(const uint32_t& indent,
                                                   const bool& leaf) const {
  std::ostringstream oss;
  print_indent(indent, leaf, oss);
  oss << " Empty Statement" << std::endl;
  return oss.str();
}

std::string compiler::Item_stmt_eval::print_result(const uint32_t& indent,
                                                   const bool& leaf) const {
  std::ostringstream oss;
  print_indent(indent, leaf, oss);
  oss << " Eval Statement" << std::endl;
  oss << expression->print_result(indent + 2, true);
  return oss.str();
}

std::string compiler::Item_stmt_return::print_result(const uint32_t& indent,
                                                     const bool& leaf) const {
  std::ostringstream oss;
  print_indent(indent, leaf, oss);
  oss << " Return statement" << std::endl;
  if (expr != nullptr) {
    oss << expr->print_result(indent + 2, true);
  }

  return oss.str();
}

std::string compiler::Item_block::print_result(const uint32_t& indent,
                                               const bool& leaf) const {
  std::ostringstream oss;
  print_indent(indent, leaf, oss);
  oss << " Block" << std::endl;
  for (uint32_t i = 0; i < statements.size(); i++) {
    oss << statements[i]->print_result(indent + 2, i == statements.size() - 1);
  }
  return oss.str();
}