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
#ifndef UTILS_HH
#define UTILS_HH

#include <frontend/nodes/item_ident.hh>
#include <common/types.hh>

#include <regex>
#include <string>

static const std::regex colorized_pattern(R"(\033\[.*?m)");

namespace compiler {
std::string to_string(const compiler::basic_type& type);

std::string to_string(const compiler::unary_type& type);

std::string to_string(const compiler::binary_type& type);

void print_indent(const uint32_t& indent, const bool& leaf, std::ostream& os);

bool is_dir(const std::string& file_path);

// For the parser?
void handle_lib_put(const std::string& func_name, const int& value);

int handle_lib_get(const std::string& func_name);
} // namespace compiler

#endif