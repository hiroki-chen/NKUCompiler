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
#include <common/termcolor.hh>
#include <runtime/runtime.hh>

static const auto __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
    return nullptr;
}();

using compiler::Command_parser;
using compiler::Compiler_runtime;

Compiler_runtime* compiler_runtime;

int main(int argc, const char** argv) {
  // First parse the command line
  try {
    Command_parser* const parser = new Command_parser(argc, argv);
    parser->parse();

    // Then send the parsed result to the compiler runtime.
    compiler_runtime = new Compiler_runtime(parser->get_result());
    compiler_runtime->run();
  } catch (const std::exception& e) {
    std::cerr << termcolor::red << termcolor::bold << e.what()
              << termcolor::reset << std::endl;
    exit(1);
  }

  return 0;
}