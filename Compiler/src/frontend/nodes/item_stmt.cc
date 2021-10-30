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
#include <frontend/nodes/item_stmt.hh>
#include <string>
#include <sstream>

compiler::Item_stmt::Item_stmt(const uint32_t& line_no)
    : Item_expr(line_no)
{
}

compiler::Item_stmt_assign::Item_stmt_assign(
    const uint32_t& line_no,
    Item_ident* const identifier,
    Item_expr* const expression)
    : Item_stmt(line_no)
    , identifier(identifier)
    , expression(expression)
{
}

compiler::Item_stmt_eval::Item_stmt_eval(const uint32_t& line_no, Item_expr* const expression)
    : Item_stmt(line_no)
    , expression(expression)
{
}

compiler::Item_stmt_eif::Item_stmt_eif(
    const uint32_t& line_no,
    Item_expr* const condition,
    Item_stmt* const if_branch,
    Item_stmt* const else_branch)
    : Item_stmt(line_no)
    , condition(condition)
    , if_branch(if_branch)
    , else_branch(else_branch)
{
}

compiler::Item_stmt_while::Item_stmt_while(
    const uint32_t& line_no,
    Item_expr* const condition,
    Item_stmt* const statement)
    : Item_stmt(line_no)
    , condition(condition)
    , statement(statement)
{
}

compiler::Item_stmt_break::Item_stmt_break(const uint32_t& line_no)
    : Item_stmt(line_no)
{
}

compiler::Item_stmt_continue::Item_stmt_continue(const uint32_t& line_no)
    : Item_stmt(line_no)
{
}

compiler::Item_stmt_return::Item_stmt_return(const uint32_t& line_no, Item_expr* const expr)
    : Item_stmt(line_no)
    , expr(expr)
{
}

compiler::Item_stmt_postfix::Item_stmt_postfix(const uint32_t& line_no, Item_ident* const identifier, const binary_type& type)
    : Item_stmt(line_no)
    , identifier(identifier)
    , type(type)
{
}

compiler::Item_block::Item_block(const uint32_t& line_no)
    : Item_stmt(line_no)
{
}

compiler::Item_stmt_void::Item_stmt_void(const uint32_t& line_no)
    : Item_stmt(line_no)
{
}

void compiler::Item_block::add_item(Item_stmt* const statement)
{
    statements.emplace_back(statement);
}

std::string
compiler::Item_stmt_assign::print_result(void) const
{
    std::ostringstream oss;
    oss << "Node: Assignment Statement" << std::endl;
    oss << "--" << identifier->print_result() << std::endl;
    oss << "--" << expression->print_result() << std::endl;
    return oss.str();
}

std::string
compiler::Item_stmt_break::print_result(void) const
{
    std::ostringstream oss;
    oss << "Node: Break Statement" << std::endl;
    return oss.str();
}

std::string
compiler::Item_stmt_continue::print_result(void) const
{
    std::ostringstream oss;
    oss << "Node: Continue Statement" << std::endl;
    return oss.str();
}

std::string
compiler::Item_stmt_eif::print_result(void) const
{
    std::ostringstream oss;
    oss << "Node: If-else Statement" << std::endl;
    oss << "-- Condition: " << std::endl << condition->print_result();
    oss << "-- If branch: " << std::endl << if_branch->print_result();

    // There could be no else statement at all.
    if (else_branch != nullptr) {
        oss << "-- Else branch: " << else_branch->print_result();
    }
    return oss.str();
}

std::string
compiler::Item_stmt_while::print_result(void) const
{
    std::ostringstream oss;
    oss << "Node: While Statement" << std::endl;
    oss << "-- Condition: " << condition->print_result();
    oss << "-- While body: " << statement->print_result();
    return oss.str();
}

std::string
compiler::Item_stmt_postfix::print_result(void) const
{
    std::ostringstream oss;
    oss << "Node: Postfix Statement with identifier" << identifier->print_result() << std::endl;
    return oss.str();
}

std::string
compiler::Item_stmt_void::print_result(void) const
{
    return "Node: Empty Statement";
}

std::string
compiler::Item_stmt_eval::print_result(void) const
{
    std::ostringstream oss;
    oss << "Node: Eval Statement" << std::endl;
    oss << "-- Expression body" << std::endl <<expression->print_result();
    return oss.str();
}

std::string
compiler::Item_stmt_return::print_result(void) const
{
    std::ostringstream oss;
    oss << "Node: Return statement" << std::endl;
    if (expr != nullptr) {
        oss << "--" << expr->print_result();
    } else {
        oss << "--VOID" << std::endl;
    }
    return oss.str();
}

std::string
compiler::Item_block::print_result(void) const
{
    std::ostringstream oss;
    oss << "Node: Block" << std::endl;
    for (auto item : statements) {
        oss << "--" << item->print_result();
    }
    return oss.str();
}