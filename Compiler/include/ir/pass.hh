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
#ifndef PASS_HH
#define PASS_HH

#include <map>
#include <unordered_map>

#include <ir/ir.hh>

namespace compiler::ir::pass {
/**
 * @brief The base class for optimizing the IR.
 *        If you want to implement other types of optimizations, you should
 *        inherit this class and implement the interfaces.
 *
 */
typedef class Pass {
 public:
  virtual bool do_pass(const std::vector<IR*>& ir_list) = 0;
} Pass;

/**
 * @brief Eliminate the dead code.
 *
 */
typedef class Dead_code_pass final : public Pass {
 private:
  uint32_t timestamp;

 protected:
  // Maps an IR to the timestamp.
  std::unordered_map<IR*, uint32_t> ir_to_time;

  // Records the timestamp when a variable is defined.
  std::unordered_map<std::string, uint32_t> var_def_timestamp;
  std::multimap<uint32_t, std::string> var_def_timestamp_heap;

  // Records the last timestamp when a variable is used.
  std::unordered_map<std::string, uint32_t> var_latest_use_timestamp;
  std::multimap<uint32_t, std::string> var_latest_use_timestamp_heap;

  virtual void set_latest_use(IR* const ir);

  virtual void set_var_def(IR* const ir);

 public:
  Dead_code_pass() : timestamp(0ul) {}

  virtual bool do_pass(const std::vector<IR*>& ir_list) override;

  virtual void reset(void);
} Dead_code_pass;
}  // namespace compiler::ir::pass

#endif