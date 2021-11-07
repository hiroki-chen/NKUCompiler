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
#include <common/termcolor.hh>
#include <common/utils.hh>
#include <runtime/runtime.hh>

#include <algorithm>
/* For filesystem. */
#include <experimental/filesystem>

using namespace std::string_literals;
using namespace std::experimental;

std::vector<std::string> compiler::process_input(const std::string& input)
{
    std::vector<std::string> files;

    for (const auto& entry : filesystem::directory_iterator(input)) {
        const filesystem::path file_path = entry.path();
        if (file_path.extension().compare(".sy") == 0) {
            const std::string sy_name = file_path.string();
            files.emplace_back(sy_name);
        }
    }

    filesystem::create_directory(input + "/output");

    std::sort(files.begin(), files.end());
    return files;
}

compiler::Command_parser::Command_parser(const int& argc, const char** argv)
    : argc(argc)
    , argv(argv)
{
    options = new cxxopts::Options("Compiler", "--------- Compiler by Takanashi Guidance ---------");

    options->custom_help("[INPUT FILE] [OTHER...]");

    options->add_options("INPUT FILE")("s,source", "The location of all the input source files. If it a directory, then all the files in the "
                                                   "direcotry will be read in.",
        cxxopts::value<std::string>()->default_value("test/test.sy"));

    options->add_options("OTHER")("c,compile", "Output the object file rather than executable", cxxopts::value<bool>()->default_value("false"))("g,debug", "Enable debug mode", cxxopts::value<bool>()->default_value("false"))("t,tree", "Print the abstract syntax tree", cxxopts::value<bool>()->default_value("false"))("o,output", "The output file name."
                                                                                                                                                                                                                                                                                                                                        "Note that if --source is set to a directory, then --output will be ignored.",
        cxxopts::value<std::string>()->default_value("a.out"))("O,optimize", "The level of optimization", cxxopts::value<int>()->default_value("0"))("h,help", "Get the guidance");
}

compiler::Compiler_runtime::Compiler_runtime(const cxxopts::ParseResult& result)
    : compile_on(result["compile"].as<bool>())
    , debug_on(result["debug"].as<bool>())
    , print_ast(result["tree"].as<bool>())
    , opt_level(result["optimize"].as<int>())
{
    const std::string input = result["source"].as<std::string>();

    if (is_dir(input)) {
        input_file = process_input(input);
        base_path = input;
    } else {
        output_file.open(result["output"].as<std::string>(), std::ios::out);
        input_file.emplace_back(input);
    }

    std::cout << "\033[4;90;107mTakanashi Compiler is running!!\033[0m" << std::endl;
}

void compiler::Compiler_runtime::run(void)
{
    try {
        for (uint32_t i = 0; i < input_file.size(); i++) {
            std::cout << "Reading " << input_file[i] << std::endl;
            yyset_in(fopen(input_file[i].data(), "r"));
            yyset_lineno(1);
            yyparse();
            yylex_destroy();

            if (print_ast) {
                if (!output_file.is_open()) {
                    std::ostringstream oss;
                    const std::string file = input_file[i].substr(input_file[i].find_last_of("/"));
                    oss << base_path << "/output/" << file << ".ast";
                    output_file.open(oss.str(), std::ios::out);
                }
                std::string res = root->print_result(0, false);
                output_file << res;
                output_file.flush();
                output_file.close();
                //std::cout << res;
                //std::cout.flush();
            }
        }

    } catch (const std::exception& e) {
        // Error handler.
        std::cerr << e.what() << std::endl;
    }
}

void compiler::Command_parser::parse(void)
{
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