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
#include <frontend/nodes/item.hh>
#include <ir/ir.hh>

#include <iomanip>

compiler::ir::Operand::Operand(
    const var_type& type,
    const std::string& identifier,
    const std::string& value,
    const bool& is_var,
    const bool& is_ptr)
    : type(type)
    , identifier(identifier)
    , value(value)
    , is_var(is_var)
    , is_ptr(is_ptr)
{
}

compiler::ir::Operand_ptr::Operand_ptr(
    const var_type& type,
    const std::string& identifier,
    const std::string& value,
    const uint32_t& shape)
    : Operand(type, identifier, value, true)
    , shape(shape)
{
}

compiler::ir::IR::IR(
    const op_type& operation,
    Operand* const dst,
    Operand* const operand_a,
    Operand* const operand_b,
    Operand* const operand_c,
    const std::string& label)
    : type(operation)
    , dst(dst)
    , operand_a(operand_a)
    , operand_b(operand_b)
    , operand_c(operand_c)
    , label(label)
{
}

compiler::ir::IR::IR(
    const op_type& operation,
    Operand* const dst,
    Operand* const operand_a,
    Operand* const operand_b,
    const std::string& label)
    : type(operation)
    , dst(dst)
    , operand_a(operand_a)
    , operand_b(operand_b)
    , operand_c(nullptr)
    , label(label)
{
}

compiler::ir::IR::IR(
    const op_type& operation,
    Operand* const dst,
    Operand* const operand_a,
    const std::string& label)
    : type(operation)
    , dst(dst)
    , operand_a(operand_a)
    , operand_b(nullptr)
    , operand_c(nullptr)
    , label(label)
{
}

compiler::ir::IR::IR(
    const op_type& operation,
    Operand* const dst,
    const std::string& label)
    : type(operation)
    , dst(dst)
    , operand_a(nullptr)
    , operand_b(nullptr)
    , operand_c(nullptr)
    , label(label)
{
}

void compiler::ir::IR::emit_ir(std::ostream& output, const bool& verbose)
{
    // Wrap std::ostream in a macro.
    FORMAT(output, op_name[type]);

    // Emit IR of each operand. Deepmost callee.
    auto lambda_walk_ir = [&](Operand* const operand) {
        if (operand == nullptr) {
            output << "\t" << label;
            return;
        }

        const bool is_var = operand->get_is_var();
        output << (is_var == true ? operand->get_identifier() : operand->get_value())
               << "\t" << label << std::endl;
    };

    walk_ir(lambda_walk_ir);
}

void compiler::ir::IR::walk_ir(std::function<void(Operand* const)>&& callback, const bool& chained)
{
    emit_helper([&](Operand* const operand) -> bool {
        callback(operand);
        return false;
    },
        chained);
}

bool compiler::ir::IR::emit_helper(
    decltype(&Operand::get_is_var)&& callback,
    const bool& chained) const
{
    return emit_helper([&](Operand* const operand) -> bool {
        return (operand->*callback)();
    },
        chained);
}

bool compiler::ir::IR::emit_helper(
    std::function<bool(Operand* const operand)>&& callback,
    const bool& chained) const
{
    // This callback function is what we created in function walk_ir and the latter one is created in iterate_operand.
    return (chained && callback(dst)) || callback(operand_a) || callback(operand_b) || callback(operand_c);
}