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

#include <stack>

namespace compiler::ir {
/**
 * @brief This is the context for generating intermediate representation.
 *        It may include:
 *        1) Symbol tables;
 *        2) Loop labels;
 *        3) Jump labels;
 * 
 */
typedef class IRContext {
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
public:
    /**
     * @brief Construct a new IRContext object. It will also create a global context?
     * 
     */
    IRContext();

    /**
     * @brief Called when a new scope is encountered and we should enter a new scope.
     * 
     */
    virtual void enter_scope(void);

    /**
     * @brief If a scope is left, then we need to call the function and do some garbage cleaning work.
     * 
     */
    virtual void leave_scope(void);
    
    /**
     * @brief Checks if the current context is created by a loop statement. 
     *        It is used when a continue, break or other loop-related statement is evaluated.
     * 
     * @return true 
     * @return false 
     */
    virtual bool is_loop_context(void) const { return loop_label.size() != 0;}

    /**
     * @brief Check if the current context is a global context.
     * @note uuid == 0 denotes that the context is a global context.
     * 
     * @return true 
     * @return false 
     */
    virtual bool is_global_context(void) const { return symbol_table.get_top_scope_uuid() == 0; }

    /**
     * @brief Get the symbol table object. 
     *        The outside functions and variables may need symbol_table and invoke its interfaces.
     * 
     * @return Symbol_table 
     */
    Symbol_table get_symbol_table(void) const { return symbol_table; }
} IRContext;
} // namespace compiler::ir.

#endif