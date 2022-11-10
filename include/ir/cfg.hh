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
static const uint32_t maximum_pass_time = 0ul;
/**
 * @brief A basic block in the control flow graph.
 *
 */
typedef class CFG_block {
 private:
  const uint32_t id;

  // The name is extracted from the label.
  const std::string name;

  // Predecessors and successors.
  std::vector<CFG_block*> preds;
  std::vector<CFG_block*> succs;

  ir::ir_list ir_list;

 public:
  CFG_block() = delete;

  CFG_block(const std::string& name, const uint32_t& id);

  void add_pred(CFG_block* const block) { preds.emplace_back(block); }

  void add_succ(CFG_block* const block) { succs.emplace_back(block); }

  void add_ir(const ir::IR& ir) { ir_list.emplace_back(ir); }

  void splice(const ir::ir_list& ir_list);

  ir::ir_list* get_ir_list(void) { return &ir_list; }

  uint32_t get_id(void) const { return id; }

  std::string get_name(void) const { return name; }

  std::vector<CFG_block*> get_preds(void) const { return preds; }

  std::vector<CFG_block*> get_succs(void) const { return succs; }

  void remove_pred(CFG_block* const pred);

  void remove_succ(CFG_block* const succ);

  void remove_jump(void);

} CFG_block;

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

  // Each function will contain several basic CFG blocks.
  std::map<std::string, std::vector<CFG_block*>> functions;

  // This is used to construct preds and succs.
  std::map<std::string, std::map<uint32_t, CFG_block*>> id_to_cfg;

  std::map<std::string, std::map<std::string, uint32_t>> name_to_id;

  CFG_block* global_defs;

  // Functions.
  void construct_mapping(const std::vector<IR>& ir_list);

  void analyze_control_flow(void);

  void prune_cfg(void);

  void block_epilogue(compiler::ir::CFG_block* const basic_block,
                      const uint32_t& id, const std::string& name);

  void do_pass(void);

 public:
  CFG_builder() = delete;

  CFG_builder(const std::vector<IR>& ir_list);

  void prettier_ir(std::ostream& out = std::cerr);

  std::map<std::string, std::vector<CFG_block*>> get_functions(void) const {
    return functions;
  }

  CFG_block* get_global_defs(void) const { return global_defs; }

#ifdef COMPILER_DEBUG
  void print_cfg(void) const;
#endif
} CFG_builder;

}  // namespace compiler::ir

#endif