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
#ifndef ITEM_EXPR_HH
#define ITEM_EXPR_HH

#include <common/types.hh>
#include <frontend/nodes/item.hh>

namespace compiler {

/**
 * @brief Class for general expressions.
 *
 */
typedef class Item_expr : public Item {
 protected:
  virtual ir::BranchIR eval_cond_helper(
      compiler::ir::IRContext* const ir_context,
      compiler::ir::ir_list& ir_list) const;

  virtual ir::Operand* eval_runtime_helper(
      compiler::ir::IRContext* const ir_context) const;

  virtual ir::Operand* eval_runtime_helper(
      compiler::ir::IRContext* const ir_context,
      compiler::ir::ir_list& ir_list) const;

 public:
  typedef enum expr_type {
    STMT_TYPE,
    UNARY_TYPE,
    BINARY_TYPE,
    COND_TYPE,
    COMMA_TYPE,
    LITERAL_TYPE,
    IDENTIFIER_TYPE,
    CALL_LIST_TYPE,
    FUNC_CALL_TYPE,
    FUNC_DEF_ARG_TYPE,
    FUNC_DEF_LIST_TYPE,
    FUNC_DEF_TYPE,
  } expr_type;

  Item_expr() = delete;

  Item_expr(const uint32_t& lineno);

  virtual Item_expr::expr_type get_expr_type(void) const = 0;

  virtual Item::type get_type(void) const override {
    return Item::type::EXPR_ITEM;
  }

  /**
   * @brief Used to eval_cond conditional IR in runtime.
   *
   * @param ir_context   The IR context.
   * @param ir_list
   * @return compiler::ir::BranchIR
   */
  virtual compiler::ir::BranchIR eval_cond(
      compiler::ir::IRContext* const ir_context,
      compiler::ir::ir_list& ir_list) const;

  /**
   * @brief This function is called when optimization level is set. We calculate
   * the expression at runtime.
   *
   * @param ir_context
   * @return compiler::ir::Operand* The return value.
   * @note Since there could be different types of values, we need to return a
   * string to store it.
   */
  virtual compiler::ir::Operand* eval_runtime(
      compiler::ir::IRContext* const ir_context) const;

  /**
   * @brief Emit an operand.
   *
   * @param ir_context
   * @param ir_list
   * @return compiler::ir::Operand*
   */
  virtual compiler::ir::Operand* eval_runtime(
      compiler::ir::IRContext* const ir_context,
      compiler::ir::ir_list& ir_list) const;

  virtual ~Item_expr() override = default;
} Item_expr;

/**
 * @brief Class for conditional expressions.
 * FIXME: Maybe this is useless.
 *
 */
typedef class Item_expr_cond final : public Item_expr {
 protected:
  Item_expr* const expr;

  virtual compiler::ir::Operand* eval_runtime_helper(
      compiler::ir::IRContext* const ir_context,
      ir::ir_list& ir_list) const override;

  virtual compiler::ir::Operand* eval_runtime_helper(
      compiler::ir::IRContext* const ir_context) const override;

 public:
  virtual Item_expr::expr_type get_expr_type(void) const override {
    return Item_expr::COND_TYPE;
  }

  Item_expr_cond() = delete;

  Item_expr_cond(const uint32_t& lineno, Item_expr* const expr);

  virtual std::string print_result(uint32_t indent,
                                   std::vector<bool> should_grow_this,
                                   bool leaf) const override;

  virtual ~Item_expr_cond() override = default;
} Item_expr_cond;

typedef class Item_expr_comma final : public Item_expr {
 protected:
  std::vector<Item_expr*> expressions;

  virtual compiler::ir::Operand* eval_runtime_helper(
      compiler::ir::IRContext* const ir_context,
      compiler::ir::ir_list& ir_list) const override;

  virtual compiler::ir::Operand* eval_runtime_helper(
      compiler::ir::IRContext* const ir_context) const override;

 public:
  Item_expr_comma() = delete;

  Item_expr_comma(const uint32_t& lineno);

  virtual void add_expression(Item_expr* const expression) {
    expressions.emplace_back(expression);
  };

  virtual Item_expr::expr_type get_expr_type(void) const override {
    return Item_expr::expr_type::COMMA_TYPE;
  }

  virtual std::vector<Item_expr*> get_expressions(void) const {
    return expressions;
  }

  virtual std::string print_result(uint32_t indent,
                                   std::vector<bool> should_grow_this,
                                   bool leaf) const override;

  virtual ~Item_expr_comma() override = default;
} Item_expr_comma;

/**
 * @brief Class for binary expressions.
 *
 */
typedef class Item_expr_binary final : public Item_expr {
 protected:
  const binary_type type;

  Item_expr* const lhs;

  Item_expr* const rhs;

  virtual compiler::ir::Operand* eval_runtime_helper(
      compiler::ir::IRContext* const ir_context) const override;

  virtual compiler::ir::Operand* eval_runtime_helper(
      compiler::ir::IRContext* const ir_context,
      compiler::ir::ir_list& ir_list) const override;

  virtual compiler::ir::BranchIR eval_cond_helper(
      compiler::ir::IRContext* const ir_context,
      compiler::ir::ir_list& ir_list) const override;

 public:
  virtual Item_expr::expr_type get_expr_type(void) const override {
    return Item_expr::BINARY_TYPE;
  }

  virtual binary_type get_binary_type(void) const { return type; }

  Item_expr_binary() = delete;

  Item_expr_binary(const uint32_t& lineno, const binary_type& type,
                   Item_expr* const lhs, Item_expr* const rhs);

  virtual std::string print_result(uint32_t indent,
                                   std::vector<bool> should_grow_this,
                                   bool leaf) const override;

  virtual ~Item_expr_binary() override = default;
} Item_expr_binary;

typedef class Item_expr_unary final : public Item_expr {
 protected:
  const unary_type type;

  Item_expr* const expr;

  virtual compiler::ir::Operand* eval_runtime_helper(
      compiler::ir::IRContext* const ir_context) const override;

  virtual compiler::ir::Operand* eval_runtime_helper(
      compiler::ir::IRContext* const ir_context,
      compiler::ir::ir_list& ir_list) const override;

 public:
  virtual Item_expr::expr_type get_expr_type(void) const override {
    return Item_expr::UNARY_TYPE;
  }

  virtual unary_type get_unary_type(void) const { return type; }

  Item_expr_unary() = delete;

  Item_expr_unary(const uint32_t& lineno, const unary_type& type,
                  Item_expr* const expr);

  virtual std::string print_result(uint32_t indent,
                                   std::vector<bool> should_grow_this,
                                   bool leaf) const override;

  virtual ~Item_expr_unary() override = default;
} Item_expr_unary;
}  // namespace compiler

#endif