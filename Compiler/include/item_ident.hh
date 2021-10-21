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
#ifndef ITEM_VALUE_HH
#define ITEM_VALUE_HH

#include <item.hh>
#include <types.hh>

#include <iostream>
#include <map>
#include <string>
namespace compiler {

/**
 * @brief Class for identifiers.
 * 
 */
typedef class Item_ident : public Item {
protected:
    const std::string name;

    const uint32_t scope;
public:
    typedef enum ident_type {
        INT_TYPE,
        REAL_TYPE,
        CHAR_TYPE,
        FUNC_TYPE,
        INT_ARRAY_TYPE,
        REAL_ARRAY_TYPE,
        CHAR_ARRAY_TYPE
    } ident_type;

    virtual Item::type get_type(void) const override { return Item::type::ITENT_ITEM; }

    Item_ident() = delete;

    Item_ident(const Item_ident& idem_ident) = delete;
    /**
     * @brief Construct a new Item_ident object
     * 
     * @param line_no       The number of the current line.
     * @param name          The name of the symbol.
     * @param scope         The current scope.
     */
    Item_ident(const uint32_t& line_no, const std::string& name, const uint32_t scope);

    virtual std::string get_name(void) const { return name; }

    virtual Item_ident::ident_type get_ident_type(void) const = 0;

    virtual char get_char(void) const { return 0; }

    virtual int get_int(void) const { return 0; }

    virtual double get_real(void) const { return 0.0; }

    virtual ~Item_ident() override = default;
} Item_ident;

typedef class Item_ident_int : public Item_ident {
protected:
    int value;

public:
    virtual Item_ident::ident_type get_ident_type(void) const override { return Item_ident::INT_TYPE; }

    virtual int get_int(void) const override { return value; }

    Item_ident_int(const uint32_t& line_no, const std::string& name, const uint32_t scope, const int& value = 0);

    virtual ~Item_ident_int() override = default;
} Item_ident_int;

typedef class Item_ident_real : public Item_ident {
protected:
    double value;

public:
    virtual Item_ident::ident_type get_ident_type(void) const override { return Item_ident::REAL_TYPE; }

    virtual double get_real(void) const override { return value; }

    Item_ident_real(const uint32_t& line_no, const std::string& name, const uint32_t scope, const double& value = 0.0);

    virtual ~Item_ident_real() override = default;
} Item_ident_real;

typedef class Item_ident_char : public Item_ident {
protected:
    char value;

public:
    virtual Item_ident::ident_type get_ident_type(void) const override { return Item_ident::CHAR_TYPE; }

    virtual char get_char(void) const override { return value; }

    Item_ident_char(const uint32_t& line_no, const std::string& name, const uint32_t scope, const char& value = '\0');

    virtual ~Item_ident_char() override = default;
} Item_ident_char;

} // namespace compiler
#endif