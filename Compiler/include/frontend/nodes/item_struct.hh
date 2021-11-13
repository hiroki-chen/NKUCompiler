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
#ifndef ITEM_STRUCT_HH
#define ITEM_STRUCT_HH

#include <frontend/nodes/item_decl.hh>

#include <vector>

namespace compiler {
typedef class Item_struct_body final : Item_stmt {
protected:
    std::vector<Item*> struct_body;

public:
    Item_struct_body() = delete;

    Item_struct_body(const uint32_t& lineno);

    virtual Item_stmt::stmt_type get_stmt_type(void) const override { return Item_stmt::stmt_type::STRUCT_BODY; }

    virtual std::string print_result(const uint32_t& indent, const bool& leaf) const override;

    virtual void generate_ir(compiler::ir::IRContext* const context, std::vector<compiler::ir::IR>& ir_list) const override { return; }

    virtual void add_body(Item* const item) { struct_body.emplace_back(item); }
    
    virtual ~Item_struct_body() override = default;
} Item_struct_body;
} // namespace compiler;

#endif