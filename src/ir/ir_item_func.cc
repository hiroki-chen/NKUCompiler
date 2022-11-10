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
#include <common/termcolor.hh>
#include <common/utils.hh>
#include <frontend/nodes/item_ident.hh>
#include <frontend/nodes/item_func.hh>

static void check_return_type(compiler::ir::IRContext* const ir_context,
                              compiler::ir::ir_list& ir_list,
                              const compiler::basic_type& return_type) {
  // Check return type.
  // No return type? Add it manually.
  if (ir_list.back().get_op_type() != compiler::ir::op_type::RET) {
    compiler::ir::Operand* return_value = nullptr;

    if (return_type != compiler::basic_type::VOID_TYPE) {
      return_value = new compiler::ir::Operand(
          compiler::to_ir_type(return_type), "", "0", false, false);
    }

    ir_list.emplace_back(compiler::ir::op_type::RET, return_value);
  } else {
    // Check if return type matches the definition.
    // Get the return statement first.
    const compiler::ir::IR return_ir = ir_list.back();
    const compiler::ir::Operand* const return_value = return_ir.get_dst();

    // VOID != INT...
    if (return_type == compiler::basic_type::VOID_TYPE &&
        return_value != nullptr) {
      throw compiler::unsupported_operation(
          "Error: Return type does not match the definition!");
    }
    // INT != VOID
    if (return_type != compiler::basic_type::VOID_TYPE &&
        return_value == nullptr) {
      throw compiler::unsupported_operation(
          "Error: Return type does not match the definition!");
    }
  }
}

void compiler::Item_func_def::generate_ir_helper(
    compiler::ir::IRContext* const ir_context,
    compiler::ir::ir_list& ir_list) const {
  try {
    // Reset available id.
    ir_context->get_symbol_table()->set_available_id(1ul);

    // Set the function name.
    ir_context->set_func_name(identifier->get_name());

    // Set symbol
    compiler::Symbol* const func_symbol = new compiler::Symbol(
        identifier->get_name(), compiler::symbol_type::FUNC_TYPE);
    // Set return type and parameter counts.
    func_symbol->set_var_type(compiler::to_ir_type(return_type));
    // Set argument number.
    func_symbol->set_arg_count(parameter->get_arguments().size());

    ir_context->get_symbol_table()->add_symbol(identifier->get_name(),
                                               func_symbol);
    ir_context->enter_scope();
    const size_t argument_number = parameter->get_arg_number();

    // BEGIN_FUNCTION.
    ir_list.emplace_back(ir::op_type::FUNC, nullptr,
                         new ir::Operand(ir::var_type_to_string(
                             compiler::to_ir_type(return_type))),
                         new ir::Operand(std::to_string(argument_number)),
                         ir::global_sign + identifier->get_name());

    // Generate an explicit label for CFG generation.
    ir_list.emplace_back(
        ir::op_type::LBL,
        compiler::concatenate(".LB", ir::global_sign, identifier->get_name()));

    // Get all the arguments.
    const std::vector<Item_func_def_arg*> arguments =
        parameter->get_arguments();
    for (size_t i = 0; i < argument_number; i++) {
      // Allocate variable to store the arguments.
      const compiler::Item_func_def_arg* const arg = arguments[i];
      const compiler::Item_ident* const identifier = arg->get_identifier();

      // Handle array type.
      // Currently we do not support non-array and non-variable type.
      if (identifier->get_ident_type() == Item_ident::ARRAY) {
        const compiler::Item_ident_array* const arr =
            static_cast<const compiler::Item_ident_array* const>(identifier);
        // This vector will store the shape information about the array.
        std::vector<compiler::ir::Operand*> shape;

        for (compiler::Item_expr* const shape_expr : arr->get_array_shape()) {
          // FIXME: Implement integer runtime evaluation.
          compiler::ir::Operand* const res =
              shape_expr->eval_runtime(ir_context);
          shape.emplace_back(res);
        }

        const std::string tmp = compiler::concatenate(
            compiler::ir::local_sign, compiler::ir::arr_param_sign,
            ir_context->get_symbol_table()->get_available_id());
        ir_list.emplace_back(compiler::ir::op_type::MOV,
                             new compiler::ir::Operand(tmp),
                             new compiler::ir::Operand(compiler::concatenate(
                                 compiler::ir::arg_sign, i)));

        ir_context->get_symbol_table()->add_symbol(
            identifier->get_name(),
            new compiler::Symbol(tmp, compiler::symbol_type::ARRAY_TYPE, false,
                                 shape));
      } else {
        const std::string var =
            ir::local_sign +
            std::to_string(ir_context->get_symbol_table()->get_available_id());
        ir_list.emplace_back(
            ir::op_type::MOV, new ir::Operand(var),
            new ir::Operand(compiler::concatenate(ir::arg_sign, i)));
        ir_context->get_symbol_table()->add_symbol(
            identifier->get_name(),
            new compiler::Symbol(var, compiler::symbol_type::VAR_TYPE));
      }
    }

    // Generate the IR for the function body.
    func_body->generate_ir(ir_context, ir_list);

    // Check return type.
    check_return_type(ir_context, ir_list, return_type);

    ir_list.emplace_back(ir::op_type::END_FUNC);
    ir_context->leave_scope();
  } catch (const std::exception& e) {
    std::cerr << termcolor::red << termcolor::bold << lineno << ": " << e.what()
              << termcolor::reset << '\n';
    exit(1);
  }
}

compiler::ir::Operand* compiler::Item_func_call::eval_runtime_helper(
    compiler::ir::IRContext* const ir_context,
    compiler::ir::ir_list& ir_list) const {
  // Check if the function name is valid.
  compiler::Symbol* func_symbol = nullptr;
  try {
    func_symbol =
        ir_context->get_symbol_table()->find_symbol(identifier->get_name());
  } catch (const std::exception& e) {
    std::cerr << termcolor::red << termcolor::bold << lineno << ": " << e.what()
              << termcolor::reset << '\n';
    exit(1);
  }

  // Check argument count.
  const size_t arg_count = arguments->get_arguments().size();

  if (arg_count != func_symbol->get_arg_count()) {
    throw compiler::unsupported_operation(
        "Error: The argument number is not correct!");
  }

  std::vector<ir::Operand*> operands;
  // Set to void if the return type is a void.
  const ir::var_type return_type = func_symbol->get_var_type();

  ir::Operand* const dst = new ir::Operand(
      return_type,
      ir::local_sign +
          std::to_string(ir_context->get_symbol_table()->get_available_id()),
      "", true, false);

  const std::vector<compiler::Item_expr*> args = arguments->get_arguments();

  ir::IR* const func_call =
      new ir::IR(ir::op_type::CALL, dst, identifier->get_name());

  // We first evaluate the arguments then push them into the registers in order
  // to protect the argument registers.
  std::vector<ir::Operand*> evaluated_args;

  for (uint32_t i = 0; i < args.size(); i++) {
    ir::Operand* const arg = args[i]->eval_runtime(ir_context, ir_list);
    evaluated_args.emplace_back(arg);
  }

  // Set arguments.
  for (int i = evaluated_args.size() - 1; i >= 0; i--) {
    ir::IR* const ir_arg = new ir::IR(ir::op_type::PUSH, nullptr,
                                      OPERAND_VALUE(std::to_string(i)), evaluated_args[i]);
    ir_list.emplace_back(*ir_arg);
  }

  ir_list.emplace_back(*func_call);

  return dst;
}