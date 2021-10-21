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
#include <item_expr.hh>
#include <types.hh>

#include <cstring>
#include <iostream>
#include <map>
#include <string>

namespace compiler {

/**
 * @brief Class for identifiers.
 * 
 * @note THIS IS AN ABSTACT CLASS! DO NOT CREATE AN INSTANCE FROM IT. BUT IT IS OK WITH
 *       Idem_ident *const item_ident = new Idem_int_ident(...);
 * 
 */
typedef class Item_ident : public Item_expr {
protected:
    /**
     * @brief The symbol name.
     * 
     * E.g.: int a = 3   =>    name = "a"
     */
    const std::string name;

    /**
     * @brief In which scope does it reside. Identified by a unique number.
     * 
     */
    const uint32_t scope;

public:
    /**
     * @brief The type of the identifier.
     * 
     */
    typedef enum ident_type {
        INT_TYPE,
        REAL_TYPE, // DOUBLE AND FLOAT ARE JUST "REAL" TYPE.
        CHAR_TYPE,
        FUNC_TYPE,
        STRUCT_TYPE,
        INT_ARRAY_TYPE,
        REAL_ARRAY_TYPE,
        CHAR_ARRAY_TYPE
    } ident_type;

    /**
     * @brief Get the type object
     * 
     * @return Item::type 
     */
    virtual Item::type get_type(void) const override { return Item::type::ITENT_ITEM; }

    // DO NOT USE A RAW ITEM_IDENT.
    Item_ident() = delete;

    Item_ident(const Item_ident& idem_ident) = delete;
    /**
     * @brief Construct a new Item_ident object
     * 
     * @param line_no       The number of the current line.
     * @param name          The name of the symbol.
     * @param scope         The current scope.
     */
    Item_ident(const uint32_t& line_no, const std::string& name, const uint32_t& scope);

    /**
     * @brief Get the name object
     * 
     * @return std::string 
     */
    virtual std::string get_name(void) const { return name; }

    virtual Item_ident::ident_type get_ident_type(void) const = 0;

    /*
        Here it begins with basic value dump functions.
        For implementation, we consider every value to be "double" (even with characters)
        Currently we do not take into consideration the array type and other complex objects like "struct".
    */
    virtual char get_char(void) const { return 0; }

    virtual int get_int(void) const { return 0; }

    virtual double get_real(void) const { return 0.0; }

    virtual char* get_c_str(void) const { return nullptr; }

    /**
     * @brief Destroy the Item_ident object
     * 
     */
    virtual ~Item_ident();
} Item_ident;

/*
    Here it begins with identifiers with different types.
*/
typedef class Item_ident_int : public Item_ident {
protected:
    int value;

public:
    virtual Item_ident::ident_type get_ident_type(void) const override { return Item_ident::INT_TYPE; }

    virtual int get_int(void) const override { return value; }

    Item_ident_int() = delete;

    Item_ident_int(const uint32_t& line_no, const std::string& name, const uint32_t& scope, const int& value = 0);

    virtual ~Item_ident_int() override = default;
} Item_ident_int;

typedef class Item_ident_real : public Item_ident {
protected:
    double value;

public:
    virtual Item_ident::ident_type get_ident_type(void) const override { return Item_ident::REAL_TYPE; }

    virtual double get_real(void) const override { return value; }

    Item_ident_real(const uint32_t& line_no, const std::string& name, const uint32_t& scope, const double& value = 0.0);

    virtual ~Item_ident_real() override = default;
} Item_ident_real;

typedef class Item_ident_char : public Item_ident {
protected:
    char value;

public:
    virtual Item_ident::ident_type get_ident_type(void) const override { return Item_ident::CHAR_TYPE; }

    virtual char get_char(void) const override { return value; }

    Item_ident_char(const uint32_t& line_no, const std::string& name, const uint32_t& scope, const char& value = '\0');

    virtual ~Item_ident_char() override = default;
} Item_ident_char;

typedef class Item_ident_str : public Item_ident {
protected:
    std::string value;

public:
    virtual Item_ident::ident_type get_ident_type(void) const override { return Item_ident::CHAR_ARRAY_TYPE; }

    virtual char* get_c_str(void) const override { return strdup(value.c_str()); }

    Item_ident_str() = delete;

    Item_ident_str(const uint32_t& line_no, const std::string& name, const uint32_t& scope, const char* value = nullptr);

    virtual ~Item_ident_str() override = default;
} Item_ident_str;

typedef class Item_ident_struct : public Item_ident {
protected:
    // A pointer to the definition?
    // Item_def *const item_struct;
public:
    /**
     * @brief Usage: struct.id
     * 
     * @param name 
     * @return Item_ident* 
     */
    virtual Item_ident* dereference(const std::string& name) const;

    virtual Item_ident::ident_type get_ident_type(void) const override { return Item_ident::STRUCT_TYPE; }

    Item_ident_struct() = delete;

    Item_ident_struct(const uint32_t& line_no, const std::string& name, const uint32_t& scope, const uintptr_t& struct_ptr);

    virtual ~Item_ident_struct() override = default;

} Item_ident_struct;
} // namespace compiler
#endif