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
#ifndef REGISTER_POOL_HH
#define REGISTER_POOL_HH

#include <unordered_map>

// For ARM-v7 32-bit backend.

/**
 * @brief Defines register allocation algorithms.
 *
 */
namespace compiler::reg {
/**
 * @brief This class defines pool for active registers.
 *
 */
typedef class Register_pool {
private:
  /**
   * @brief A hash map that stores the availability of each registers of ARM.
   * 
   */
  std::unordered_map<std::string, bool> register_free_map;

  /**
   * @brief Records the number of free registers.
   * 
   */
  uint32_t free_registers;

public:
  /**
   * @brief Get a free register from the register pool.
   * 
   * @return std::string 
   */
  std::string get_free_register(void);

  /**
   * @brief Set an occupied register to be free.
   * 
   * @param reg_name 
   */
  void set_free_register(const std::string& reg_name);

  uint32_t free_num(void) { return free_registers; }
  
} Register_pool;
}  // namespace compiler::reg

#endif