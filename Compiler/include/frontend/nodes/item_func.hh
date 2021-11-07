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
#ifndef ITEM_FUNC_HH
#define ITEM_FUNC_HH

#include <common/types.hh>
#include <frontend/nodes/item.hh>
#include <frontend/nodes/item_expr.hh>
#include <frontend/nodes/item_ident.hh>
#include <frontend/nodes/item_stmt.hh>

#include <vector>

namespace compiler {
/**
 * @brief Class for function call argument list.
 * 
 */
typedef class Item_func_call_list final : public Item_expr {
protected:
    std::vector<Item_expr*> arguments;

public:
    virtual void add_arg(Item_expr* const arg);

    virtual std::vector<Item_expr*> get_arguments(void) const { return arguments; }

    virtual Item_expr::expr_type get_expr_type(void) const override { return Item_expr::expr_type::CALL_LIST_TYPE; }

    virtual std::string print_result(const uint32_t& indent, const bool& leaf) const override;

    Item_func_call_list() = delete;

    Item_func_call_list(const uint32_t& lineno);

    virtual ~Item_func_call_list() override = default;
} Item_func_call_list;

typedef class Item_func_call final : public Item_expr {
protected:
    Item_ident* const identifier;

    Item_func_call_list* const arguments;

public:
    virtual Item_expr::expr_type get_expr_type(void) const override { return Item_expr::expr_type::FUNC_CALL_TYPE; }

    virtual Item_ident* get_identifier(void) const { return identifier; }

    virtual Item_func_call_list* get_call_list(void) const { return arguments; }

    virtual std::string print_result(const uint32_t& indent, const bool& leaf) const override;

    Item_func_call() = delete;

    Item_func_call(const uint32_t& lineno, Item_ident* const identifier, Item_func_call_list* const arguments);

    virtual ~Item_func_call() override = default;
} Item_func_call;

typedef class Item_func_def_arg final : public Item_expr {
protected:
    const basic_type type;

    Item_ident* const identifier;

public:
    virtual Item_expr::expr_type get_expr_type(void) const override { return Item_expr::expr_type::FUNC_DEF_ARG_TYPE; }

    virtual basic_type get_arg_type(void) const { return type; }

    virtual Item_ident* get_identifier(void) const { return identifier; }

    virtual std::string print_result(const uint32_t& indent, const bool& leaf) const override;

    Item_func_def_arg() = delete;

    Item_func_def_arg(const uint32_t& lineno, const basic_type& type, Item_ident* const identifier);

    virtual ~Item_func_def_arg() override = default;
} Item_func_def_arg;

typedef class Item_func_def_list final : public Item_expr {
protected:
    std::vector<Item_func_def_arg*> arguments;

public:
    Item_func_def_list() = delete;

    Item_func_def_list(const uint32_t& lineno);

    virtual void add_arg(Item_func_def_arg* const argument);

    virtual std::string print_result(const uint32_t& indent, const bool& leaf) const override;

    virtual Item_expr::expr_type get_expr_type(void) const override { return Item_expr::expr_type::FUNC_DEF_LIST_TYPE; }

    virtual ~Item_func_def_list() override = default;
} Item_func_def_list;

typedef class Item_func_def final : public Item {
protected:
    const basic_type return_type;

    Item_ident* const identifier;

    Item_func_def_list* const parameter;

    Item_block* const func_body;

public:
    virtual Item::type get_type(void) const override { return Item::type::FUNC_DEF_ITEM; }

    Item_func_def() = delete;

    Item_func_def(const uint32_t& lineno,
        const basic_type& return_type,
        Item_ident* const identifier,
        Item_func_def_list* const parameter,
        Item_block* const func_body);

    virtual std::string print_result(const uint32_t& indent, const bool& leaf) const override;

    virtual ~Item_func_def() override = default;
} Item_func_def;
} // namespace compiler

#endif