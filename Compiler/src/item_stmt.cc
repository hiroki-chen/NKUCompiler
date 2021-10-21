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
#include <item_stmt.hh>

compiler::Item_stmt::Item_stmt(const uint32_t& line_no)
    : Item(line_no)
{
}

compiler::Item_stmt_eif::Item_stmt_eif(
    const uint32_t& line_no,
    Item_expr_cond* const condition,
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
    Item_expr_cond* const condition,
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

compiler::Item_stmt_for::Item_stmt_for(
    const uint32_t& line_no,
    Item_expr* const expr1,
    Item_expr_cond* const condition,
    Item_expr* const expr2)
    : Item_stmt(line_no)
    , expr1(expr1)
    , condition(condition)
    , expr2(expr2)
{
}

compiler::Item_block::Item_block(const uint32_t& line_no)
    : Item_stmt(line_no)
{
}

void compiler::Item_block::add(Item_stmt* const statement)
{
    statements.emplace_back(statement);
}