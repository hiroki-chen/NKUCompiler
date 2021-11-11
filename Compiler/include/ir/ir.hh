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
#ifndef IR_HH
#define IR_HH

#include <vector>

namespace compiler::ir {
/**
 * @brief The class for IR (Intermediate Representation).
 * 
 */
typedef class IR {

} IR;

/**
 * @brief Defines different operations.
 * 
 */
typedef enum op_type {
    NOP,
    // Basic algorithmic operations
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,

    // For floats.
    FADD,
    FSUB,
    FMUL,
    FDIV,
    FNEG,

    // Assignment
    MOV,

    // Function call
    CALL,
    RETURN,

    // Jump
    JMP,
    JGE,
    JLE,
    JEQ,
    JNE,
    JLT,
    JGT,

    // Bit operations.
    BIT_AND,
    BIT_OR,
    BIT_XOR,
    BIT_NEG,
    SHL,
    LSHR,
    ASHR,

    // Logic operations.
    LAND,
    LOR,
    LNOT,

    // Relational operations.
    CMP,

    // Memory related operations.
    LOAD,
    STORE,
    MALLOC

    // Delimiters.
    BEGIN_DATA,
    END_DATA,
    BEGIN_FUNC,
    END_FUNC,
    BEGIN_STRUCT,
    END_STRUCT,

    // Jump labels.
    LBL,
} op_type;

/**
 * @brief Defines different variable types.
 * 
 * i32 => 32-bit variables. int, unsigned int.
 */
typedef enum var_type {
    i32,
    i8,
    // A little bit of complex...
    DOUBLE,
    FLOAT
} var_type;

} // namespace compiler::ir

#endif