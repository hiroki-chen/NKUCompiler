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
#include <algorithm>
#include <common/compile_excepts.hh>
#include <common/termcolor.hh>
#include <common/utils.hh>
#include <ir/cfg.hh>
#include <runtime/runtime.hh>
/* For filesystem. */
#include <filesystem>

using namespace std::string_literals;

extern int yyparse();
extern int yylex_destroy();
extern void yyset_lineno(int _line_number);
extern int yycolumn;
extern void yyset_in(FILE* _in_str);

uint32_t opt_level;  // Shared with each node for generating optimized IR.

std::vector<std::string> compiler::process_input(const std::string& input) {
  std::vector<std::string> files;

  for (const auto& entry : std::filesystem::directory_iterator(input)) {
    const std::filesystem::path file_path = entry.path();
    if (file_path.extension().compare(".sy") == 0) {
      const std::string sy_name = file_path.string();
      files.emplace_back(sy_name);
    }
  }

  std::filesystem::create_directory(input + "/output");

  std::sort(files.begin(), files.end());
  return files;
}

compiler::Command_parser::Command_parser(const int& argc, const char** argv)
    : argc(argc), argv(argv) {
  options = new cxxopts::Options(
      "Compiler", "--------- Compiler by Takanashi Guidance ---------");

  options->custom_help("[INPUT FILE POSITIONAL] [OTHER...]");

  options->add_options("INPUT FILE POSITIONAL")(
      "s,source", "The path of the source file",
      cxxopts::value<std::string>()->default_value("./test/test.sy"));

  options->parse_positional({"source"});

  options->add_options("OTHER")("c,compile",
                                "Output the object file rather than executable",
                                cxxopts::value<bool>()->default_value("false"))(
      "g,debug", "Enable debug mode",
      cxxopts::value<bool>()->default_value("false"))(
      "o,output", "The output file name.",
      cxxopts::value<std::string>()->default_value("a.out"))(
      "print-ir", "Print the intermediate representation of the source code",
      cxxopts::value<bool>()->default_value("false"))(
      "print-ast", "Print the abstract syntax tree",
      cxxopts::value<bool>()->default_value("false"))(
      "O,opt-level", "Enable Optimization",
      cxxopts::value<int>()->default_value("0"))("h,help", "Get the guidance")(
      "S,assembly", "Generate assembly code",
      cxxopts::value<bool>()->default_value("false"));
}

compiler::Compiler_runtime::Compiler_runtime(const cxxopts::ParseResult& result)
    : compile_on(result["compile"].as<bool>()),
      debug_on(result["debug"].as<bool>()),
      print_ast(result["print-ast"].as<bool>()),
      print_ir(result["print-ir"].as<bool>()),
      opt_level(result["opt-level"].as<int>()),
      generate_assembly(result["assembly"].as<bool>()) {
  ::opt_level = opt_level;
  const std::string input = result["source"].as<std::string>();

  if (is_dir(input)) {
    input_file = process_input(input);
    base_path = input;
  } else {
    output_file.open(result["output"].as<std::string>(), std::ios::out);
    input_file.emplace_back(input);
  }

  std::cout << "\033[4;90;107mTakanashi Compiler is running!!\033[0m"
            << std::endl;
}

void compiler::Compiler_runtime::run(void) {
  try {
    for (uint32_t i = 0; i < input_file.size(); i++) {
      std::cout << "Reading " << input_file[i] << std::endl;
      yyset_in(fopen(input_file[i].data(), "r"));
      yyset_lineno(1);
      yyparse();
      yylex_destroy();

      std::string res;
      std::ostringstream oss;
      std::vector<compiler::ir::IR> ir_list;
      if (!output_file.is_open()) {
        const std::string file =
            input_file[i].substr(input_file[i].find_last_of("/"));
        if (print_ast) {
          oss << base_path << "/output/" << file << ".ast";
          output_file.open(oss.str(), std::ios::out);
        }
        if (print_ir) {
          oss << base_path << "/output/" << file << ".ir";
          output_file.open(oss.str(), std::ios::out);
        }
      }

      if (print_ast) {
        res = root->print_result(0, false);
      }
      if (print_ir) {
        compiler::ir::IRContext* const ir_context =
            new compiler::ir::IRContext();

        root->generate_ir(ir_context, ir_list);

        for (auto item : ir_list) {
          item.emit_ir(oss, false);
          item.emit_ir(std::cerr, false);
        }

        res = oss.str();
      }

      output_file << res;
      output_file.flush();
      output_file.close();
      // compiler::ir::CFG_builder* const cfg_builder =
      //     new compiler::ir::CFG_builder(ir_list);
      // // DEBUG
      // auto table = cfg_builder->get_look_up_table();
      // for (auto item : table) {
      //   std::cout << item.first << ":\n";
      //   for (auto ir : item.second) {
      //     ir->emit_ir();
      //   }
      // }
    }

  } catch (const std::exception& e) {
    // Error handler.
    std::cerr << termcolor::red << termcolor::bold << e.what()
              << termcolor::reset << std::endl;
  }
}

void compiler::Command_parser::parse(void) {
  try {
    result = options->parse(argc, argv);

    // We store configuration in a global accessable field.
    if (result.count("help")) {
      std::cout << options->help() << std::endl;
      exit(0);
    }
  } catch (const cxxopts::OptionException& e) {
    std::cout << "Error: " << e.what() << std::endl;
    exit(1);
  }
}