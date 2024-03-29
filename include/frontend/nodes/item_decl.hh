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
#ifndef ITEM_DECL_HH
#define ITEM_DECL_HH

#include <common/types.hh>
#include <frontend/nodes/item.hh>
#include <frontend/nodes/item_func.hh>
#include <frontend/nodes/item_literal.hh>
#include <frontend/nodes/item_stmt.hh>
#include <frontend/nodes/item_struct.hh>
#include <memory>
#include <vector>

namespace compiler {
class Item_struct_body;
/**
 * @brief Class for declaration. BUT THIS NOT A DECLARE STATEMENT.
 *
 */
typedef class Item_decl : public Item {
 protected:
  const bool
      is_decl;  // This differentiates between DEFINITION AND DECLARATION.

  virtual void generate_ir_helper(compiler::ir::IRContext* const ir_context,
                                  compiler::ir::ir_list& ir_list,
                                  const basic_type& b_type) const {
    throw;
  }

 public:
  typedef enum decl_type {
    VARIABLE,
    ARRAY,
    FUNCTION,
    POINTER,
    STRUCT
  } decl_type;
  Item_decl() = delete;

  Item_decl(const uint32_t& lineno, const bool& is_decl);

  virtual bool get_is_decl(void) const { return is_decl; }

  virtual Item::type get_type(void) const override {
    return Item::type::DECLARE_ITEM;
  }

  virtual Item_decl::decl_type get_decl_type(void) const = 0;

  /**
   * @brief For declaration, basic_type must be given in order to determine
   * which type it is.
   * @note This function can ONLY be called by compiler::Item_stmt_decl.
   *
   * @param ir_context
   * @param ir_list
   * @param b_type
   */
  virtual void generate_ir(compiler::ir::IRContext* const ir_context,
                           compiler::ir::ir_list& ir_list,
                           const basic_type& b_type) const;

  virtual ~Item_decl() override = default;
} Item_decl;

typedef class Item_stmt_decl : public Item_stmt {
 protected:
  std::vector<Item_decl*> declarations;

  const basic_type type;

  /**
   * @brief Note that this function will invoke compiler::Item_decl::generate_ir
   * with compiler::basic_type specified.
   *
   * @param ir_context
   * @param ir_list
   */
  virtual void generate_ir_helper(
      compiler::ir::IRContext* const ir_context,
      compiler::ir::ir_list& ir_list) const override;

 public:
  virtual Item_stmt::stmt_type get_stmt_type(void) const override {
    return Item_stmt::stmt_type::DECL_STMT;
  }

  virtual void add_declaration(Item_decl* const declaration);

  virtual std::vector<Item_decl*> get_declarataions(void) const {
    return declarations;
  }

  virtual std::string print_result(uint32_t indent,
                                   std::vector<bool> should_grow_this,
                                   bool leaf) const override;

  Item_stmt_decl() = delete;

  Item_stmt_decl(const uint32_t& lineno, const basic_type& type);
} Item_stmt_decl;

/**
 * @brief Class for declaraction of variables.
 *
 */
typedef class Item_decl_var : public Item_decl {
 protected:
  Item_ident* const identifier;

  virtual void generate_ir_helper(compiler::ir::IRContext* const ir_context,
                                  compiler::ir::ir_list& ir_list,
                                  const basic_type& b_type) const override;

 public:
  Item_decl_var() = delete;

  Item_decl_var(const uint32_t& lineno, Item_ident* const identifier,
                const bool& is_decl = true);

  virtual std::string print_result(uint32_t indent,
                                   std::vector<bool> should_grow_this,
                                   bool leaf) const override;

  virtual Item_ident* get_identifier(void) const { return identifier; }

  virtual Item_decl::decl_type get_decl_type(void) const override {
    return Item_decl::decl_type::VARIABLE;
  }

  virtual ~Item_decl_var() override = default;
} Item_decl_var;

typedef class Item_decl_pointer : public Item_decl {
 protected:
  Item_ident_pointer* const identifier;

 public:
  Item_decl_pointer() = delete;

  Item_decl_pointer(const uint32_t& lineno,
                    Item_ident_pointer* const identifier,
                    const bool& is_decl = true);

  virtual Item_decl::decl_type get_decl_type(void) const override {
    return Item_decl::decl_type::POINTER;
  }

  virtual std::string print_result(uint32_t indent,
                                   std::vector<bool> should_grow_this,
                                   bool leaf) const override;

  virtual ~Item_decl_pointer() override = default;
} Item_decl_pointer;

typedef class Item_decl_pointer_init final : public Item_decl_pointer {
 protected:
  Item_expr* const expression;  // Init value.

  const bool is_const;

 public:
  Item_decl_pointer_init() = delete;

  Item_decl_pointer_init(const uint32_t& lineno,
                         Item_ident_pointer* const identifier,
                         Item_expr* const expression, const bool& is_const,
                         const bool& is_decl = false);

  virtual void generate_ir(compiler::ir::IRContext* const ir_context,
                           compiler::ir::ir_list& ir_list) const override {
    return;
  }

  virtual bool get_is_const(void) const { return is_const; }

  virtual Item_expr* get_expression(void) const { return expression; }

  virtual std::string print_result(uint32_t indent,
                                   std::vector<bool> should_grow_this,
                                   bool leaf) const override;

  virtual ~Item_decl_pointer_init() override = default;

} Item_decl_pointer_init;

/**
 * @brief Class for declaration of variables with initial value.
 *
 */
typedef class Item_decl_var_init final : public Item_decl_var {
 protected:
  Item_expr* const expression;  // Init value.

  const bool is_const;

  virtual void generate_ir_helper(ir::IRContext* const ir_context,
                                  ir::ir_list& ir_list,
                                  const basic_type& b_type) const override;

 public:
  virtual bool get_is_const(void) const { return is_const; }

  virtual Item_expr* get_expression(void) const { return expression; }

  virtual std::string print_result(uint32_t indent,
                                   std::vector<bool> should_grow_this,
                                   bool leaf) const override;

  Item_decl_var_init() = delete;

  Item_decl_var_init(const uint32_t& lineno, Item_ident* const identifier,
                     Item_expr* const expression, const bool& is_const,
                     const bool& is_decl = false);

  virtual ~Item_decl_var_init() override = default;
} Item_decl_var_init;

/**
 * @brief Class for declaraction of variables.
 *
 */
typedef class Item_decl_array : public Item_decl {
 protected:
  Item_ident_array* const identifier;

  virtual void generate_ir_helper(compiler::ir::IRContext* const ir_context,
                                  compiler::ir::ir_list& ir_list,
                                  const basic_type& b_type) const override;

  virtual uint32_t calculate_array_size(
      compiler::ir::IRContext* const ir_context, compiler::ir::ir_list& ir_list,
      const basic_type& b_type, std::vector<ir::Operand*>& shape) const;

 public:
  Item_decl_array() = delete;

  Item_decl_array(const uint32_t& lineno, Item_ident_array* const identifier,
                  const bool& is_decl = true);

  virtual Item_ident* get_identifier(void) const { return identifier; }

  virtual Item_decl::decl_type get_decl_type(void) const override {
    return Item_decl::decl_type::ARRAY;
  }

  virtual std::string print_result(uint32_t indent,
                                   std::vector<bool> should_grow_this,
                                   bool leaf) const override;

  virtual ~Item_decl_array() override = default;
} Item_decl_array;

typedef class Item_decl_array_init final : public Item_decl_array {
 protected:
  const bool is_const;

  Item_literal_array_init* const init_value;

  virtual void generate_ir_helper(compiler::ir::IRContext* const ir_context,
                                  compiler::ir::ir_list& ir_list,
                                  const basic_type& b_type) const override;

  /**
   * @brief Recursively handle the initial values for an array. There could be
   * nested initial values.
   *
   * @param value_list
   * @param init_value
   * @param index
   * @param ir_context
   * @param ir_list
   * @param var_type
   */
  virtual void init_helper(
      const std::vector<compiler::Item_literal_array_init*> value_list,
      std::vector<compiler::ir::Operand*>& init_value, const uint32_t& index,
      compiler::ir::IRContext* const ir_context, compiler::ir::ir_list& ir_list,
      const compiler::ir::var_type& var_type) const;

 public:
  virtual bool get_is_const(void) const { return is_const; }

  virtual Item_literal_array_init* get_initial_value(void) const {
    return init_value;
  }

  Item_decl_array_init() = delete;

  Item_decl_array_init(const uint32_t& lineno,
                       Item_ident_array* const identifier,
                       Item_literal_array_init* const init_value,
                       const bool& is_const, const bool& is_decl = false);

  virtual std::string print_result(uint32_t indent,
                                   std::vector<bool> should_grow_this,
                                   bool leaf) const override;

  virtual ~Item_decl_array_init() override = default;
} Item_decl_array_init;

typedef class Item_decl_struct final : public Item_decl {
 protected:
  Item_struct_body* const struct_body;
  // Identifier
  Item_ident* const identifier;

 public:
  Item_decl_struct() = delete;

  Item_decl_struct(const uint32_t& lineno, Item_ident* const identifier,
                   Item_struct_body* const struct_body,
                   const bool& is_decl = true);

  virtual void generate_ir(compiler::ir::IRContext* const ir_context,
                           compiler::ir::ir_list& ir_list) const override {
    return;
  }

  virtual std::string print_result(uint32_t indent,
                                   std::vector<bool> should_grow_this,
                                   bool leaf) const override;

  virtual Item_decl::decl_type get_decl_type(void) const override {
    return Item_decl::decl_type::STRUCT;
  }

  virtual ~Item_decl_struct() override = default;
} Item_decl_struct;
}  // namespace compiler

#endif