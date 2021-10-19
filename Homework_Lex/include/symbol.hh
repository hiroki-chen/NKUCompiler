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
#ifndef SYMBOL_H
#define SYMBOL_H

#include <iostream>
#include <map>
#include <string>
#include <variant>

/**
 * @brief The namespace defined for the compiler
 * 
 * @author chb xjw
 */
namespace compiler {
/**
 * @brief The type of the identifier
 * 
 * @author chb
 */
typedef enum token_type {
    TYPE_VOID,
    TYPE_INT,
    TYPE_DOUBLE,
    TYPE_FLOAT,
    TYPE_CHAR,
    TYPE_STR,
    TYPE_STRUCT,
    TYPE_FUNCTION
} token_type;

typedef struct Symbol {
private:
    /**
     * @brief The name of the symbol.
     * 
     */
    const std::string name;
    
    /**
     * @brief The type of the symbol.
     * 
     * @see \ref{token_type}
     */
    const token_type type;

    /**
     * @brief The value of the symbol. HACKY WAY to deal with this...
     * 
     * @note We do not consider function name in this implementation now.
     * 
     */
    const std::string value;

protected:
    /**
     * @brief Construct a new Symbol object
     * 
     * @author chb
     * @deprecated DO NOT USE IT.
     */
    Symbol() = delete;

public:
    /**
     * @brief Construct a new Symbol object for integers.
     * 
     * @param id 
     * @param token_type 
     * @param value 
     */
    Symbol(const std::string& id, const token_type& token_type, const int& value = 0);

    /**
     * @brief Construct a new Symbol object for doubles.
     * 
     * @param id 
     * @param token_type 
     * @param value 
     */
    Symbol(const std::string& id, const token_type& token_type, const double& value = 0.0);

    /**
     * @brief Construct a new Symbol object for floats.
     * 
     * @param id 
     * @param token_type 
     * @param value 
     */
    Symbol(const std::string& id, const token_type& token_type, const float& value = 0.0);

    /**
     * @brief Construct a new Symbol object for characters.
     * 
     * @param id 
     * @param token_type 
     * @param value 
     */
    Symbol(const std::string& id, const token_type& token_type, const char& value = '\0');

    Symbol(const std::string& id, const token_type& token_type, char* const value = nullptr);

    token_type get_type(void) { return type; }

    std::string get_name(void) { return name; }
} Symbol;

typedef class SymbolTable {
private:
    /**
     * @brief This is rudimentary symbol table for different namespaces.
     * 
     * Usage: scope -> name -> symbol. O(logS * log N)
     * 
     * @author chb
     */
    std::map<std::string, std::map<std::string, Symbol>> symbols;

public:
    SymbolTable() = default;
} SymbolTable;
}

#endif