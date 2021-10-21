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
#ifndef ITEM_LITERAL_HH
#define ITEM_LITERAL_HH

#include <frontend/nodes/item_expr.hh>

namespace compiler {

/**
 * @brief Class for literals.
 * 
 */
typedef class Item_literal : public Item_expr {
public:
    typedef enum literal_type {
        INT,
        REAL,
        CHAR,
        STRING,
    } literal_type;

    virtual Item_literal::literal_type get_literal_type(void) const = 0;

    virtual Item_expr::expr_type get_expr_type(void) const override { return Item_expr::expr_type::LITERAL_TYPE; }

    Item_literal() = delete;

    Item_literal(const uint32_t& line_no);

    virtual ~Item_literal() override = default;
} Item_literal;

/**
 * @brief Class for basic numbers. INT/DOUBLE/CHAR
 * 
 */
typedef class Item_literal_numeric : public Item_literal {
protected:
    double value;

public:
    Item_literal_numeric() = delete;

    Item_literal_numeric(const uint32_t& line_no, const double& value);

    virtual Item_literal::literal_type get_literal_type(void) const override = 0;

    virtual ~Item_literal_numeric() override = default;
} Item_literal_numeric;

typedef class Item_literal_int : public Item_literal_numeric {
public:
    virtual Item_literal::literal_type get_literal_type(void) const override { return Item_literal::literal_type::INT; }

    virtual int get_int() const { return (int)value; }

    Item_literal_int() = delete;

    Item_literal_int(const uint32_t& line_no, const int& value);

    virtual ~Item_literal_int() override = default;
} Item_literal_int;
} // namespace compiler

#endif