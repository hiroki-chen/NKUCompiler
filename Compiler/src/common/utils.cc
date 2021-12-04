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
#include <sys/stat.h>

#include <common/compile_excepts.hh>
#include <common/termcolor.hh>
#include <common/utils.hh>
#include <iostream>
#include <regex>

std::string compiler::to_string(const compiler::basic_type& type) {
  switch (type) {
    case INT_TYPE:
      return "int";

    case REAL_TYPE:
      return "double";

    case VOID_TYPE:
      return "void";

    case CHAR_TYPE:
      return "char";

    case STR_TYPE:
      return "string";

    default:
      throw compiler::type_error("Unrecognized basic type!");
  }
}

std::string compiler::to_string(const compiler::unary_type& type) {
  switch (type) {
    case LNOT_TYPE:
      return "LOGIC_NOT";

    case BITNEG_TYPE:
      return "BIT_NEGATIVE";

    case UMINUS_TYPE:
      return "UNARY MINUS";

    case UADD_TYPE:
      return "UNARY ADD";

    case UDEREFER_TYPE:
      return "UNARY DEREFERENCE";

    case UREF_TYPE:
      return "UNARY REFERENCE";

    default:
      throw compiler::type_error("Unrecognized unary type!");
  }
}

std::string compiler::to_string(const compiler::binary_type& type) {
  switch (type) {
    case ADD_TYPE:
      return "Add";

    case SUB_TYPE:
      return "Sub";

    case MUL_TYPE:
      return "Mul";

    case DIV_TYPE:
      return "Div";

    case MOD_TYPE:
      return "Mod";

    case BITOR_TYPE:
      return "Bitwise_or";

    case BITAND_TYPE:
      return "Bitwise_and";

    case BITXOR_TYPE:
      return "Bitwise_xor";

    case EQ_TYPE:
      return "Conditional_equal";

    case NEQ_TYPE:
      return "Conditional_nonequal";

    case G_TYPE:
      return "Conditional_greater";

    case L_TYPE:
      return "Conditional_less";

    case GE_TYPE:
      return "Conditional_greater_or_equal";

    case LE_TYPE:
      return "Conditional_less_or_equal";

    case LOR_TYPE:
      return "Conditional_or";

    case LAND_TYPE:
      return "Conditional_and";

    default:
      throw compiler::type_error("Unrecognized binary type!");
  }
}

void compiler::print_indent(const uint32_t& indent, const bool& leaf,
                            std::ostream& os) {
  // Print indentation.
  for (uint32_t i = 0; i < indent; i += 2) {
    os << termcolor::bright_green << "│  " << termcolor::reset;
  }

  // Print node.
  if (leaf) {
    os << termcolor::bright_green << (std::string) "└──" << termcolor::reset;
  } else {
    os << termcolor::bright_green << (std::string) "├──" << termcolor::reset;
  }
}

bool compiler::is_dir(const std::string& file_name) {
  struct stat status;

  if (stat(file_name.data(), &status) == 0) {
    if (S_ISDIR(status.st_mode)) {
      return true;
    }
  } else {
    throw std::invalid_argument("Path does not exist!");
  }

  return false;
}

compiler::ir::var_type compiler::to_ir_type(const basic_type& b_type) {
  switch (b_type) {
    case basic_type::CHAR_TYPE:
      return ir::var_type::i8;
    case basic_type::INT_TYPE:
      return ir::var_type::i32;
    case basic_type::REAL_TYPE:
      return ir::var_type::DB;
    case basic_type::VOID_TYPE:
      return ir::var_type::NONE;
    default:
      throw compiler::unsupported_operation("Cannot convert this type to IR!");
  }
}

uint32_t compiler::to_byte_length(const compiler::basic_type& b_type) {
  switch (b_type) {
    case basic_type::CHAR_TYPE:
      return 1;
    case basic_type::INT_TYPE:
    case basic_type::REAL_TYPE:
      return 4;
    default:
      throw compiler::unsupported_operation(
          "Cannot convert this type to byte!");
  }
}

compiler::basic_type compiler::to_basic_type(
    const compiler::ir::var_type& v_type) {
  switch (v_type) {
    case ir::var_type::i8:
      return basic_type::CHAR_TYPE;
    case ir::var_type::i32:
      return basic_type::INT_TYPE;
    case ir::var_type::DB:
      return basic_type::REAL_TYPE;
    default:
      throw compiler::unsupported_operation(
          "Cannot convert this type to basic type!");
  }
}

compiler::reg::inst_type compiler::to_machine_type(
    const compiler::ir::op_type& type) {
  switch (type) {
    case compiler::ir::op_type::JEQ:
    case compiler::ir::op_type::JNE:
    case compiler::ir::op_type::JG:
    case compiler::ir::op_type::JGE:
    case compiler::ir::op_type::JL:
    case compiler::ir::op_type::JLE:
    case compiler::ir::op_type::JMP:
      return compiler::reg::inst_type::BRANCH;
    case compiler::ir::op_type::PHI:
    case compiler::ir::op_type::MOV:
    case compiler::ir::op_type::MOVNE:
    case compiler::ir::op_type::MOVEQ:
    case compiler::ir::op_type::MOVGT:
    case compiler::ir::op_type::MOVGE:
    case compiler::ir::op_type::MOVLT:
    case compiler::ir::op_type::MOVLE:
      return compiler::reg::inst_type::MOV;
    case compiler::ir::op_type::LDR:
    case compiler::ir::op_type::STR:
    case compiler::ir::op_type::PUSH:
      return compiler::reg::inst_type::STACK;
    case compiler::ir::op_type::CMP:
      return compiler::reg::inst_type::CMP;
    case compiler::ir::op_type::ALLOCA:
      return compiler::reg::inst_type::ALLOCA;
    case compiler::ir::op_type::IADD:
    case compiler::ir::op_type::ISUB:
    case compiler::ir::op_type::IMUL:
    case compiler::ir::op_type::IDIV:
    case compiler::ir::op_type::IMOD:
    case compiler::ir::op_type::BOR:
    case compiler::ir::op_type::BXOR:
    case compiler::ir::op_type::BAND:
      return compiler::reg::inst_type::BINARY;
    case compiler::ir::op_type::BNEG:
      return compiler::reg::inst_type::UNARY;
    case compiler::ir::op_type::RET:
      return compiler::reg::inst_type::RET;
    case compiler::ir::op_type::CALL:
      return compiler::reg::inst_type::CALL;
    default:
      std::cout << type << '\n';
      throw compiler::unsupported_operation("TODO: Support this.");
  }
}