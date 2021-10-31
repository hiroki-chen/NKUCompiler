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
#include <common/utils.hh>

#include <iostream>

std::string
compiler::to_string(const compiler::basic_type& type)
{
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

std::string
compiler::to_string(const compiler::unary_type& type)
{
    switch (type) {
    case LNOT_TYPE:
        return "LOGIC_NOT";

    case BITNEG_TYPE:
        return "BIT_NEGATIVE";

    case UMINUS_TYPE:
        return "UNARY MINUS";

    case UADD_TYPE:
        return "UNARY ADD";

    default:
        throw compiler::type_error("Unrecognized unary type!");
    }
}

std::string
compiler::to_string(const compiler::binary_type& type)
{
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

void compiler::print_indent(const uint32_t& indent, const bool& leaf, std::ostream& os)
{
    // Print indentation.
    for (uint32_t i = 0; i < indent; i++) {
        os << "│  ";
    }

    // Print node.
    if (leaf) {
        os << (std::string)"└──";
    } else {
        os << (std::string)"├──";
    }
}
