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
#include <common/compile_excepts.hh>
#include <common/termcolor.hh>
#include <common/utils.hh>
#include <frontend/nodes/item_ident.hh>
#include <frontend/nodes/item_literal.hh>

extern uint32_t opt_level;

compiler::ir::Operand* compiler::Item_ident::eval_runtime_helper(
    compiler::ir::IRContext* const ir_context) const {
  compiler::Symbol_table* const symbol_table = ir_context->get_symbol_table();
  try {
    compiler::Symbol_const* const symbol = symbol_table->find_const(name);
    if (symbol->get_is_pointer()) {
      throw compiler::fatal_error(
          "Cannot evaluate pointer / array type. What: " + name);
    } else {
      return new ir::Operand(symbol->get_var_type(), "", symbol->get_value(),
                             false, false);
    }
  } catch (const std::exception& e) {
    compiler::Symbol* const symbol_cur = symbol_table->find_symbol(name);
    if (opt_level > 0) {
      compiler::Symbol_const* symbol_assign =
          symbol_table->find_assign_const(symbol_cur->get_name());
      return new ir::Operand(symbol_assign->get_var_type(), "",
                             symbol_assign->get_values()[0], false, false);
    } else {
      return new ir::Operand(symbol_cur->get_name());
    }
  }
}

compiler::ir::Operand* compiler::Item_ident::eval_runtime_helper(
    compiler::ir::IRContext* const ir_context,
    compiler::ir::ir_list& ir_list) const {
  compiler::Symbol_table* const symbol_table = ir_context->get_symbol_table();
  try {
    compiler::Symbol_const* const symbol =
        symbol_table->find_assign_const(name);

    if (symbol->get_is_pointer() || opt_level == 0) {
      return new compiler::ir::Operand(symbol->get_name());
    } else {
      try {
        return new ir::Operand(symbol->get_var_type(), "",
                               symbol->get_values()[0], false, false);
      } catch (const std::exception& e) {
        // Cannot dump value... We return its name.
        return new compiler::ir::Operand(name);
      }
    }
  } catch (const std::exception& e) {
    compiler::Symbol* const symbol = symbol_table->find_symbol(name);
    return new compiler::ir::Operand(symbol->get_name());
  }
}

// For generting the IR for array identifiers. E.g.: arr[4][4].
compiler::ir::Operand* compiler::Item_ident_array::eval_runtime_helper(
    compiler::ir::IRContext* const ir_context, ir::ir_list& ir_list) const {
  return array_access_helper(ir_context, ir_list, ir::op_type::LDR);
}

void compiler::Item_ident_array::assign_to_array(
    ir::IRContext* ir_context, ir::ir_list& ir_list,
    compiler::ir::Operand* const expression) const {
  array_access_helper(ir_context, ir_list, ir::op_type::STR, expression);
}

compiler::ir::Operand* compiler::Item_ident_array::eval_runtime_helper(
    compiler::ir::IRContext* const ir_context) const {
  throw;
}

compiler::ir::Operand* compiler::Item_ident_array::array_access_helper(
    compiler::ir::IRContext* const ir_context, ir::ir_list& ir_list,
    const compiler::ir::op_type& op_type,
    compiler::ir::Operand* const expression) const {
  try {
    // We need to check the symbol table. If it is undefined, an error will be
    // thrown by the search function and will be captured by try-catch block.
    compiler::Symbol* const array_symbol =
        ir_context->get_symbol_table()->find_symbol(name);
    // Check if this is an array.
    if (array_symbol->get_type() != compiler::symbol_type::ARRAY_TYPE) {
      throw compiler::unsupported_operation(
          "Error: Cannot index a non-array type!");
    }
    // Check if the shape can match the symbol.
    const size_t shape_cur = array_symbol->get_shape().size();
    if (array_shape.size() != shape_cur) {
      throw compiler::unsupported_operation(
          "Error: Array shape is of wrong size!");
    }
    // Note that we do not check if the index is out of range.
    // Checking is done by the programmer.

    // Fetch basic information.
    const ir::var_type var_type = array_symbol->get_var_type();
    const uint32_t byte_length =
        compiler::to_byte_length(compiler::to_basic_type(var_type));

    // Optimization can be done.
    if (opt_level > 0) {
      ir::Operand* const dst = new ir::Operand(compiler::concatenate(
          ir::local_sign, ir_context->get_symbol_table()->get_available_id()));
      // Determine the alignment of the array.
      uint32_t length = byte_length;
      // A pointer recording the current position.
      uint32_t index = 0;

      // Traverse the shape array in a reverse way.
      // Because in the syntax tree, all the elements are stored backwards
      // (since they are parsed from right to the left, and the length of each
      // row is determined by the column).
      for (auto iter = array_shape.crend(); iter != array_shape.crbegin();
           iter++) {
        // Get the result of the shape.
        ir::Operand* res = (*iter)->eval_runtime(ir_context, ir_list);
        const uint32_t res_num = std::stoul(res->get_value());
        // Add to the index.
        index += res_num * length;
        const uint32_t distance = std::distance(iter, array_shape.crend());
        length *= std::stoul(array_symbol->get_shape()[distance]->get_value());
        // Append to the IR list.
        ir_list.emplace_back(
            op_type, dst,
            new ir::Operand(ir::var_type::i8, "", std::to_string(index), false),
            res);

        return dst;
      }
    } else {
      // SSA: create size & index.
      const std::string size_name = compiler::concatenate(
          ir::local_sign, ir_context->get_symbol_table()->get_available_id());
      const std::string index_name = compiler::concatenate(
          ir::local_sign, ir_context->get_symbol_table()->get_available_id());
      // Create operands from them.
      ir::Operand* operand_size = new ir::Operand(size_name);
      ir::Operand* operand_index = new ir::Operand(index_name);

      // Multiply the operand index by byte_length.
      ir_list.emplace_back(
          ir::op_type::IMUL, operand_index,
          array_shape.back()->eval_runtime(ir_context, ir_list),
          OPERAND_VALUE(std::to_string(byte_length)));

      // How to get the correct index from shape and the byte_length:
      // E.g.: arr[4][4] (where arr is int type):
      // 1. Determine the alignment in the memory: 4 bytes.
      // 2. Determine the offset from the beginning of the array in the
      //    memory: 16 (in reverse order)
      // 3. Multiply 1. with 2.

      // First calculate the last bracket.
      if (array_shape.size() != 1) {
        const uint32_t size_uni =
            std::stoul(array_symbol->get_shape().back()->get_value());
        const std::string tmp = compiler::concatenate(
            ir::local_sign, ir_context->get_symbol_table()->get_available_id());
        ir::Operand* const operand_tmp = new ir::Operand(tmp);
        ir_list.emplace_back(
            ir::op_type::MOV, operand_size,
            OPERAND_VALUE(std::to_string(size_uni * byte_length)));
      }

      const uint32_t byte_length = compiler::to_byte_length(
          compiler::to_basic_type(array_symbol->get_var_type()));

      for (auto iter = array_shape.crbegin() + 1; iter != array_shape.crend();
           iter++) {
        // Get the subscript.
        ir::Operand* const subscript = (*iter)->eval_runtime(ir_context, ir_list);
        // Intermediate variable for calculating the offset.
        const std::string size_str = compiler::concatenate(
            ir::local_sign, ir_context->get_symbol_table()->get_available_id());
        const std::string offset_str = compiler::concatenate(
            ir::local_sign, ir_context->get_symbol_table()->get_available_id());
        ir::Operand* const size = new ir::Operand(size_str);
        ir::Operand* const offset = new ir::Operand(offset_str);
        // Calculate the current size.
        ir_list.emplace_back(ir::op_type::IMUL, size, operand_size, subscript);
        // Then add to the offset.
        ir_list.emplace_back(ir::op_type::IADD, offset, operand_index, size);
        operand_index = new ir::Operand(*offset);
        // Extra care for the size!
        if (iter != array_shape.crend() - 1) {
          // Create a temporary name.
          const std::string tmp = compiler::concatenate(
              ir::local_sign,
              ir_context->get_symbol_table()->get_available_id());
          // Determine the offset. We use an iterator to calculate the distance.
          const uint32_t distance =
              std::distance(iter, array_shape.crend()) - 1;
          ir::Operand* const operand_tmp = new ir::Operand(tmp);
          // Do the multiplication.
          ir_list.emplace_back(ir::op_type::IMUL, operand_tmp, operand_size,
                               array_symbol->get_shape()[distance]);
          operand_size = new ir::Operand(*operand_tmp);
        }
      }
      if (op_type == ir::op_type::STR) {
        ir::Operand* const dst = new ir::Operand(array_symbol->get_name());
        ir_list.emplace_back(op_type, dst, operand_index, expression);

        return dst;
      } else {
        // Prepare for the destination variable.
        const std::string dst_name = compiler::concatenate(
            ir::local_sign, ir_context->get_symbol_table()->get_available_id());
        ir::Operand* const dst = new ir::Operand(dst_name);
        ir_list.emplace_back(op_type, dst,
                             new ir::Operand(array_symbol->get_name()),
                             operand_index);
        return dst;
      }
    }
  } catch (const std::exception& e) {
    PANIC(lineno, e.what());
    exit(1);
  }
}