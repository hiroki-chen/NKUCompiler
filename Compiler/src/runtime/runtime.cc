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

compiler::Command_parser::Command_parser(const int& argc, const char** argv)
    : argc(argc)
    , argv(argv)
{
    options = new cxxopts::Options("Compiler", "--------- Compiler by Takanashi Guidance ---------");

    options->custom_help("[INPUT FILE] [OTHER...]");

    options->add_options("INPUT FILE")("s,source", "The location of all the input source files", cxxopts::value<std::string>()->default_value("test/test.sy"));

    options->add_options("OTHER")("c,compile", "Output the object file rather than executable", cxxopts::value<bool>()->default_value("false"))("g,debug", "Enable debug mode", cxxopts::value<bool>()->default_value("false"))("t,tree", "Print the abstract syntax tree", cxxopts::value<bool>()->default_value("false"))("o,output", "The output file name", cxxopts::value<std::string>()->default_value("a.out"))("O,optimize", "The level of optimization", cxxopts::value<int>()->default_value("0"))("h,help", "Get the guidance");
}

compiler::Compiler_runtime::Compiler_runtime(const cxxopts::ParseResult& result)
    : compile_on(result["compile"].as<bool>())
    , debug_on(result["debug"].as<bool>())
    , print_ast(result["tree"].as<bool>())
    , output_file(std::ofstream(result["output"].as<std::string>(), std::ios::out))
    , input_file(fopen(result["source"].as<std::string>().data(), "r"))
    , opt_level(result["optimize"].as<int>())
{
    std::cout << "\033[4;90;107m Takanashi Compiler is running!! \033[0m" << std::endl;
}

void compiler::Compiler_runtime::run(void)
{
    try {
        yyset_in(input_file);
        yyset_lineno(1);
        yycolumn = 1;
        yyparse();
        yylex_destroy();

        if (print_ast) {
            // TODO: Check why output_file was accidentally truncated?
            output_file << root->print_result(0, false);
            std::cout << root->print_result(0, false);
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