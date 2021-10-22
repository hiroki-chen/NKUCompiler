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
#ifndef TYPES_HH
#define TYPES_HH

namespace compiler {

typedef enum binary_type {
    ADD_TYPE,
    SUB_TYPE,
    MUL_TYPE,
    DIV_TYPE,
    BITOR_TYPE,
    BITAND_TYPE,
    BITXOR_TYPE
} binary_type;

typedef enum unary_type {
    NOT_TYPE,
    NEG_TYPE,
    UMINUS_TYPE,
    UADD_TYPE
} unary_type;

typedef enum basic_type {
    VOID_TYPE,
    INT_TYPE,
    REAL_TYPE,
    CHAR_TYPE,
    STR_TYPE
} basic_type;

typedef enum decl_type {
    VAR_DECL,
    CONST_DECL,
} decl_type;
} // namespace compiler

#endif