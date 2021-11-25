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

#include <common/types.hh>
#include <regex>
#include <sstream>
#include <string>

namespace compiler {
std::string to_string(const compiler::basic_type& type);

std::string to_string(const compiler::unary_type& type);

std::string to_string(const compiler::binary_type& type);

/**
 * @brief Concatenate variables to a string, using parameter pack.
 *
 * @tparam Args
 * @param args
 * @return std::string
 */
template <class... Args>
std::string concatenate(Args&&... args) {
  std::ostringstream oss;
  (oss << ... << std::forward<Args>(args));
  return oss.str();
}

/**
 * @brief Print indentation for each node in the AST.
 *
 * @param indent
 * @param leaf
 * @param os
 */
void print_indent(const uint32_t& indent, const bool& leaf, std::ostream& os);

/**
 * @brief Checks whether a given file path is a directory.
 * @note std::filesystem is a must.
 *
 * @param file_path
 * @return true
 * @return false
 */
bool is_dir(const std::string& file_path);

uint32_t to_byte_length(const basic_type& type);

/**
 * @brief Converts a basic_type to its corresponding IR type.
 *
 * @param b_type
 * @return ir::var_type
 */
ir::var_type to_ir_type(const basic_type& b_type);

/**
 * @brief Convert a IR type back to its basic type.
 *
 * @param v_type
 * @return basic_type
 */
basic_type to_basic_type(const ir::var_type& v_type);

/**
 * @brief A helper function that inserts into the vector without copy
 * constructor..
 *
 * @tparam ItemType
 * @param dst
 * @param src
 */
template <class ItemType>
void insert_with_move(std::vector<ItemType>& dst,
                      const std::vector<ItemType>& src) {
  for (const auto& item : src) {
    dst.emplace_back(std::move(item));
  }
}
}  // namespace compiler

#endif
