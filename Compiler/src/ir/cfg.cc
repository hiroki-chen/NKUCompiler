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
#include <ir/cfg.hh>

extern uint32_t opt_level;

static void construct_mapping(const compiler::ir::ir_list& ir_list,
                              std::map<std::string, uint32_t>& name_to_id,
                              std::map<uint32_t, std::string>& id_to_name,
                              compiler::ir::cfg& blocks) {
  // TODO: Need to save global definition.
  // Create mapping while constructing basic blocks for the CFG.
  // Scan the whole ir_list to construct basic blocks and the id.
  uint32_t id = 0;

  size_t i = 0;
  while (i < ir_list.size()) {
    if (ir_list[i].get_op_type() == compiler::ir::op_type::FUNC) {
      // Build a new CFG for a function.
      id = 0;
      const std::string function_name = std::move(ir_list[i].get_label());

      // Prepare block.
      std::vector<std::pair<uint32_t, compiler::ir::cfg_block>> block_body;

      // Construct block body.
      size_t j = i + 1;
      while (j < ir_list.size() &&
             ir_list[j].get_op_type() != compiler::ir::op_type::END_FUNC) {
        // Check if this is a label.
        if (ir_list[j].get_op_type() == compiler::ir::op_type::LBL) {
          // Prepare for the basic block.
          name_to_id[ir_list[j].get_label()] = id;
          id_to_name[id] = ir_list[j].get_label();
          compiler::ir::cfg_block basic_block;

          // Construct basic block.
          size_t k = j + 1;
          while (k < ir_list.size() &&
                 ir_list[k].get_op_type() != compiler::ir::op_type::LBL &&
                 ir_list[k].get_op_type() != compiler::ir::op_type::END_FUNC) {
            basic_block.emplace_back(ir_list[k]);
            k++;
          }
          // Reset index.
          j = k;
          block_body.emplace_back(id++, basic_block);
        }
      }
      i = j;
      blocks[function_name] = std::move(block_body);
    } else {
      i++;
    }
  }
}

static void analyze_control_flow(
    const compiler::ir::cfg& blocks,
    const std::map<std::string, uint32_t>& name_to_id,
    std::map<std::string, std::vector<compiler::ir::Edge>>& edges) {
  // Since there are some implicit jump between blocks, we need analyze
  // them as well.
  // E.g.:
  //      Foo:
  //       ADD %t1, %t0, i32 1
  //      Bar:
  //       Sub %t1, %t2, i32 9
  // To this end, * We need to look back and check whether there is an
  // unconditional jump after the previous block.*
  // I.e.:
  //        Foo -> Bar  type: 1 (Unconditional)
  for (auto item : blocks) {
    const std::string name = item.first;

    // Analyze the control flow by jump-related instructions.
    const auto blocks = item.second;
    for (auto basic_block : blocks) {
      const uint32_t id = basic_block.first;
      // Iterate through the instruction lists.
      for (auto ir : basic_block.second) {
        // Check if there is any jump-related instructions.
        if (compiler::ir::is_jump(ir.get_op_type())) {
          // Extract edge information for building the edge.
          const std::string jump_dst = std::move(ir.get_label());
          const uint32_t jump_dst_id = name_to_id.at(jump_dst);
          const bool type = ir.get_op_type() == compiler::ir::JMP;

          // Add an edge to the edge map.
          edges[name].emplace_back(id, jump_dst_id, type);
        }
      }

      // Check if there is any JUMP instruction at the end of the basic block.
      // If not, construct an explicit edge.
      // HACK: Assume the next block's id is always cur_id + 1...
      if (basic_block.second.back().get_op_type() !=
          compiler::ir::op_type::JMP) {
        edges[name].emplace_back(id, id + 1, true);
      }
    }
  }
}

// Do pruning.
static void prune_cfg(
    const std::map<std::string, std::vector<compiler::ir::Edge>>& edges,
    compiler::ir::cfg& blocks) {
// Iterate over the block and remove dead basic blocks.
// If any, merge continuos blocks.
#ifdef COMPILER_DEBUG
  std::cout << "Pruning and merging basic blocks!" << std::endl;
#endif

  // No optimization. We do nothing here.
  if (opt_level == 0) {
    return;
  }

  for (const auto item : edges) {
    for (const compiler::ir::Edge& edge : item.second) {
    }
  }
}

compiler::ir::CFG_builder::CFG_builder(const compiler::ir::ir_list& ir_list) {
  // The CFG builder constructs the control flow graph as follows:
  // 1. It first scans the ir list and constructs a mapping from the label name
  //    to the label id.
  // 2. It scans the ir list again and add edges from one block to another block
  //    according to the jumo-related instructions.
  // 3. It analyzes the control flow and tries to prune needless / dead blocks;
  //    that is, blocks that have no entry point.

  // Construct blocks and their mappings.
  construct_mapping(ir_list, name_to_id, id_to_name, blocks);
  // Analyze the control flow.
  analyze_control_flow(blocks, name_to_id, edges);
  // Prune useless control flows or merge continuous basic blocks.
  prune_cfg(edges, blocks);
}

#ifdef COMPILER_DEBUG
void compiler::ir::CFG_builder::print_cfg(void) const {
  for (auto item : edges) {
    std::cout << item.first << ": " << std::endl;
    for (auto edge : item.second) {
      std::cout << edge.from << " -> " << edge.to << " type: " << edge.type
                << std::endl;
    }
  }
}
#endif

void compiler::ir::CFG_builder::prettier_ir(std::ostream& out) {
  throw compiler::unimplemented_error("Error: Not yet supported!");
}
