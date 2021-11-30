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
#ifndef ASSEMBLY_HH
#define ASSEMBLY_HH

#include <string>

namespace compiler::reg {
/**
 * @brief This is a auto-generated ARM-v7 assebmly template for every output
 *        file.
 *
 */
static const std::string assembly_template =
    ".macro mov32, reg, val\n"
    "    movw \\reg, #:lower16:\\val\n"
    "    movt \\reg, #:upper16:\\val\n"
    ".endm\n"
    ".macro cpu_id, rd\n"
    "    mrc	p15, 0, \\rd, c0, c0, 5\n"
    "    and	\\rd, \\rd, #0xF\n"
    ".endm\n"
    ".text\n"
    ".syntax unified\n"
    ".cpu    arm7tdmi\n";

/**
 * @brief ARM-v7 registers that are callee-saved. They can be regarded as the
 *        general-purposed registers in x86 assembly.
 *
 */
static const std::string general_registers[8] = {"r4", "r5", "r6",  "r7",
                                                 "r8", "r9", "r10", "r11"};

static const std::string program_counter = "pc";

static const std::string stack_pointer = "sp";

/**
 * @brief ARM-v7 Registers that are NOT callee-saved. I.e., they are used when a
 *        procedure is called.
 *
 */
static const std::string argument_registers[4] = {"r0", "r1", "r2", "r3"};
} // namespace compiler

#endif