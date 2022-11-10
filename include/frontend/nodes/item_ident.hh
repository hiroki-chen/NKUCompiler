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
#ifndef ITEM_IDENT_HH
#define ITEM_IDENT_HH

#include <frontend/nodes/item_expr.hh>
#include <string>
#include <vector>

namespace compiler {

/**
 * @brief Class for identifiers.
 *
 */
typedef class Item_ident : public Item_expr {
 protected:
  const std::string name;

  virtual compiler::ir::Operand* eval_runtime_helper(
      compiler::ir::IRContext* const ir_context) const override;

  virtual compiler::ir::Operand* eval_runtime_helper(
      compiler::ir::IRContext* const ir_context,
      compiler::ir::ir_list& ir_list) const override;

 public:
  typedef enum ident_type { VARIABLE, POINTER, ARRAY, FUNCTION } ident_type;

  virtual Item_expr::expr_type get_expr_type(void) const override {
    return Item_expr::expr_type::IDENTIFIER_TYPE;
  }

  virtual std::string get_name(void) const { return name; }

  Item_ident() = delete;

  Item_ident(const uint32_t& lineno, const std::string& name);

  virtual Item_ident::ident_type get_ident_type(void) const {
    return Item_ident::ident_type::VARIABLE;
  }

  virtual std::string print_result(const uint32_t& indent,
                                   const bool& leaf) const override;
} Item_ident;

/**
 * @brief Class for array identifiers.
 *
 */
typedef class Item_ident_array final : public Item_ident {
 protected:
  std::vector<Item_expr*> array_shape;

  virtual ir::Operand* eval_runtime_helper(
      ir::IRContext* const ir_context,
      ir::ir_list& ir_list) const override;

  virtual ir::Operand* eval_runtime_helper(
      ir::IRContext* ir_context) const override;

  virtual ir::Operand* array_access_helper(
      compiler::ir::IRContext* const ir_context, ir::ir_list& ir_list,
      const ir::op_type& op_type,
      compiler::ir::Operand* expression = nullptr) const;

 public:
  virtual void add_shape(Item_expr* const array_shape);

  virtual Item_ident::ident_type get_ident_type(void) const override {
    return Item_ident::ident_type::ARRAY;
  }

  virtual void generate_ir(
      compiler::ir::IRContext* const ir_context,
      compiler::ir::ir_list& ir_list) const override {
    return;
  }

  virtual void assign_to_array(ir::IRContext* ir_context,
                               ir::ir_list& ir_list,
                               compiler::ir::Operand* const expression) const;

  Item_ident_array() = delete;

  Item_ident_array(const uint32_t& lineno, const std::string& name);

  virtual std::string print_result(const uint32_t& indent,
                                   const bool& leaf) const override;

  virtual std::vector<Item_expr*> get_array_shape(void) const {
    return array_shape;
  }

  virtual ~Item_ident_array() override = default;
} Item_ident_array;

typedef class Item_ident_func final : public Item_ident {
 public:
  virtual Item_ident::ident_type get_ident_type(void) const override {
    return Item_ident::ident_type::ARRAY;
  }

  Item_ident_func() = delete;

  Item_ident_func(const uint32_t& lineno, const std::string& name);

  virtual std::string print_result(const uint32_t& indent,
                                   const bool& leaf) const override;

  virtual ~Item_ident_func() override = default;
} Item_ident_func;

/**
 * @brief Class for pointers.
 *
 */
typedef class Item_ident_pointer final : public Item_ident {
 protected:
  // This should be similar as the array.
  uint32_t shape;

 public:
  Item_ident_pointer() = delete;

  Item_ident_pointer(const uint32_t& lineno, const std::string& name);

  virtual std::string print_result(const uint32_t& indent,
                                   const bool& leaf) const override;

  virtual void add_shape(void) { shape++; };

  virtual void generate_ir(
      compiler::ir::IRContext* const ir_context,
      compiler::ir::ir_list& ir_list) const override {
    return;
  }

  virtual Item_ident::ident_type get_ident_type(void) const override {
    return Item_ident::ident_type::POINTER;
  }

  virtual ~Item_ident_pointer() override = default;
} Item_ident_pointer;
}  // namespace compiler

#endif