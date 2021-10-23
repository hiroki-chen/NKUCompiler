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
#ifndef ITEM_STMT_HH
#define ITEM_STMT_HH

#include <frontend/nodes/item_expr.hh>
#include <frontend/nodes/item_ident.hh>

#include <vector>

namespace compiler {

typedef class Item_stmt : public Item_expr {

public:
    typedef enum stmt_type {
        ASSIGN_STMT,
        EIF_STMT,
        WHILE_STMT,
        BREAK_STMT,
        CONTINUE_STMT,
        FOR_STMT,
        RETURN_STMT,
        BLOCK,
        DECL_STMT,
        EVAL_STMT,
        VOID_STMT,
        POSTFIX_STMT,
    } stmt_type;

    Item_stmt() = delete;

    Item_stmt(const uint32_t& line_no);

    virtual Item_expr::expr_type get_expr_type(void) const override { return Item_expr::expr_type::STMT_TYPE; }

    virtual Item_stmt::stmt_type get_stmt_type(void) const = 0;

    virtual ~Item_stmt() override = default;
} Item_stmt;

/**
 * @brief Class for assignment
 * 
 */
typedef class Item_stmt_assign final : public Item_stmt {
protected:
    Item_ident* const identifier;

    Item_expr* const expression;

public:
    Item_stmt_assign() = delete;

    Item_stmt_assign(
        const uint32_t& line_no,
        Item_ident* const identifier,
        Item_expr* const expression);

    virtual Item_stmt::stmt_type get_stmt_type(void) const override { return Item_stmt::stmt_type::ASSIGN_STMT; }

    virtual ~Item_stmt_assign() override = default;
} Item_stmt_assign;

/**
 * @brief Class for if-else statement.
 * 
 */
typedef class Item_stmt_eif final : public Item_stmt {
protected:
    Item_expr_cond* const condition;

    Item_stmt* const if_branch;

    Item_stmt* const else_branch;

public:
    Item_stmt_eif() = delete;

    /**
     * @brief Construct a new Item_stmt_eif object
     * 
     * @param line_no 
     * @param condition 
     * @param if_branch 
     * @param else_branch 
     */
    Item_stmt_eif(const uint32_t& line_no, Item_expr_cond* const condition, Item_stmt* const if_branch, Item_stmt* const else_branch);

    virtual Item_stmt::stmt_type get_stmt_type(void) const override { return Item_stmt::stmt_type::EIF_STMT; }

    virtual ~Item_stmt_eif() override = default;
} Item_stmt_eif;

/**
 * @brief Class for while statement
 * 
 */
typedef class Item_stmt_while final : public Item_stmt {
protected:
    Item_expr_cond* const condition;

    Item_stmt* const statement; // while body

public:
    Item_stmt_while() = delete;

    Item_stmt_while(const uint32_t& line_no, Item_expr_cond* const condition, Item_stmt* const statement);

    virtual Item_stmt::stmt_type get_stmt_type(void) const override { return Item_stmt::stmt_type::WHILE_STMT; }

    virtual ~Item_stmt_while() override = default;
} Item_stmt_while;

/**
 * @brief Class for break statement.
 * 
 */
typedef class Item_stmt_break final : public Item_stmt {
public:
    Item_stmt_break() = delete;

    Item_stmt_break(const uint32_t& line_no);

    virtual Item_stmt::stmt_type get_stmt_type(void) const override { return Item_stmt::stmt_type::BREAK_STMT; }

    virtual ~Item_stmt_break() override = default;
} Item_stmt_break;

/**
 * @brief Class for continue statement
 * 
 */
typedef class Item_stmt_continue final : public Item_stmt {
public:
    Item_stmt_continue() = delete;

    Item_stmt_continue(const uint32_t& line_no);

    virtual Item_stmt::stmt_type get_stmt_type() const override { return Item_stmt::stmt_type::CONTINUE_STMT; }

    virtual ~Item_stmt_continue() override = default;
} Item_stmt_continue;

/**
 * @brief Class for return statement
 * 
 */
typedef class Item_stmt_return final : public Item_stmt {
protected:
    Item_expr* const expr;

public:
    Item_stmt_return() = delete;

    Item_stmt_return(const uint32_t& line_no, Item_expr* const expr = nullptr /* for void function, it can be null*/);

    virtual Item_stmt::stmt_type get_stmt_type(void) const override { return Item_stmt::stmt_type::RETURN_STMT; }

    virtual ~Item_stmt_return() override = default;
} Item_stmt_return;

/**
 * @brief Class for for loop statement.
 * 
 */
typedef class Item_stmt_for final : public Item_stmt {
protected:
    Item_expr* const expr1;

    Item_expr_cond* const condition;

    Item_expr* const expr2;

public:
    Item_stmt_for() = delete;

    Item_stmt_for(const uint32_t& line_no, Item_expr* const expr1 = nullptr, Item_expr_cond* const condition = nullptr, Item_expr* const expr2 = nullptr);

    virtual Item_stmt::stmt_type get_stmt_type(void) const override { return Item_stmt::stmt_type::FOR_STMT; }

    virtual ~Item_stmt_for() override = default;
} Item_stmt_for;

/**
 * @brief Class for nothing.
 * 
 */
typedef class Item_stmt_void final : public Item_stmt {
public:
    Item_stmt_void() = default;

    Item_stmt_void(const uint32_t& line_no);

    virtual Item_stmt::stmt_type get_stmt_type(void) const override { return Item_stmt::stmt_type::VOID_STMT; }

    virtual ~Item_stmt_void() override = default;
} Item_stmt_void;

typedef class Item_stmt_eval final : public Item_stmt {
protected:
    Item_expr* const expression;

public:
    virtual Item_stmt::stmt_type get_stmt_type(void) const override { return Item_stmt::stmt_type::EVAL_STMT; }

    Item_stmt_eval() = delete;

    Item_stmt_eval(const uint32_t& line_no, Item_expr* const expression);

    virtual ~Item_stmt_eval() override = default;
} Item_stmt_eval;

typedef class Item_stmt_postfix final : public Item_stmt {
protected:
    const binary_type type; // ++ / --

    Item_ident* const identifier;

public:
    virtual Item_stmt::stmt_type get_stmt_type(void) const override { return Item_stmt::stmt_type::POSTFIX_STMT; }

    Item_stmt_postfix() = delete;

    Item_stmt_postfix(const uint32_t& line_no, Item_ident* const identifier, const binary_type& type);

    virtual ~Item_stmt_postfix() override = default;
} Item_stmt_postfix;

/**
 * @brief Class for block.
 * 
 */
typedef class Item_block final : public Item_stmt {
protected:
    std::vector<Item_stmt*> statements; // Block body.

public:
    Item_block() = delete;

    Item_block(const uint32_t& line_no);

    virtual void add_item(Item_stmt* const statement);

    virtual Item_stmt::stmt_type get_stmt_type() const override { return Item_stmt::stmt_type::BLOCK; }

    virtual ~Item_block() override = default;
} Item_block;
} // namespace compiler

#endif