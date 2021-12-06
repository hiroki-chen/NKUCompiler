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
#ifndef INTERVAL_HH
#define INTERVAL_HH
#include <backend/assembly.hh>
#include <set>

namespace compiler::reg {
typedef struct Interval final {
  uint32_t start;
  uint32_t end;
  bool spill;        // Whether this vreg should be spilled to memory
  uint32_t disp;     // Displacement in stack
  uint32_t phy_reg;  // The physical register mapped from virtual register if
                     // the vreg is not spilled to memory
  std::set<Machine_operand *> defs;
  std::set<Machine_operand *> uses;
} Interval;
}  // namespace compiler::reg

#endif