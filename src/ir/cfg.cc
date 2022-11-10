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
#include <cassert>
#include <common/compile_excepts.hh>
#include <common/utils.hh>
#include <ir/cfg.hh>
#include <ir/pass.hh>

static void prune_early_return(compiler::ir::CFG_block* const block) {
  compiler::ir::ir_list* const ir_list = block->get_ir_list();
  uint32_t end_pos = 0;
  while (end_pos < ir_list->size() &&
         (*ir_list)[end_pos].get_op_type() != compiler::ir::op_type::RET) {
    end_pos++;
  }

  // HACK: Just pop useless IRs out of the vector!
  const size_t vec_size = ir_list->size();
  for (size_t i = end_pos + 1; i < vec_size; i++) {
    ir_list->pop_back();
  }
}

void compiler::ir::CFG_builder::construct_mapping(
    const compiler::ir::ir_list& ir_list) {
  // Create mapping while constructing basic blocks for the CFG.
  // Scan the whole ir_list to construct basic blocks and the id.
  uint32_t id = 1;

  size_t i = 0;
  while (i < ir_list.size()) {
    if (ir_list[i].get_op_type() == compiler::ir::op_type::GLOBAL_BEGIN) {
      // Handle global definitions.
      global_defs->add_ir(ir_list[i]);
      uint32_t j = i + 1;

      while (j < ir_list.size() &&
             ir_list[j].get_op_type() != compiler::ir::op_type::GLOBAL_END) {
        global_defs->add_ir(ir_list[j]);
        j++;
      }

      i = j;

    } else if (ir_list[i].get_op_type() == compiler::ir::op_type::FUNC) {
      // Build a new CFG for a function.
      id = 1;
      const std::string function_name = compiler::concatenate(
          ir_list[i].get_label(), "_", ir_list[i].get_op2()->get_identifier());

      // Construct block body.
      size_t j = i + 1;
      while (j < ir_list.size() &&
             ir_list[j].get_op_type() != compiler::ir::op_type::END_FUNC) {
        // Check if this is a label.
        if (ir_list[j].get_op_type() == compiler::ir::op_type::LBL) {
          const std::string label = ir_list[j].get_label();
          // Prepare for the basic block.
          compiler::ir::CFG_block* const basic_block =
              new compiler::ir::CFG_block(label, id);

          // Insert into the name_to_cfg map.
          id_to_cfg[function_name][id] = basic_block;
          name_to_id[function_name][label] = id;

          // Construct basic block.
          size_t k = j + 1;
          while (k < ir_list.size() &&
                 ir_list[k].get_op_type() != compiler::ir::op_type::LBL &&
                 ir_list[k].get_op_type() != compiler::ir::op_type::END_FUNC) {
            if (!ir_list[k].get_is_dead()) {
              basic_block->add_ir(ir_list[k]);
            }
            k++;
          }
          // Reset index.
          j = k;
          functions[function_name].emplace_back(basic_block);
          id++;
        }
      }
      i = j;
    } else {
      i++;
    }
  }
}

void compiler::ir::CFG_builder::analyze_control_flow(void) {
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
  // First we prune the early return statements.
  for (auto item : functions) {
    // Prune early return statements.
    for (auto block : item.second) {
      prune_early_return(block);
    }
  }

  for (auto& item : functions) {
    const std::string name = item.first;
    // Analyze the control flow by jump-related instructions.
    const auto blocks = item.second;
    for (auto basic_block : blocks) {
      const uint32_t id = basic_block->get_id();
      // Iterate through the instruction lists.
      for (auto ir : *(basic_block->get_ir_list())) {
        // Check if there is any jump-related instructions.
        if (compiler::ir::is_jump(ir.get_op_type())) {
          // Extract edge information for building the edge.
          const std::string jump_dst = std::move(ir.get_label());
          const uint32_t jump_dst_id = name_to_id.at(name).at(jump_dst);
          compiler::ir::CFG_block* const dst_block =
              id_to_cfg.at(name).at(jump_dst_id);
          const bool type = ir.get_op_type() == compiler::ir::JMP;

          // Add the successor to the vector.
          basic_block->add_succ(dst_block);
          dst_block->add_pred(basic_block);
        }
      }

      block_epilogue(basic_block, id, name);
    }
  }
}

void compiler::ir::CFG_builder::block_epilogue(
    compiler::ir::CFG_block* const basic_block, const uint32_t& id,
    const std::string& name) {
  // Check if there is any JUMP instruction at the end of the basic block.
  // If not, construct an explicit edge.

  // HACK: Assume the next block's id is always cur_id + 1... Is that really
  // so? NO.
  compiler::ir::IR& last_ir = basic_block->get_ir_list()->back();

  if (basic_block->get_ir_list()->empty() ||
      last_ir.get_op_type() != compiler::ir::op_type::JMP &&
          last_ir.get_op_type() != compiler::ir::op_type::RET) {
    const uint32_t next_block_id = id + 1;
    compiler::ir::CFG_block* const next_block = id_to_cfg[name][next_block_id];
    basic_block->add_succ(next_block);
    next_block->add_pred(basic_block);
  }
}

// Do pruning.
void compiler::ir::CFG_builder::prune_cfg(void) {
// Iterate over the block and remove dead basic blocks.
// If any, merge continuos blocks.
#ifdef COMPILER_DEBUG
  std::cout << "Pruning and merging basic blocks!" << '\n';
#endif

  for (auto& block : functions) {
    auto& cfg_blocks = block.second;
    // We handle blocks by function.
    // 1. Merge nodes that have only one entry and one exit.
    // 2. Remove all blocks that have no predecessors.
    // Do this until the block does not change.
    bool change = false;
    do {
      change = false;
#ifdef COMPILER_DEBUG
      this->prettier_ir(std::cout);
#endif
      for (auto iter = cfg_blocks.begin(); iter != cfg_blocks.end();) {
        // Entry point should not be touched!
        if ((*iter)->get_id() == 1) {
          iter++;
          continue;
        }

        if ((*iter)->get_preds().empty()) {
          change = true;
          // Recursively remove all the successors.
          for (auto succ : (*iter)->get_succs()) {
            succ->remove_pred(*iter);
          }
          iter = cfg_blocks.erase(iter);
          continue;
        }
        // A block that has exactly one predecessor may be merged to its
        // predecessor if the predecessor has only one sucessor.
        // NOTE:
        //      DO NOT MERGE BLOCKS A and B.
        //      A -> B
        //        |
        //        -> C
        if ((*iter)->get_preds().size() == 1) {
          compiler::ir::CFG_block* const pred = (*iter)->get_preds().front();
          // Merging them is OK.
          // The predecessor will inherit (?) its sucessor's sucessors.
          if (pred->get_succs().size() == 1 &&
              pred->get_succs().front()->get_id() == (*iter)->get_id()) {
#ifdef COMPILER_DEBUG
            std::cout << "Merging " << pred->get_name() << " and "
                      << (*iter)->get_name() << '\n';
#endif  // Remove predecessor's JUMP instruction.
            pred->remove_jump();
            // Merge.
            pred->splice(*(*iter)->get_ir_list());
            // Remove it from the predecessor's successor list.
            pred->remove_succ(*iter);
            // Add successors.
            for (auto succ : (*iter)->get_succs()) {
              pred->add_succ(succ);
              succ->add_pred(pred);
              succ->remove_pred(*iter);
            }
            // Remove the current block.
            iter = cfg_blocks.erase(iter);
            change = true;
            continue;
          }
        }

        iter++;
      }
    } while (change == true);
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
  global_defs = new compiler::ir::CFG_block("GLOBAL", 0);
  // Construct blocks and their mappings.
  construct_mapping(ir_list);
  // Analyze the control flow.
  analyze_control_flow();
  // Prune useless control flows or merge continuous basic blocks.
  prune_cfg();
  // Do optimizations on the IR.
  do_pass();
}

void compiler::ir::CFG_builder::do_pass(void) {
  // Do a simple pass.
  // Note that the the atomic unit for optimization is a function.
  for (auto blocks : functions) {
    const std::unique_ptr<ir::pass::Dead_code_pass> pass =
        std::make_unique<ir::pass::Dead_code_pass>();
    std::vector<ir::IR*> ir_list;
    for (auto basic_block : blocks.second) {
      for (uint32_t i = 0; i < basic_block->get_ir_list()->size(); i++) {
        // Fetch the raw pointer to manipulate the ir.
        ir_list.emplace_back(&((*basic_block->get_ir_list())[i]));
      }
    }

    for (uint32_t i = 0; i < ir::maximum_pass_time; i++) {
      pass->do_pass(ir_list);
      pass->reset();
    }
  }
}

void compiler::ir::CFG_block::splice(const ir::ir_list& ir_list) {
  for (compiler::ir::IR ir : ir_list) {
    if (ir.get_op_type() != compiler::ir::op_type::LBL) {
      this->ir_list.emplace_back(std::move(ir));
    }
  }
}

#ifdef COMPILER_DEBUG
void compiler::ir::CFG_builder::print_cfg(void) const {
  for (auto item : functions) {
    std::cout << item.first << ": " << '\n';
    for (auto block : item.second) {
      std::cout << "------------" << '\n';
      std::cout << block->get_id() << "'s preds: ";
      for (auto preds : block->get_preds()) {
        std::cout << preds->get_id() << " ";
      }
      std::cout << '\n';
      std::cout << block->get_id() << "'s succs: ";
      for (auto succs : block->get_succs()) {
        std::cout << succs->get_id() << " ";
      }
      std::cout << '\n';
    }
  }
}
#endif

void compiler::ir::CFG_builder::prettier_ir(std::ostream& out) {
  for (auto item : functions) {
    out << item.first << ": " << '\n';
    for (auto block : item.second) {
      out << block->get_name() << ": " << '\n';
      for (auto ir : *(block->get_ir_list())) {
        ir.emit_ir(out);
      }
    }
  }
}

compiler::ir::CFG_block::CFG_block(const std::string& name, const uint32_t& id)
    : name(name), id(id) {}

void compiler::ir::CFG_block::remove_pred(compiler::ir::CFG_block* const pred) {
  // Find the element.
  auto iter = std::find_if(preds.begin(), preds.end(),
                           [=](compiler::ir::CFG_block* const block) -> bool {
                             return block->get_id() == pred->get_id();
                           });

  assert(iter != preds.end() &&
         "You are accessing a non-existing predecessor!");
  // Remove it.
  preds.erase(iter);
}

void compiler::ir::CFG_block::remove_succ(compiler::ir::CFG_block* const succ) {
  // Find the element.
  auto iter = std::find_if(succs.begin(), succs.end(),
                           [=](compiler::ir::CFG_block* const block) -> bool {
                             return block->get_id() == succ->get_id();
                           });

  assert(iter != succs.end() && "You are accessing a non-existing successor!");
  // Remove it.
  succs.erase(iter);
}

void compiler::ir::CFG_block::remove_jump(void) {
  if (!ir_list.empty() &&
      ir_list.back().get_op_type() == compiler::ir::op_type::JMP) {
    ir_list.pop_back();
  }
}