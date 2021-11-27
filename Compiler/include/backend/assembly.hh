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

namespace compiler {
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
}  // namespace compiler

#endif