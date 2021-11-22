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
#include <vector>
#include <map>

namespace compiler::ir {
/**
 * @brief Basic block in a control flow graph.
 *
 */
using cfg_block = std::vector<IR*>;

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
} Edge;

/**
 * @brief A class for building the cfg from raw TAC (Three Address Code).
 * 
 */
typedef class CFG_builder {
private:
  std::vector<Edge> edges;

  std::map<uint32_t, cfg_block> look_up_table;

  std::map<std::string, uint32_t> name_to_id;

public:
  CFG_builder() = delete;

  CFG_builder(const std::vector<IR>& ir_list);
  
  void prettier_ir(std::ostream& out = std::cerr);

  std::vector<Edge> get_edges(void) const { return edges; }

  std::map<uint32_t, cfg_block> get_look_up_table(void) const { return look_up_table; }
} CFG_builder;
}  // namespace compiler::ir

#endif