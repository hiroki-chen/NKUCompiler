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
#ifndef ITEM_ARGUMENT_LIST_HH
#define ITEM_ARGUMENT_LIST_HH

#include <frontend/nodes/item_expr.hh>

#include <vector>

namespace compiler {

typedef class Item_expr_call_list : public Item_expr {
protected:
    std::vector<Item_expr*> arguments;

public:
    virtual void add_arg(Item_expr* const arg);

    virtual Item_expr::expr_type get_expr_type(void) const override { return Item_expr::expr_type::ARG_CALL_LIST_TYPE; }

    Item_expr_call_list() = delete;

    Item_expr_call_list(const uint32_t& line_no);

    virtual ~Item_expr_call_list() override = default;
} Item_expr_call_list;
} // namespace compiler

#endif