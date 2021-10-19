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
#ifndef COMPILER_BODY_HH
#define COMPILER_BODY_HH

#include "symbol.hh"
#include "node.hh"

#include <map>
#include <string>
#include <memory>

namespace compiler {

// Compiler runtime.
typedef class Compiler {
private:
    std::unique_ptr<SymbolTable> symbol_table;

} Compiler;
}

#endif