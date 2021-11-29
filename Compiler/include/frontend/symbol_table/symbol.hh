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
#ifndef SYMBOL_HH
#define SYMBOL_HH

#include <common/types.hh>
#include <ir/ir.hh>
#include <string>
#include <vector>

namespace compiler {
// To avoid circular includes error.
// 1. Item_literal <- compiler::symbol_table <- compiler::ir::context <-
// Item_literal
// 2. Another way is to define seperate virtual functions for each node type.
// But Item_literal is inherited from Item_expr.
class Item_literal;

/**
 * @brief Class for symbols (basic type).
 *
 */
class Symbol_table;
typedef class Symbol {
 protected:
  std::vector<ir::Operand*> shape;

  std::string name;

  const symbol_type type;

  bool is_pointer;  // Array is pointer type.

  std::string value;

  ir::var_type var_type;

  uint32_t arg_count;

 public:
  Symbol() = delete;

  Symbol(const std::string& name, const symbol_type& type,
         const bool& is_pointer = false,
         const std::vector<ir::Operand*>& shape = {},
         const ir::var_type& var_type = ir::var_type::i32);

  Symbol(const std::string& name, const symbol_type& type,
         const uint32_t& arg_count,
         const ir::var_type& var_type);  // For functions.

  Symbol(const Symbol& symbol);

  virtual void set_value(const std::string& value) { this->value = value; }

  virtual void set_var_type(const ir::var_type& type) { this->var_type = type; }

  virtual void add_shape(ir::Operand* const shape) {
    this->shape.emplace_back(shape);
  }

  virtual std::vector<ir::Operand*> get_shape(void) const { return shape; }

  virtual bool is_const(void) const { return false; }

  virtual uint32_t get_arg_count(void) const { return arg_count; }

  virtual void set_arg_count(const uint32_t& arg_count) {
    this->arg_count = arg_count;
  }

  virtual std::string get_name(void) const { return name; }

  virtual void set_name(const std::string& name) { this->name = name; }

  virtual symbol_type get_type(void) const { return type; }

  virtual bool get_is_pointer(void) const { return is_pointer; }

  virtual ir::var_type get_var_type(void) const { return var_type; }

  virtual ~Symbol() = default;
} Symbol;

typedef class Symbol_const : public Symbol {
 protected:
  std::vector<std::string> values;

  std::string value;

 public:
  Symbol_const() = delete;

  Symbol_const(const std::string& name, const symbol_type& type,
               const std::string& value, const bool& is_pointer = false,
               const std::vector<ir::Operand*>& shape = {},
               const std::vector<std::string>& values = {},
               const ir::var_type& var_type = ir::var_type::i32);

  Symbol_const(const Symbol_const& symbol_const);

  virtual bool is_const(void) const override { return true; }

  virtual std::string get_value(void) const { return value; }

  virtual std::vector<std::string> get_values(void) const { return values; }
} Symbol_const;
}  // namespace compiler

#endif