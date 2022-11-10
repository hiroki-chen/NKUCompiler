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
#define FORMAT(output, str, width) \
  { output << std::setw(width) << std::left << str; }
#endif

#ifndef OPERAND_VALUE
#define OPERAND_VALUE(val) \
  new compiler::ir::Operand(ir::var_type::i32, "", val, false, false)
#endif

namespace compiler {
namespace reg {
// Prevent circular includes.
class Assembly_builder;
class Machine_instruction;
class Machine_operand;
}  // namespace reg

namespace ir {
// Forward declaration.
class IR;

static const std::string global_sign = "@";

static const std::string local_sign = "%t";

static const std::string arg_sign = "$";

static const std::string arr_sign = "&";

static const std::string arr_param_sign = "*";

using ir_list = std::vector<IR>;
/**
 * @brief Look-up table for enum type compiler::ir::op_type.
 *
 */
static const char* op_name[]{
    "PUSH",
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
    "JL",
    "JG",

    // Bit operations.
    "AND",
    "OR",
    "XOR",
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
    "LDR",
    "STR",
    "MALLOC",

    // Delimiters.
    "GLOBAL_BEGIN",
    "GLOBAL",
    "SPACE",
    "GLOBAL_END",
    "FUNC",
    "END_FUNC",
    "BEGIN_STRUCT",
    "END_STRUCT",

    // Jump labels.
    "LBL",

    // PHI
    "PHI",
    "MOVNE",
    "MOVEQ",
    "MOVGT",
    "MOVLT",
    "MOVGE",
    "MOVLE",

    // Alloca.
    "ALLOCA",
    "WORD",
};
/**
 * @brief Defines different operations.
 *
 */
typedef enum op_type {
  PUSH,
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
  JL,
  JG,

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
  LDR,
  STR,
  MALLOC,

  // Delimiters.
  GLOBAL_BEGIN,
  GLOBAL,
  SPACE,
  GLOBAL_END,
  FUNC,
  END_FUNC,
  BEGIN_STRUCT,
  END_STRUCT,

  // Jump labels.
  LBL,
  PHI,

  // MOV CONDITIONAL.
  MOVNE,
  MOVEQ,
  MOVGT,
  MOVLT,
  MOVGE,
  MOVLE,

  // Declare,
  ALLOCA,
  WORD,
} op_type;

/**
 * @brief Base class for operand in the IR.
 *
 */
typedef class Operand {
 protected:
  var_type type;

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

  Operand(const Operand& operand);

  Operand(const std::string& name, const var_type& var_type = NONE);

  Operand(const var_type& type, const std::string& identifier,
          const std::string& value, const bool& is_var = true,
          const bool& is_ptr = false);

  virtual var_type get_type(void) const { return type; }

  virtual bool get_is_ptr(void) const { return is_ptr; }

  virtual bool get_is_var(void) const { return is_var; }

  virtual std::string get_identifier(void) const { return identifier; }

  virtual std::string get_value(void) const { return value; }

  virtual void set_var_type(const var_type& type) { this->type = type; }

  virtual reg::Machine_operand* emit_machine_operand(void) const;

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

  bool is_dead;

  uint32_t lineno;

  /**
   * @brief Used to generate phi_move type.
   *
   */
  std::vector<IR>::iterator phi;

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

 public:
  // Default constructor is definitely not allowed.
  IR() = delete;

  IR(const IR& ir);

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

  /**
   * @brief Emit the machine code. IR -> Machine code.
   *
   * @param asm_builder
   */
  void emit_machine_code(reg::Assembly_builder* const asm_builder) const;

  void set_phi_block(const ir::ir_list::iterator& phi_block) {
    phi = phi_block;
  }

  void set_dead(void) { is_dead = true; }

  ir::ir_list::iterator get_phi_block(void) const { return phi; }

  op_type get_op_type(void) const { return type; }

  Operand* get_dst(void) const { return dst; }

  Operand* get_op1(void) const { return operand_a; }

  Operand* get_op2(void) const { return operand_b; }

  Operand* get_op3(void) const { return operand_c; }

  std::string get_label(void) const { return label; }

  bool get_is_dead(void) const { return is_dead; }
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
 * @brief Get alignment in memory
 *
 * @param type
 * @return uint32_t
 */
uint32_t to_byte_length(const var_type& type);

/**
 * @brief Check if the operation type is jump-related.
 *
 * @param op_type
 * @return true
 * @return false
 */
bool is_jump(const op_type& op_type);
}  // namespace ir
}  // namespace compiler
#endif