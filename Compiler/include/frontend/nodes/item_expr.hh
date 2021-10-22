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
#ifndef ITEM_EXPR_HH
#define ITEM_EXPR_HH

#include <frontend/nodes/item.hh>
#include <common/types.hh>

namespace compiler {

/**
 * @brief Class for general expressions.
 * 
 */
typedef class Item_expr : public Item {
public:
    typedef enum expr_type {
        UNARY_TYPE,
        BINARY_TYPE,
        COND_TYPE,
        LITERAL_TYPE,
        IDENTIFIER_TYPE,
        CALL_LIST_TYPE,
        FUNC_CALL_TYPE,
        FUNC_DEF_ARG_TYPE,
        FUNC_DEF_LIST_TYPE,
        FUNC_DEF_TYPE,
    } expr_type;

    Item_expr() = delete;

    Item_expr(const uint32_t& line_no);

    virtual Item_expr::expr_type get_expr_type(void) const = 0;

    virtual Item::type get_type(void) const override { return Item::type::EXPR_ITEM; }

    // virtual ? eval() const = 0;

    virtual ~Item_expr() override = default;
} Item_expr;

/**
 * @brief Class for conditional expressions.
 * 
 */
typedef class Item_expr_cond final : public Item_expr {
protected:
    Item_expr* const expr;

public:
    virtual Item_expr::expr_type get_expr_type(void) const override { return Item_expr::COND_TYPE; }

    Item_expr_cond() = delete;

    Item_expr_cond(const uint32_t& line_no, Item_expr* const expr);

    virtual ~Item_expr_cond() override = default;
} Item_expr_cond;

/**
 * @brief Class for binary expressions. 
 * 
 */
typedef class Item_expr_binary final : public Item_expr {
protected:
    const binary_type type;

    Item_expr* const lhs;

    Item_expr* const rhs;
public:

    virtual Item_expr::expr_type get_expr_type(void) const override { return Item_expr::BINARY_TYPE; }

    virtual binary_type get_binary_type(void) const { return type; }

    Item_expr_binary() = delete;

    Item_expr_binary(const uint32_t& line_no, const binary_type& type, Item_expr* const lhs, Item_expr* const rhs);

    virtual ~Item_expr_binary() override = default;
} Item_expr_binary;

typedef class Item_expr_unary final : public Item_expr {
protected:
    const unary_type type;

    Item_expr* const expr;
public:
    virtual Item_expr::expr_type get_expr_type(void) const override { return Item_expr::UNARY_TYPE; }

    virtual unary_type get_unary_type(void) const { return type; }

    Item_expr_unary() = delete;

    Item_expr_unary(const uint32_t& line_no, const unary_type& type, Item_expr* const expr);

    virtual ~Item_expr_unary() override = default;
} Item_expr_unary;
} // namespace compiler

#endif