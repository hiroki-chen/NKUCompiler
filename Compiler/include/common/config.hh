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
#ifndef CONFIG_HH
#define CONFIG_HH

#include <frontend/nodes/item.hh>

#include <fstream>

namespace compiler {
// root
extern Item_root* const root;

namespace config {
    bool compile_on = false;

    bool debug_on = false;

    uint32_t opt_level = 0;

    std::ofstream output_file;
} // namespace config

} // namespace compiler

#endif