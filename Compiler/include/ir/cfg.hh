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
#ifndef CFG_HH
#define CFG_HH
#include <ir/ir.hh>
#include <map>
#include <vector>

namespace compiler::ir {
/**
 * @brief Basic block in a control flow graph.
 *
 */
using cfg_block = std::vector<IR>;

/**
 * @brief The CFG itself.
 *
 * A CFG is defined as:
 *    Function -> Blocks = [id, block_body].
 *
 */
using cfg = std::map<std::string, std::vector<std::pair<uint32_t, cfg_block>>>;

using edge =
    std::map<std::string,
             std::map<uint32_t, std::vector<std::pair<uint32_t, bool>>>>;

/**
 * @brief An edge in the CFG.
 *
 */
typedef struct Edge {
  uint32_t from;

  uint32_t to;

  /**
   * @brief type == 1 => Conditional jump; type == 0 => Uncondintional jump.
   *
   */
  bool type;

  Edge() = default;

  Edge(const uint32_t& from, const uint32_t& to, const bool& type)
      : from(from), to(to), type(type) {}
} Edge;

/**
 * @brief A class for building the cfg from raw TAC (Three Address Code).
 *
 */
typedef class CFG_builder {
 private:
  /**
   * @brief The CFG should be a SPARSE graph where each node has at most two
   *        successors and two predecessors.
   * @note  We maintain as a list since it is more efficient than the matrix.
   *
   */
  edge edges;

  std::map<uint32_t, cfg_block> look_up_table;

  std::map<std::string, std::map<std::string, uint32_t>> name_to_id;

  cfg blocks;

 public:
  CFG_builder() = delete;

  CFG_builder(const std::vector<IR>& ir_list);

  void prettier_ir(std::ostream& out = std::cerr);

  edge get_edges(void) const { return edges; }

  std::map<uint32_t, cfg_block> get_look_up_table(void) const {
    return look_up_table;
  }

#ifdef COMPILER_DEBUG
  void print_cfg(void) const;
#endif
} CFG_builder;

}  // namespace compiler::ir

#endif