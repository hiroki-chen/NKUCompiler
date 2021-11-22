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
#ifndef SYMBOL_TABLE_HH
#define SYMBOL_TABLE_HH

#include <deque>
#include <frontend/symbol_table/symbol.hh>
#include <unordered_map>

namespace compiler {

using symbol_table_type = std::unordered_map<std::string, Symbol*>;

using const_table_type = std::unordered_map<std::string, Symbol_const*>;

/**
 * @brief Class for a single symbol table.
 *
 */
typedef class Symbol_block {
 protected:
  symbol_table_type block;

 public:
  Symbol_block() = default;

  Symbol_block(const Symbol_block& symbol_block);

  virtual Symbol* find_symbol(const std::string& name);

  virtual void add_symbol(const std::string& name, Symbol* const symbol);

  virtual symbol_table_type* get_block(void) { return &block; }
} Symbol_block;

/**
 * @brief Stores some information about constant types which are needed at
 * runtime evaluation.
 *
 */
typedef class Const_block {
 protected:
  const_table_type block;

 public:
  Const_block() = default;

  Const_block(const Const_block& const_block);

  virtual Symbol_const* find_const(const std::string& name);

  virtual void add_const(const std::string& name, Symbol_const* const symbol);

  virtual const_table_type* get_block(void) { return &block; }
} Const_block;

/**
 * @brief Class for symbol table.
 *
 * @note Currently we do not take into consideration the storage of functions
 * and structs.
 *
 */
typedef class Symbol_table {
 protected:
  int last_uuid;

  /**
   * @brief This structure records the available id for local variables.
   *
   */
  uint32_t available_id;

  // Tables are pushed onto the front of the stack (here it is a list)
  std::deque<Symbol_block*> symbol_table;

  std::deque<Const_block*> const_table;

  std::deque<Const_block*> const_assign_table;

 public:
  Symbol_table() = default;

  Symbol_table(const Symbol_table& symbol_table);

  virtual ~Symbol_table();

  virtual int get_top_scope_uuid() const {
    return (int)symbol_table.size() - 1;
  }

  virtual int get_last_find_uuid(void) const { return last_uuid; }

  virtual Symbol_block* get_spec_block(const uint32_t& index);

  virtual std::deque<Symbol_block*> get_symbol_table(void) {
    return symbol_table;
  }

  virtual Symbol* find_symbol(const std::string& name);

  virtual Symbol_const* find_const(const std::string& name);

  virtual Symbol_const* find_assign_const(const std::string& name);

  virtual void add_symbol(const std::string& name, Symbol* const symbol);

  virtual void add_const(const std::string& name, Symbol_const* const symbol);

  virtual void assign_const(const std::string& name,
                            Symbol_const* const symbol);

  virtual void enter_scope();

  virtual void leave_scope();

  virtual uint32_t get_available_id(void) { return available_id++; }

  virtual void set_available_id(const uint32_t& id) { available_id = id; }
} Symbol_table;
}  // namespace compiler

#endif