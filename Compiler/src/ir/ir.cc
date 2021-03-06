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
#include <backend/analyzer.hh>
#include <backend/assembly_dispatcher.hh>
#include <backend/units.hh>
#include <common/compile_excepts.hh>
#include <common/types.hh>
#include <common/utils.hh>
#include <frontend/nodes/item.hh>
#include <frontend/nodes/item_literal.hh>
#include <iomanip>
#include <ir/ir.hh>
#include <sstream>

static std::string escape_array(const std::string& str) {
  if (str.substr(0, 1) == compiler::ir::arr_sign) {
    return str.substr(1);
  } else {
    return str;
  }
}

compiler::ir::Operand::Operand()
    : type(compiler::ir::var_type::NONE),
      identifier(""),
      value(""),
      is_var(false),
      is_ptr(false) {}

// Construct an operand type from name.
compiler::ir::Operand::Operand(const std::string& identifier,
                               const var_type& var_type)
    : type(var_type),
      identifier(identifier),
      value(""),
      is_var(true),
      is_ptr(false) {}

compiler::ir::Operand_ptr::Operand_ptr() : Operand(), shape(0) {}

compiler::ir::Operand::Operand(const var_type& type,
                               const std::string& identifier,
                               const std::string& value, const bool& is_var,
                               const bool& is_ptr)
    : type(type),
      identifier(identifier),
      value(value),
      is_var(is_var),
      is_ptr(is_ptr) {}

compiler::reg::Machine_operand* compiler::ir::Operand::emit_machine_operand(
    void) const {
  // Temporary variables and local variables can be differentiated by their
  // prefixes. TEMP: %t, VAR: %v.
  if (is_var) {
    if (identifier.find(ir::local_sign) != -1) {
      // Local.
      // Escape array identifier.
      return new reg::Machine_operand(reg::operand_type::VREG,
                                      std::move(escape_array(identifier)));
    } else if (identifier.substr(0, 1).compare(ir::global_sign) == 0) {
      // Global. => LBL.
      return new reg::Machine_operand(
          std::move(escape_array(identifier.substr(1))));
    } else if (identifier.substr(0, 1).compare(ir::arg_sign) == 0) {
      // Args
      return new reg::Machine_operand(
          reg::operand_type::REG,
          compiler::concatenate("r", identifier.back()));
    } else {
      throw compiler::fatal_error(
          "Error: Unknown error when generating machine operand!");
    }
  } else {
    return new reg::Machine_operand(reg::operand_type::IMM, value);
  }
}

compiler::ir::Operand_ptr::Operand_ptr(const var_type& type,
                                       const std::string& identifier,
                                       const std::string& value,
                                       const uint32_t& shape)
    : Operand(type, identifier, value, true), shape(shape) {}

compiler::ir::IR::IR(const op_type& operation, Operand* const dst,
                     Operand* const operand_a, Operand* const operand_b,
                     Operand* const operand_c, const std::string& label)
    : type(operation),
      dst(dst),
      operand_a(operand_a),
      operand_b(operand_b),
      operand_c(operand_c),
      label(label) {}

compiler::ir::IR::IR(const op_type& operation, Operand* const dst,
                     Operand* const operand_a, Operand* const operand_b,
                     const std::string& label)
    : type(operation),
      dst(dst),
      operand_a(operand_a),
      operand_b(operand_b),
      operand_c(nullptr),
      label(label),
      is_dead(false) {}

compiler::ir::IR::IR(const op_type& operation, Operand* const dst,
                     Operand* const operand_a, const std::string& label)
    : type(operation),
      dst(dst),
      operand_a(operand_a),
      operand_b(nullptr),
      operand_c(nullptr),
      label(label),
      is_dead(false) {}

compiler::ir::IR::IR(const op_type& operation, Operand* const dst,
                     const std::string& label)
    : type(operation),
      dst(dst),
      operand_a(nullptr),
      operand_b(nullptr),
      operand_c(nullptr),
      label(label),
      is_dead(false) {}

compiler::ir::IR::IR(const op_type& operation, const std::string& label)
    : type(operation),
      dst(nullptr),
      operand_a(nullptr),
      operand_b(nullptr),
      operand_c(nullptr),
      label(label),
      is_dead(false) {}

compiler::ir::IR::IR(const IR& ir)
    : type(ir.type),
      is_dead(ir.is_dead),
      dst(ir.dst == nullptr ? nullptr : new ir::Operand(*ir.dst)),
      operand_a(ir.operand_a == nullptr ? nullptr
                                        : new ir::Operand(*ir.operand_a)),
      operand_b(ir.operand_b == nullptr ? nullptr
                                        : new ir::Operand(*ir.operand_b)),
      operand_c(ir.operand_c == nullptr ? nullptr
                                        : new ir::Operand(*ir.operand_c)),
      label(ir.label) {}

void compiler::ir::IR::emit_machine_code(
    compiler::reg::Assembly_builder* const asm_builder) const {
  // We do not handle NOP.
  if (type == compiler::ir::op_type::NOP ||
      type == compiler::ir::op_type::WORD ||
      type == compiler::ir::op_type::SPACE || is_dead) {
    return;
  }
  // Let a dispatcher do the job.
  // const_cast<compiler::ir::IR*>(this)->emit_ir();
  compiler::Assembly_dispatcher* const dispatcher =
      compiler::Assembly_dispatcher::dispatch(type, this);

  // Handle function call.
  // Set where the return value is stored.
  if (type == compiler::ir::op_type::CALL) {
    static_cast<compiler::Assembly_dispatcher_call*>(dispatcher)
        ->set_return_virtual_reg(dst);
  }

  dispatcher->emit_machine_code(asm_builder);
}

void compiler::ir::IR::emit_ir(std::ostream& output, const bool& verbose) {
  if (type == ir::op_type::NOP || is_dead) {
    return;
  }
  // Wrap std::ostream in a macro.
  if (type == ir::op_type::FUNC || type == ir::op_type::GLOBAL_BEGIN) {
    FORMAT(output, op_name[type], 0x10);
  } else if (type == ir::op_type::LBL) {
    output << '\n';
  } else if (type == ir::op_type::END_FUNC || type == ir::op_type::GLOBAL_END) {
    FORMAT(output, op_name[type], 0x10);
  } else {
    FORMAT(output, std::string("  ") + op_name[type], 0x10);
  }

  // Emit IR of each operand. Deepmost callee.
  auto lambda_walk_ir = [&output, this](Operand* const operand) {
    if (operand != nullptr) {
      if (operand->get_type() == var_type::NONE) {
        FORMAT(output, operand->get_identifier(), 10);
      } else if (operand->get_is_var() == false) {
        FORMAT(output,
               var_type_to_string(operand->get_type()) + " " +
                   operand->get_value(),
               10);
      } else if (operand->get_is_var() == true) {
        FORMAT(output,
               var_type_to_string(operand->get_type()) + " " +
                   operand->get_identifier(),
               10);
      }
    }
  };
  walk_ir(lambda_walk_ir);

  if (type == ir::op_type::LBL) {
    FORMAT(output, label + ":\n", 0);
  } else {
    FORMAT(output, label + "\n", 0);
  }

  if (type == ir::op_type::END_FUNC || type == ir::op_type::GLOBAL_END) {
    output << '\n';
  }
}

void compiler::ir::IR::walk_ir(std::function<void(Operand* const)>&& callback,
                               const bool& chained) {
  emit_helper(
      [&](Operand* const operand) -> bool {
        callback(operand);
        return false;
      },
      chained);
}

bool compiler::ir::IR::emit_helper(decltype(&Operand::get_is_var)&& callback,
                                   const bool& chained) const {
  return emit_helper(
      [&](Operand* const operand) -> bool { return (operand->*callback)(); },
      chained);
}

bool compiler::ir::IR::emit_helper(
    std::function<bool(Operand* const operand)>&& callback,
    const bool& chained) const {
  // This callback function is what we created in function walk_ir and the
  // latter one is created in iterate_operand.
  return (chained && callback(dst)) || callback(operand_a) ||
         callback(operand_b) || callback(operand_c);
}

bool compiler::ir::get_type_priority(const var_type& lhs, const var_type& rhs) {
  return lhs <= rhs;
}

bool compiler::ir::check_valid_binary(compiler::ir::Operand* const lhs,
                                      compiler::ir::Operand* const rhs) {
  // TODO: Implement me!
  /*if (lhs->get_type() == compiler::ir::var_type::NONE ||
      rhs->get_type() == compiler::ir::var_type::NONE) {
    return false;
  } else if ((lhs->get_is_ptr() | rhs->get_is_var()) == 0) {
    return false;
  }*/
  return true;
}

double compiler::ir::convert_from_string(const std::string& num) {
  const uint32_t res = std::stoul(num);
  return *reinterpret_cast<const double*>(&res);
}

std::string compiler::ir::convert_from_double(const double& num) {
  uint32_t res = *reinterpret_cast<const uint32_t*>(&num);
  std::ostringstream oss;
  oss << std::ios::hex << res;
  return oss.str();
}

std::string compiler::ir::var_type_to_string(
    const compiler::ir::var_type& type) {
  switch (type) {
    case var_type::DB:
      return "DOUBLE";
    case var_type::i32:
      return "i32";
    case var_type::i8:
      return "i8";
    case var_type::NONE:
      return "";
    default:
      throw compiler::unimplemented_error(
          "This type of variable is not yet supported!");
  }
}

compiler::ir::Operand* compiler::ir::dump_value(
    compiler::Item_literal* const value) {
  switch (value->get_literal_type()) {
    case Item_literal::INT_TYPE: {
      compiler::Item_literal_int* const val_int =
          static_cast<compiler::Item_literal_int* const>(value);
      return new compiler::ir::Operand(ir::var_type::i32, "",
                                       std::to_string(val_int->get_int()),
                                       false, false);
    }

    case Item_literal::REAL_TYPE: {
      compiler::Item_literal_real* const val_real =
          static_cast<compiler::Item_literal_real* const>(value);
      return new compiler::ir::Operand(
          ir::var_type::DB, "", ir::convert_from_double(val_real->get_double()),
          false, false);
    }

    case Item_literal::CHAR_TYPE: {
      compiler::Item_literal_char* const val_char =
          static_cast<compiler::Item_literal_char* const>(value);
      return new compiler::ir::Operand(
          ir::var_type::i8, "", std::to_string((int)val_char->get_char()),
          false, false);
    }

    default:
      throw compiler::unsupported_operation(
          "Cannot dump operand from type" +
          std::to_string(value->get_literal_type()));
  }
}

compiler::Item_literal* compiler::ir::wrap_value(
    compiler::ir::Operand* const operand) {
  switch (operand->get_type()) {
    case ir::var_type::i32:
      return new compiler::Item_literal_int(0, std::stoi(operand->get_value()));
    case ir::var_type::i8:
      return new compiler::Item_literal_char(0, operand->get_value()[0]);
    case ir::var_type::DB:
      return new compiler::Item_literal_real(
          0, ir::convert_from_string(operand->get_value()));
    default:
      throw compiler::unimplemented_error("Not yet supported!");
  }
}

uint32_t compiler::ir::to_byte_length(const compiler::ir::var_type& type) {
  switch (type) {
    case ir::var_type::i32:
    case ir::var_type::DB:
      return 4;
    case ir::var_type::i8:
      return 1;
    default:
      throw compiler::unimplemented_error("Not yet supported!");
  }
}

compiler::ir::Operand::Operand(const compiler::ir::Operand& operand)
    : type(operand.type),
      identifier(operand.identifier),
      is_ptr(operand.is_ptr),
      is_var(operand.is_var),
      value(operand.value) {}

bool compiler::ir::is_jump(const op_type& op_type) {
  switch (op_type) {
    case op_type::JEQ:
    case op_type::JL:
    case op_type::JG:
    case op_type::JGE:
    case op_type::JLE:
    case op_type::JNE:
    case op_type::JMP:
      return true;
    default:
      return false;
  }
}