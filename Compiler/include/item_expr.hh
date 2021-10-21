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
#include <item.hh>
#include <item_stmt.hh>

namespace compiler {

/**
 * @brief Class for expression.
 * 
 */
typedef class Item_expr : public Item_stmt {
public:
    typedef enum expr_type {
        ADD_TYPE,
        SUB_TYPE,
        MUL_TYPE,
        DIV_TYPE,
        MOD_TYPE,
        
        UADD_TYPE,
        UMINUS_TYPE,

        COND_TYPE
    } expr_type;

    Item_expr() = delete;

    Item_expr(const uint32_t& line_no);

    virtual Item::type get_type(void) const override { return Item::type::EXPR_ITEM; }

    virtual Item_expr::expr_type get_expr_type(void) const = 0;

    virtual ~Item_expr();
} Item_expr;

typedef class Item_expr_cond : public Item_expr {
protected:
    Item_expr* const expr;

public:
    virtual Item_expr::expr_type get_expr_type(void) const override { return Item_expr::COND_TYPE; }

    Item_expr_cond() = delete;

    Item_expr_cond(const uint32_t& line_no, Item_expr* const expr);

    virtual ~Item_expr_cond() override = default;
} Item_expr_cond;
} // namespace compiler