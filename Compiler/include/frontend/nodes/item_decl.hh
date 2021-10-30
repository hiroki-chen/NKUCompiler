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
#include <frontend/nodes/item_literal.hh>
#include <frontend/nodes/item_stmt.hh>
#include <common/types.hh>

#include <memory>
#include <vector>

namespace compiler {

/**
 * @brief Class for declaration. BUT THIS NOT A DECLARE STATEMENT.
 * 
 */
typedef class Item_decl : public Item {
public:
    Item_decl() = delete;

    Item_decl(const uint32_t& line_no);

    virtual Item::type get_type(void) const override { return Item::type::DECLARE_ITEM; }

    virtual ~Item_decl() override = default;
} Item_decl;

typedef class Item_stmt_decl : public Item_stmt {
protected:
    std::vector<Item_decl*> declarations;

    const basic_type type;
public:
    virtual Item_stmt::stmt_type get_stmt_type(void) const override { return Item_stmt::stmt_type::DECL_STMT; }

    virtual void add_declaration(Item_decl* const declaration);

    virtual std::string print_result(void) const override;

    Item_stmt_decl() = delete;

    Item_stmt_decl(const uint32_t& line_no, const basic_type& type);
} Item_stmt_decl;

/**
 * @brief Class for declaraction of variables.
 * 
 */
typedef class Item_decl_var : public Item_decl {
protected:
    Item_ident* const identifier;

public:
    Item_decl_var() = delete;

    Item_decl_var(const uint32_t& line_no, Item_ident* const identifier);

    virtual std::string print_result(void) const override;

    virtual ~Item_decl_var() override = default;
} Item_decl_var;

typedef class Item_decl_pointer final : public Item_decl {
protected:
    Item_ident_pointer* const identifier;

public:
    Item_decl_pointer() = delete;

    Item_decl_pointer(const uint32_t& line_no, Item_ident_pointer* const identifier);

    virtual std::string print_result(void) const override;

    virtual ~Item_decl_pointer() override = default;
} Item_decl_pointer;


/**
 * @brief Class for declaration of variables with initial value.
 * 
 */
typedef class Item_decl_var_init final : public Item_decl_var {
protected:
    Item_expr* const expression; // Init value.

    const bool is_const;
public:
    virtual bool get_is_const(void) const { return is_const; }

    virtual std::string print_result(void) const override;

    Item_decl_var_init() = delete;

    Item_decl_var_init(const uint32_t& line_no, Item_ident* const identifier, Item_expr* const expression, const bool& is_const);

    virtual ~Item_decl_var_init() override = default;
} Item_decl_var_init;

/**
 * @brief Class for declaraction of variables.
 * 
 */
typedef class Item_decl_array : public Item_decl {
protected:
    Item_ident_array* const identifier;

public:
    Item_decl_array() = delete;

    Item_decl_array(const uint32_t& line_no, Item_ident_array* const identifier);

    virtual std::string print_result(void) const override;

    virtual ~Item_decl_array() override = default;
} Item_decl_array;

typedef class Item_decl_array_init final : public Item_decl_array {
protected:
    const bool is_const;

    Item_literal_array_init* const init_value;
public:
    virtual bool get_is_const(void) const { return is_const; }

    Item_decl_array_init() = delete;

    Item_decl_array_init(
        const uint32_t& line_no,
        Item_ident_array* const identifier,
        Item_literal_array_init* const init_value,
        const bool& is_const);

    virtual std::string print_result(void) const override;

    virtual ~Item_decl_array_init() override = default;
} Item_decl_array_init;
} // namespace compiler

#endif