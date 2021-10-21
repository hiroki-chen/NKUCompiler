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
#ifndef ITEM_DECL_HH
#define ITEM_DECL_HH

#include <frontend/nodes/item.hh>
#include <frontend/nodes/item_stmt.hh>
#include <common/types.hh>

#include <memory>
#include <vector>

namespace compiler {

/**
 * @brief Class for declaration.
 * 
 */
typedef class Item_decl : public Item_stmt {
public:
    typedef enum decl_type {
        VAR_DECL,
        CONST_DECL,
        FUNC_DECL,
        STRUCT_DECL,
    } decl_type;

    Item_decl() = delete;

    Item_decl(const uint32_t& line_no);

    virtual Item_stmt::stmt_type get_stmt_type(void) const override { return DECL_STMT; }

    virtual Item_decl::decl_type get_decl_type(void) const = 0;

    virtual ~Item_decl() override = default;
} Item_decl;
} // namespace compiler

#endif