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
#ifndef CONTEXT_HH
#define CONTEXT_HH

#include <frontend/symbol_table/symbol_table.hh>
#include <map>
#include <stack>

namespace compiler::ir {

using phi_tag = std::map<std::pair<uint32_t, std::string>, std::string>;

using phi_block_type = std::stack<phi_tag>;

/**
 * @brief This is the context for generating intermediate representation.
 *        It may include:
 *        1) Symbol tables;
 *        2) Loop labels;
 *        3) Jump labels;
 *
 */

typedef class IRContext {
 private:
  /**
   * @brief Register some statically linked functions to the global symbol
   * table.
   *
   * @param functions
   */
  void register_library_function(
      const std::vector<std::pair<std::string, Symbol*>>& functions);

 protected:
  /**
   * @brief The context will store a symbol table within itself.
   *
   */
  Symbol_table symbol_table;

  /**
   * @brief Stack that is used to store loop labels.
   *
   */
  std::stack<std::string> loop_label;

  /**
   * @brief Temporarily stores the function name.
   *
   */
  std::string func_name;

  /**
   * @brief Stack that is used to store temporary variables for loop statement.
   *
   */
  std::stack<std::vector<std::string>> loop_variable;

 public:
  /**
   * @brief A temporary symbol table for continue statements.
   *
   */
  std::stack<std::vector<Symbol_table>> continue_symbol;

  /**
   * @brief A temporary symbol table for break statements.
   *
   */
  std::stack<std::vector<Symbol_table>> break_symbol;

  /**
   * @brief A phi block look up table for continue statement.
   * @note Usage:
   *      [<symbol_table_id>][variable_name] -> [<symbol_name>];
   *
   */
  phi_block_type continue_phi_block;

  /**
   * @brief A phi block look up table for break statement.
   *
   */
  phi_block_type break_phi_block;
  //======================= END OF VARIABLE ===================

  /**
   * @brief Construct a new IRContext object. It will also create a global
   * context?
   *
   */
  IRContext();

  /**
   * @brief Construct a new IRContext object. Dump a context.
   *
   * @param ir_context
   */
  IRContext(const IRContext& ir_context);

  virtual void set_func_name(const std::string& func_name) {
    this->func_name = func_name;
  }

  /**
   * @brief Called when a new scope is encountered and we should enter a new
   * scope.
   *
   */
  virtual void enter_scope(void);

  /**
   * @brief If a scope is left, then we need to call the function and do some
   * garbage cleaning work.
   *
   */
  virtual void leave_scope(void);

  /**
   * @brief Checks if the current context is created by a loop statement.
   *        It is used when a continue, break or other loop-related statement is
   * evaluated.
   *
   * @return true
   * @return false
   */
  virtual bool is_loop_context(void) const { return loop_label.size() != 0; }

  /**
   * @brief Check if the current context is a global context.
   * @note uuid == 0 denotes that the context is a global context.
   *
   * @return true
   * @return false
   */
  virtual bool is_global_context(void) const {
    return symbol_table.get_top_scope_uuid() == 0;
  }

  /**
   * @brief Push a loop label into the stack, and then create a new stack for
   * loop variable.
   *
   * @param label
   */
  virtual void add_loop_label(const std::string& label) {
    loop_label.push(label);
    loop_variable.push({});
  }

  /**
   * @brief Add a loop variable into the current vector.
   *
   * @param var
   */
  virtual void add_loop_var(const std::string& var) {
    loop_variable.top().emplace_back(var);
  }

  virtual void pop_loop_var(void) {
    loop_variable.pop();
    loop_label.pop();
  }

  /**
   * @brief Get the top loop label object
   *
   * @return std::string
   */
  virtual std::string get_top_loop_label(void) const {
    return loop_label.top();
  }
  /**
   * @brief Get the func name.
   *
   * @return std::string
   */
  virtual std::string get_func_name(void) const { return func_name; }

  /**
   * @brief Get the symbol table object.
   *        The outside functions and variables may need symbol_table and invoke
   * its interfaces.
   *
   * @return Symbol_table*
   */
  Symbol_table* get_symbol_table(void) { return &symbol_table; }

  /**
   * @brief Get the top variable loop vector.
   *
   * @return  std::vector<std::string>
   */
  virtual std::vector<std::string> get_top_loop_vector(void) const {
    return loop_variable.top();
  }
} IRContext;
}  // namespace compiler::ir.

#endif