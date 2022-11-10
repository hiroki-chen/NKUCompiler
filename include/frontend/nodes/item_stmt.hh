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
#ifndef ITEM_STMT_HH
#define ITEM_STMT_HH

#include <frontend/nodes/item_expr.hh>
#include <frontend/nodes/item_ident.hh>
#include <vector>

namespace compiler {

typedef class Item_stmt : public Item_expr {
 protected:
  virtual ir::Operand* eval_runtime_helper(
      compiler::ir::IRContext* const ir_context,
      compiler::ir::ir_list& ir_list) const override;

 public:
  typedef enum stmt_type {
    ASSIGN_STMT,
    EIF_STMT,
    WHILE_STMT,
    BREAK_STMT,
    CONTINUE_STMT,
    FOR_STMT,
    RETURN_STMT,
    BLOCK,
    DECL_STMT,
    EVAL_STMT,
    VOID_STMT,
    POSTFIX_STMT,
    STRUCT_BODY,
  } stmt_type;

  Item_stmt() = delete;

  Item_stmt(const uint32_t& lineno);

  virtual Item_expr::expr_type get_expr_type(void) const override {
    return Item_expr::expr_type::STMT_TYPE;
  }

  virtual Item_stmt::stmt_type get_stmt_type(void) const = 0;

  virtual ~Item_stmt() override = default;
} Item_stmt;

/**
 * @brief Class for assignment
 *
 */
typedef class Item_stmt_assign final : public Item_stmt {
 protected:
  Item_ident* const identifier;

  Item_expr* const expression;

  virtual void generate_ir_helper(
      compiler::ir::IRContext* const ir_context,
      compiler::ir::ir_list& ir_list) const override;

  virtual ir::Operand* eval_runtime_helper(
      compiler::ir::IRContext* const ir_context) const override;

  virtual ir::Operand* eval_runtime_helper(
      compiler::ir::IRContext* const ir_context,
      compiler::ir::ir_list& ir_list) const override;

 public:
  Item_stmt_assign() = delete;

  Item_stmt_assign(const uint32_t& lineno, Item_ident* const identifier,
                   Item_expr* const expression);

  virtual Item_stmt::stmt_type get_stmt_type(void) const override {
    return Item_stmt::stmt_type::ASSIGN_STMT;
  }

  virtual std::string print_result(uint32_t indent,
                                   std::vector<bool> should_grow_this,
                                   bool leaf) const override;

  virtual ~Item_stmt_assign() override = default;
} Item_stmt_assign;

/**
 * @brief Class for if-else statement.
 *
 */
typedef class Item_stmt_eif final : public Item_stmt {
 protected:
  Item_expr_cond* const condition;

  Item_stmt* const if_branch;

  Item_stmt* const else_branch;

  virtual void generate_ir_helper(
      compiler::ir::IRContext* const ir_context,
      compiler::ir::ir_list& ir_list) const override;

 public:
  Item_stmt_eif() = delete;

  /**
   * @brief Construct a new Item_stmt_eif object
   *
   * @param lineno
   * @param condition
   * @param if_branch
   * @param else_branch
   */
  Item_stmt_eif(const uint32_t& lineno, Item_expr_cond* const condition,
                Item_stmt* const if_branch, Item_stmt* const else_branch);

  virtual Item_stmt::stmt_type get_stmt_type(void) const override {
    return Item_stmt::stmt_type::EIF_STMT;
  }

  virtual std::string print_result(uint32_t indent,
                                   std::vector<bool> should_grow_this,
                                   bool leaf) const override;

  virtual ~Item_stmt_eif() override = default;
} Item_stmt_eif;

/**
 * @brief Class for while statement
 *
 */
typedef class Item_stmt_while final : public Item_stmt {
 protected:
  Item_expr_cond* const condition;

  Item_stmt* const statement;  // while body

  const bool is_do_while;

  /**
   * @brief Generate the IR for while block.
   * @note The structure of the while block (also the same for 'for' statement.)
   * is given as follows:
   * .LB_scope_LOOP_BEGIN:
   * .LB_scope_COND:
   *      CMP
   *      JNE DO
   *      PHI_MOVE
   *      JEQ END
   * .LB_scope_DO:
   *      DO_SOMETHING
   *      PHI_MOVE
   *      BREAK
   *      PHI_MOVE
   *      CONITNUE
   * .LB_scope_CONITNUE:
   *      JMP COND
   * .LB_scope_END:
   *
   * @note Insert phi_move before `JEQ END`、`break`、`continue`.
   *
   * @param context
   * @param ir_list
   */
  virtual void generate_ir_helper(
      compiler::ir::IRContext* const ir_context,
      compiler::ir::ir_list& ir_list) const override;

 public:
  Item_stmt_while() = delete;

  Item_stmt_while(const uint32_t& lineno, Item_expr_cond* const condition,
                  Item_stmt* const statement, const bool& is_do_while = false);

  virtual Item_stmt::stmt_type get_stmt_type(void) const override {
    return Item_stmt::stmt_type::WHILE_STMT;
  }

  virtual std::string print_result(uint32_t indent,
                                   std::vector<bool> should_grow_this,
                                   bool leaf) const override;

  virtual ~Item_stmt_while() override = default;
} Item_stmt_while;

/**
 * @brief Class for break statement.
 *
 */
typedef class Item_stmt_break final : public Item_stmt {
 protected:
  virtual void generate_ir_helper(ir::IRContext* const ir_context,
                                  ir::ir_list& ir_list) const override;

 public:
  Item_stmt_break() = delete;

  Item_stmt_break(const uint32_t& lineno);

  virtual Item_stmt::stmt_type get_stmt_type(void) const override {
    return Item_stmt::stmt_type::BREAK_STMT;
  }

  virtual std::string print_result(uint32_t indent,
                                   std::vector<bool> should_grow_this,
                                   bool leaf) const override;

  virtual ~Item_stmt_break() override = default;
} Item_stmt_break;

/**
 * @brief Class for continue statement
 *
 */
typedef class Item_stmt_continue final : public Item_stmt {
 protected:
  virtual void generate_ir_helper(ir::IRContext* const ir_context,
                                  ir::ir_list& ir_list) const override;

 public:
  Item_stmt_continue() = delete;

  Item_stmt_continue(const uint32_t& lineno);

  virtual Item_stmt::stmt_type get_stmt_type() const override {
    return Item_stmt::stmt_type::CONTINUE_STMT;
  }

  virtual std::string print_result(uint32_t indent,
                                   std::vector<bool> should_grow_this,
                                   bool leaf) const override;

  virtual ~Item_stmt_continue() override = default;
} Item_stmt_continue;

/**
 * @brief Class for return statement
 *
 */
typedef class Item_stmt_return final : public Item_stmt {
 protected:
  Item_expr* const expr;

  virtual void generate_ir_helper(
      compiler::ir::IRContext* const ir_context,
      compiler::ir::ir_list& ir_list) const override;

 public:
  Item_stmt_return() = delete;

  Item_stmt_return(
      const uint32_t& lineno,
      Item_expr* const expr = nullptr /* for void function, it can be null*/);

  virtual Item_stmt::stmt_type get_stmt_type(void) const override {
    return Item_stmt::stmt_type::RETURN_STMT;
  }

  virtual std::string print_result(uint32_t indent,
                                   std::vector<bool> should_grow_this,
                                   bool leaf) const override;

  virtual ~Item_stmt_return() override = default;
} Item_stmt_return;

/**
 * @brief Class for nothing.
 *
 */
typedef class Item_stmt_void final : public Item_stmt {
 protected:
  virtual void generate_ir_helper(
      compiler::ir::IRContext* const ir_context,
      compiler::ir::ir_list& ir_list) const override;

 public:
  Item_stmt_void() = delete;

  Item_stmt_void(const uint32_t& lineno);

  virtual Item_stmt::stmt_type get_stmt_type(void) const override {
    return Item_stmt::stmt_type::VOID_STMT;
  }

  virtual std::string print_result(uint32_t indent,
                                   std::vector<bool> should_grow_this,
                                   bool leaf) const override;

  virtual ~Item_stmt_void() override = default;
} Item_stmt_void;

typedef class Item_stmt_eval final : public Item_stmt {
 protected:
  Item_expr* const expression;

  virtual compiler::ir::Operand* eval_runtime_helper(
      compiler::ir::IRContext* const ir_context,
      compiler::ir::ir_list& ir_list) const override {
    return expression->eval_runtime(ir_context, ir_list);
  }

  virtual compiler::ir::Operand* eval_runtime_helper(
      compiler::ir::IRContext* const ir_context) const override {
    return expression->eval_runtime(ir_context);
  }

  virtual void generate_ir_helper(
      compiler::ir::IRContext* const ir_context,
      compiler::ir::ir_list& ir_list) const override {
    eval_runtime(ir_context, ir_list);
  }

 public:
  virtual Item_stmt::stmt_type get_stmt_type(void) const override {
    return Item_stmt::stmt_type::EVAL_STMT;
  }

  virtual std::string print_result(uint32_t indent,
                                   std::vector<bool> should_grow_this,
                                   bool leaf) const override;

  Item_stmt_eval() = delete;

  Item_stmt_eval(const uint32_t& lineno, Item_expr* const expression);

  virtual ~Item_stmt_eval() override = default;
} Item_stmt_eval;

typedef class Item_stmt_postfix final : public Item_stmt {
 protected:
  const binary_type type;  // ++ / --

  Item_ident* const identifier;

  virtual void generate_ir_helper(
      compiler::ir::IRContext* const ir_context,
      compiler::ir::ir_list& ir_list) const override;

  virtual compiler::ir::Operand* eval_runtime_helper(
      compiler::ir::IRContext* const ir_context) const override;

  virtual compiler::ir::Operand* eval_runtime_helper(
      compiler::ir::IRContext* const ir_context,
      compiler::ir::ir_list& ir_list) const override;

 public:
  virtual Item_stmt::stmt_type get_stmt_type(void) const override {
    return Item_stmt::stmt_type::POSTFIX_STMT;
  }

  virtual std::string print_result(uint32_t indent,
                                   std::vector<bool> should_grow_this,
                                   bool leaf) const override;

  Item_stmt_postfix() = delete;

  Item_stmt_postfix(const uint32_t& lineno, Item_ident* const identifier,
                    const binary_type& type);

  virtual ~Item_stmt_postfix() override = default;
} Item_stmt_postfix;

/**
 * @brief Class for block.
 *
 */
typedef class Item_block final : public Item_stmt {
 protected:
  std::vector<Item_stmt*> statements;  // Block body.

  virtual void generate_ir_helper(
      compiler::ir::IRContext* const ir_context,
      compiler::ir::ir_list& ir_list) const override;

 public:
  Item_block() = delete;

  Item_block(const uint32_t& lineno);

  virtual void add_item(Item_stmt* const statement);

  virtual Item_stmt::stmt_type get_stmt_type() const override {
    return Item_stmt::stmt_type::BLOCK;
  }

  virtual std::string print_result(uint32_t indent,
                                   std::vector<bool> should_grow_this,
                                   bool leaf) const override;

  virtual ~Item_block() override = default;
} Item_block;

/**
 * @brief Create phi blocks for real context based on the information collected
 * in the fake context.
 *
 * @param ir_context_fake
 * @param ir_context_real
 * @param ir_context_dst
 */
void handle_phi_move(ir::IRContext* const ir_context_fake,
                     ir::IRContext* const ir_context_real,
                     ir::IRContext* const ir_context_dst);

void handle_phi_move(ir::IRContext* const ir_context, const bool& type = false);
}  // namespace compiler

#endif