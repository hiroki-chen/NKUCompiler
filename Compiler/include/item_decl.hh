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

#include <item.hh>
#include <item_def.hh>
#include <types.hh>

#include <memory>
#include <vector>

namespace compiler {

/**
 * @brief Class for declaration.
 * 
 */
typedef class Item_decl : public Item {
protected:
    const basic_types type;

    std::vector<std::shared_ptr<Item_def>> def_list;

public:
    typedef enum decl_type {
        CONST_DECL,
        VAR_DECL,
        STRUCT_DECL
    } decl_type;
    virtual Item::type get_type(void) const override { return Item::type::DECL_ITEM; }

    virtual Item_decl::decl_type get_decl_type(void) const = 0;

    // Constructors.
    Item_decl() = delete;

    Item_decl(const Item_decl& item_decl) = delete;

    Item_decl(const uint32_t& line_no, const basic_types& type, const std::vector<Item_def*>& def_list);

    virtual ~Item_decl() override = default;
} Item_decl;

typedef class Item_const_decl : public Item_decl {
public:
    virtual Item_decl::decl_type get_decl_type(void) const override { return Item_decl::decl_type::CONST_DECL; }

    Item_const_decl(const uint32_t& line_no, const basic_types& type, const std::vector<Item_def*>& def_list);

    virtual ~Item_const_decl() override = default;
} Item_const_decl;

typedef class Item_var_decl : public Item_decl {
public:
    virtual Item_decl::decl_type get_decl_type(void) const override { return Item_decl::decl_type::VAR_DECL; }

    Item_var_decl(const uint32_t& line_no, const basic_types& type, const std::vector<Item_def*>& def_list);

    virtual ~Item_var_decl() override = default;
} Item_var_decl;
/*
typedef class Item_struct_decl : public Item_decl {
public:
    virtual Item_decl::decl_type get_decl_type(void) const override { return Item_decl::decl_type::STRUCT_DECL; }

    Item_struct_decl(const basic_types& type, const std::vector<Item_def*>& def_list);
} Item_struct_decl;
*/
} // namespace compiler

#endif