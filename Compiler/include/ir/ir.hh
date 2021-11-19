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

#include <common/types.hh>
#include <functional>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#ifndef FORMAT
#define FORMAT(output, str) \
  { output << std::setw(0x10) << std::left << str << " "; }
#endif

namespace compiler::ir {
/**
 * @brief Look-up table for enum type compiler::ir::op_type.
 *
 */
static const char* op_name[46]{
    "ARG",
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
    "GLOBAL",
    "SPACE",
    "END_DATA",
    "BEGIN_FUNC",
    "END_FUNC",
    "BEGIN_STRUCT",
    "END_STRUCT",

    // Jump labels.
    "LBL",

    // PHI_MOVE
    "PHI_MOVE",
};
/**
 * @brief Defines different operations.
 *
 */
typedef enum op_type {
  ARG,
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
  GLOBAL,
  SPACE,
  END_DATA,
  BEGIN_FUNC,
  END_FUNC,
  BEGIN_STRUCT,
  END_STRUCT,

  // Jump labels.
  LBL,
} op_type;

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
  /**
   * @brief Construct a dummy Operand object.
   *
   */
  Operand();

  Operand(const std::string& name);

  Operand(const var_type& type, const std::string& identifier,
          const std::string& value, const bool& is_var = true,
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
  Operand_ptr();

  Operand_ptr(const var_type& type, const std::string& identifier,
              const std::string& value, const uint32_t& shape);

  ~Operand_ptr() override = default;
} Operand_ptr;

/**
 * @brief The class for IR (Intermediate Representation).
 *        Some representation notations are taken from LLVM. @see
 * https://llvm.org/docs/LangRef.html
 *
 * Examples:
 * ADD i32 foo, i8 bar, double baz
 * ALLOC i32, align 8.
 *
 * @note LOGIC EXPLAINED
 *       When an compiler::IR instance is created from the AST, we should call
 * compiler::ir::IR::walk_ir() function to eval_cond the string as follows:
 *       1. Create a lambda function that can be passed to
 * compiler::ir::IR::walk_ir() that does some job with current operation;
 *       2. The function compiler::ir::IR::walk_ir() will iterate through each
 * operands, and because each operand can be another instance of
 * compiler::ir::IR, we need to dig into the operand, where callback function
 * comes to help.
 *       3. The callback will call each operand with callback again until it
 * reaches a deepmost level: the raw operand that we can ensure whether it is
 * chained to the caller or not.
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

  // void emit_helper(decltype<compiler::ir::isvar> callback, const bool&
  // chained = true) const;

  /**
   * @brief Helper function for generating the IR and prune needless branches.
   * Since each variable / immediate value can be related to some other IRs, we
   * need a callback function that could correctly "notify" the caller whether
   * the source variable (src) should be written by the result (dst); thus we
   * could delete useless branches.
   *
   * @param callback A callback function.
   * @param chained
   * @return is_chained
   */
  bool emit_helper(std::function<bool(Operand* const)>&& callback,
                   const bool& chained = true) const;

  /**
   * @brief Call get_is_var().
   *
   * @param callback
   * @param chained
   * @return is_chained
   */
  bool emit_helper(decltype(&Operand::get_is_var)&& callback,
                   const bool& chained = true) const;

  /**
   * @brief The @ref{compiler::ir::IR::emit_ir} funciton will iterator over each
   * operand and emit their IRs.
   *
   * @param callback A lambda expression or a function object: the callback
   * function.
   * @param chained    Denote whether the result is related to another IR.
   *                   Should be evaluated via callback. If there is no incoming
   *                   edges, the IR could be deleted.
   */
  void walk_ir(std::function<void(Operand* const)>&& callback,
               const bool& chained = true);

 public:
  // Default constructor is definitely not allowed.
  IR() = delete;

  IR(const op_type& operation, Operand* const dst, Operand* const operand_a,
     Operand* const operand_b, Operand* const operand_c,
     const std::string& labal = "");

  IR(const op_type& operation, Operand* const dst, Operand* const operand_a,
     Operand* const operand_b, const std::string& labal = "");

  IR(const op_type& operation, Operand* const dst, Operand* const operand_a,
     const std::string& label = "");

  IR(const op_type& operation, Operand* const dst,
     const std::string& label = "");

  IR(const op_type& operation, const std::string& label = "");

  /**
   * @brief Emit the IR.
   *
   * @param out
   * @param verbose
   */
  void emit_ir(std::ostream& out = std::cout, const bool& verbose = false);

  op_type get_op_type(void) const { return type; }
} IR;

using BranchIR = std::pair<compiler::ir::op_type, compiler::ir::op_type>;

bool get_type_priority(const var_type& lhs, const var_type& rhs);

/**
 * @brief Checks if the binary expression is valid.
 *          E.g. 1 + '3',  0.4 * 5 is valid.
 *               1 + "sdadas" is not valid.
 *
 * @param lhs
 * @param rhs
 * @return true
 * @return false
 */
bool check_valid_binary(Operand* const lhs, Operand* const rhs);

/**
 * @brief Convert a heximal string to double.
 *
 * @param num
 * @return double
 */
double convert_from_string(const std::string& num);

/**
 * @brief Convert a double to hexical.
 *
 * @param num
 * @return std::string
 */
std::string convert_from_double(const double& num);

/**
 * @brief Convert a variable type to its corresponding string.
 *
 * @param type
 * @return std::string
 */
std::string var_type_to_string(const var_type& type);

/**
 * @brief Converts from a compiler::Item_literal type to operand type.
 *
 * @param value
 * @return Operand*
 */
Operand* dump_value(Item_literal* const value);
}  // namespace compiler::ir
#endif