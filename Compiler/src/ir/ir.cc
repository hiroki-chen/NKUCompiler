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
#include <common/types.hh>
#include <common/utils.hh>
#include <frontend/nodes/item.hh>
#include <frontend/nodes/item_literal.hh>
#include <iomanip>
#include <ir/ir.hh>
#include <sstream>

compiler::ir::Operand::Operand()
    : type(compiler::ir::var_type::NONE),
      identifier(""),
      value(""),
      is_var(false),
      is_ptr(false) {}

// Construct an operand type from name.
compiler::ir::Operand::Operand(const std::string& identifier)
    : type(compiler::ir::var_type::NONE),
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
      label(label) {}

compiler::ir::IR::IR(const op_type& operation, Operand* const dst,
                     Operand* const operand_a, const std::string& label)
    : type(operation),
      dst(dst),
      operand_a(operand_a),
      operand_b(nullptr),
      operand_c(nullptr),
      label(label) {}

compiler::ir::IR::IR(const op_type& operation, Operand* const dst,
                     const std::string& label)
    : type(operation),
      dst(dst),
      operand_a(nullptr),
      operand_b(nullptr),
      operand_c(nullptr),
      label(label) {}

compiler::ir::IR::IR(const op_type& operation, const std::string& label)
    : type(operation),
      dst(nullptr),
      operand_a(nullptr),
      operand_b(nullptr),
      operand_c(nullptr),
      label(label) {}

void compiler::ir::IR::emit_ir(std::ostream& output, const bool& verbose) {
  // Wrap std::ostream in a macro.
  FORMAT(output, op_name[type], 0x10);

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

  FORMAT(output, label + "\n", 0);
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
  if (lhs->get_type() == compiler::ir::var_type::NONE ||
      lhs->get_type() == compiler::ir::var_type::NONE) {
    return false;
  } else if ((lhs->get_is_ptr() & rhs->get_is_var()) == 0) {
    return false;
  }
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