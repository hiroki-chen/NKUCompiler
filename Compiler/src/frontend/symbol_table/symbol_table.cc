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
#include <frontend/symbol_table/symbol_table.hh>
#include <sstream>

// TODO: Add a utility function.
compiler::Symbol* compiler::Symbol_table::find_symbol(const std::string& name) {
  // Iterate over the current table and the parent table.
  last_uuid = symbol_table.size() - 1;
  Symbol* result = nullptr;
  for (auto& cur : symbol_table) {
    result = cur->find_symbol(name);
    if (result != nullptr) {
      break;
    }
    last_uuid--;
  }
  if (result != nullptr) {
    return result;
  }

  // Not found. Raise an error.
  std::ostringstream oss;
  oss << "Error: Symbol " << name << " is not declaraed.";
  throw compiler::undeclared_symbol(oss.str());
  return nullptr;
}

compiler::Symbol_const* compiler::Symbol_table::find_const(
    const std::string& name) {
  // Iterate over the current table and the parent table.
  last_uuid = const_table.size() - 1;
  Symbol_const* result = nullptr;
  for (auto& cur : const_table) {
    result = cur->find_const(name);
    if (result != nullptr) {
      break;
    }
    last_uuid--;
  }
  if (result != nullptr) {
    return result;
  }

  // Not found. Raise an error.
  std::ostringstream oss;
  oss << "Error: Symbol " << name << " is not declaraed.";
  throw compiler::undeclared_symbol(oss.str());
  return nullptr;
}

compiler::Symbol_const* compiler::Symbol_table::find_assign_const(
    const std::string& name) {
  // Iterate over the current table and the parent table.
  last_uuid = const_assign_table.size() - 1;
  Symbol_const* result = nullptr;
  for (auto& cur : const_assign_table) {
    result = cur->find_const(name);
    if (result != nullptr) {
      break;
    }
    last_uuid--;
  }
  if (result != nullptr) {
    return result;
  }

  // Not found. Raise an error.
  std::ostringstream oss;
  oss << "Error: Symbol " << name << " is not declaraed.";
  throw compiler::undeclared_symbol(oss.str());
  return nullptr;
}

void compiler::Symbol_table::add_symbol(const std::string& name,
                                        Symbol* const symbol) {
  if (!symbol_table.size()) {
    throw compiler::fatal_error("Error: The global symbol table is not found!");
  }
  (*symbol_table.begin())->add_symbol(name, symbol);
}

void compiler::Symbol_table::add_const(const std::string& name,
                                       Symbol_const* const symbol) {
  if (!const_table.size()) {
    throw compiler::fatal_error("Error: The global symbol table is not found!");
  }
  (*const_table.begin())->add_const(name, symbol);
}

void compiler::Symbol_table::assign_const(const std::string& name,
                                          Symbol_const* const symbol) {
  if (!const_assign_table.size()) {
    throw compiler::fatal_error("Error: The global symbol table is not found!");
  }
  (*const_assign_table.begin())->add_const(name, symbol);
}

compiler::Symbol_block* compiler::Symbol_table::get_spec_block(
    const uint32_t& i) {
  uint32_t index = symbol_table.size() - i;
  if (index <= 0) {
    throw compiler::fatal_error("Error: The global symbol table is not found!");
  }
  auto iter = symbol_table.begin();
  for (uint32_t i = 0; i < index; i++) {
    iter++;
  }
  return *iter;
}

compiler::Symbol* compiler::Symbol_block::find_symbol(const std::string& name) {
  auto iter = block.find(name);
  if (iter != block.end()) {
    return iter->second;
  } else {
    return nullptr;
  }
}

compiler::Symbol_const* compiler::Const_block::find_const(
    const std::string& name) {
  auto iter = block.find(name);
  if (iter != block.end()) {
    return iter->second;
  } else {
    return nullptr;
  }
}

void compiler::Symbol_block::add_symbol(const std::string& name,
                                        Symbol* const symbol) {
  if (find_symbol(name)) {
    throw compiler::redefined_symbol("Symbol " + name +
                                     " has been already defined.");
  } else {
    block[name] = symbol;
  }
}

void compiler::Const_block::add_const(const std::string& name,
                                      Symbol_const* const symbol) {
  if (find_const(name)) {
    throw compiler::redefined_symbol("Symbol " + name +
                                     " has been already defined.");
  } else {
    block[name] = symbol;
  }
}

compiler::Symbol_table::~Symbol_table() {
  const size_t ssize = symbol_table.size();
  for (size_t i = 0; i < ssize; i++) {
    delete symbol_table.back();
    symbol_table.pop_back();
  }

  const size_t csize = const_table.size();
  for (size_t i = 0; i < csize; i++) {
    delete const_table.back();
    const_table.pop_back();
  }
}