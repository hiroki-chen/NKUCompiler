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

#include <functional>
#include <iostream>
#include <string>
#include <vector>

#ifndef FORMAT
#define FORMAT(output, str)                                 \
    {                                                       \
        output << std::ios::left << std::setw(0x10) << str; \
    }
#endif

namespace compiler::ir {
/**
 * @brief Look-up table for enum type compiler::ir::op_type.
 * 
 */
static const char* op_name[42] {
    "NOP",
    // Basic algorithmic operations
    "IADD",
    "ISUB",
    "IMUL",
    "IDIV",
    "IMOD",

    // For floats.
    "FADD",
    "FSUB",
    "FMUL",
    "FDIV",
    "FNEG",

    // Assignment
    "MOV",

    // Function call
    "CALL",
    "RET",

    // Jump
    "JMP",
    "JGE",
    "JLE",
    "JEQ",
    "JNE",
    "JLT",
    "JGT",

    // Bit operations.
    "BAND",
    "BOR",
    "BXOR",
    "BNEG",
    "SHL",
    "LSHR",
    "ASHR",

    // Logic operations.
    "LAND",
    "LOR",
    "LNOT",

    // Relational operations.
    "CMP",

    // Memory related operations.
    "LOAD",
    "STORE",
    "MALLOC",

    // Delimiters.
    "BEGIN_DATA",
    "END_DATA",
    "BEGIN_FUNC",
    "END_FUNC",
    "BEGIN_STRUCT",
    "END_STRUCT",

    // Jump labels.
    "LBL",
};
/**
 * @brief Defines different operations.
 * 
 */
typedef enum op_type {
    NOP,
    // Basic algorithmic operations
    IADD,
    ISUB,
    IMUL,
    IDIV,
    IMOD,

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
    RET,

    // Jump
    JMP,
    JGE,
    JLE,
    JEQ,
    JNE,
    JLT,
    JGT,

    // Bit operations.
    BAND,
    BOR,
    BXOR,
    BNEG,
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
    MALLOC,

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
    DB,
    FL,
} var_type;

/**
 * @brief Base class for operand in the IR.
 * 
 */
typedef class Operand {
protected:
    const var_type type;

    const std::string identifier;

    const bool is_ptr;

    const bool is_var;

    // We need to convert the value to hexical.
    const std::string value;

public:
    Operand() = delete;

    Operand(
        const var_type& type,
        const std::string& identifier,
        const std::string& value,
        const bool& is_var = true,
        const bool& is_ptr = false);

    virtual var_type get_type(void) const { return type; }

    virtual bool get_is_ptr(void) const { return is_ptr; }

    virtual bool get_is_var(void) const { return is_var; }

    virtual std::string get_identifier(void) const { return identifier; }

    virtual std::string get_value(void) const { return value; }

    virtual ~Operand() = default;
} Operand;

/**
 * @brief Class for pointer types.
 * 
 */
typedef class Operand_ptr final : public Operand {
protected:
    // How many aterisks it has.
    const uint32_t shape;

public:
    Operand_ptr() = delete;

    Operand_ptr(
        const var_type& type,
        const std::string& identifier,
        const std::string& value,
        const uint32_t& shape);

    ~Operand_ptr() override = default;
} Operand_ptr;

/**
 * @brief The class for IR (Intermediate Representation). 
 *        Some representation notations are taken from LLVM. @see https://llvm.org/docs/LangRef.html
 * 
 * Examples:
 * ADD i32 foo, i8 bar, double baz
 * ALLOC i32, align 8.
 * 
 * @note LOGIC EXPLAINED
 *       When an compiler::IR instance is created from the AST, we should call compiler::ir::IR::walk_ir()
 *       function to generate the string as follows:
 *       1. Create a lambda function that can be passed to compiler::ir::IR::walk_ir()
 *          that does some job with current operation;
 *       2. The function compiler::ir::IR::walk_ir() will iterate through each operands,
 *          and because each operand can be another instance of compiler::ir::IR, we need to dig into the   
 *          operand, where callback function comes to help.
 *       3. The callback will call each operand with callback again until it reaches a deepmost level:
 *          the raw operand that we can ensure whether it is chained to the caller or not.
 */
typedef class IR final {
private:
    const op_type type;

    const std::string label;

    Operand* const operand_a;
    Operand* const operand_b;
    Operand* const operand_c;
    Operand* const dst;

    uint32_t lineno;

    // void emit_helper(decltype<compiler::ir::isvar> callback, const bool& chained = true) const;

    /**
     * @brief Helper function for generating the IR. Since each variable / immediate value can be related to
     *        some other IRs, we need a callback function that could correctly "notify" the caller whether the
     *        source variable (src) should be written by the result (dst).
     * 
     * @param callback A callback function.
     * @param chained 
     * @return is_chained
     */
    bool emit_helper(std::function<bool(Operand* const)>&& callback, const bool& chained = true) const;

    /**
     * @brief Call get_is_var().
     * 
     * @param callback 
     * @param chained 
     * @return is_chained
     */
    bool emit_helper(decltype(&Operand::get_is_var)&& callback, const bool& chained = true) const;

    /**
     * @brief The @ref{compiler::ir::IR::emit_ir} funciton will iterator over each operand and emit their IRs.
     * 
     * @param callback A lambda expression or a function object: the callback function.
     * @param chained    Denote whether the result is related to another IR.
     *                   Should be evaluated via callback.
     */
    void walk_ir(std::function<void(Operand* const)>&& callback, const bool& chained = true);

public:
    // Default constructor is definitely not allowed.
    IR() = delete;

    IR(
        const op_type& operation,
        Operand* const dst,
        Operand* const operand_a,
        Operand* const operand_b,
        Operand* const operand_c,
        const std::string& labal = "");

    IR(
        const op_type& operation,
        Operand* const dst,
        Operand* const operand_a,
        Operand* const operand_b,
        const std::string& labal = "");

    IR(
        const op_type& operation,
        Operand* const dst,
        Operand* const operand_a,
        const std::string& label = "");

    IR(
        const op_type& operation,
        Operand* const dst,
        const std::string& label = "");

    /**
     * @brief Emit the IR.
     * 
     * @param out 
     * @param verbose 
     */
    void emit_ir(std::ostream& out = std::cout, const bool& verbose = false);
} IR;

} // namespace compiler::ir

#endif