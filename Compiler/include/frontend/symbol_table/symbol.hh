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
#ifndef SYMBOL_HH
#define SYMBOL_HH

#include <frontend/nodes/item_all.hh>
#include <common/types.hh>

#include <string>

namespace compiler {

/**
 * @brief Class for symbols (basic type).
 * 
 */
typedef class Symbol {
protected:
    const std::string name;

    const symbol_type type;

    bool is_const;

    Item_literal* value;

public:
    Symbol() = delete;

    Symbol(const std::string& name, const symbol_type& type);

    virtual void set_value(Item_literal* const literal) { this->value = literal; }

    virtual void set_const(const bool& is_const) { this->is_const = is_const; }

    virtual std::string get_name(void) const { return name; }

    virtual symbol_type get_type(void) const { return type; }

    virtual ~Symbol() = default;
} Symbol;

typedef class Symbol_func final : public Symbol {
protected:
    Item_func_def_list* const arguments;

    const basic_type return_type;

public:
    Symbol_func() = delete;

    Symbol_func(
        const std::string& name,
        const basic_type& return_type,
        Item_func_def_list* const arguments);
} Symbol_func;
} // namespace compiler

#endif