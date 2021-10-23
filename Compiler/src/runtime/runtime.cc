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
#include <common/config.hh>
#include <runtime/runtime.hh>

compiler::Command_parser::Command_parser(const int& argc, const char** argv)
    : argc(argc)
    , argv(argv)
{
    options = new cxxopts::Options("Compiler", "--------- Compiler by Takanashi Guidance ---------");

    options->custom_help("[INPUT FILE] [OTHER...]");

    options->add_options("INPUT FILE")("source", "The location of all the input source files", cxxopts::value<std::vector<std::string>>());

    options->add_options("OTHER")("c,compile", "Output the object file rather than executable", cxxopts::value<std::string>()->implicit_value("implicit"))("g,debug", "Enable debug mode", cxxopts::value<bool>()->default_value("false"))("o,outout", "The output file name", cxxopts::value<std::string>()->default_value("a.out"))("O,optimize", "The level of optimization", cxxopts::value<int>()->default_value("0"))("h,help", "Get the guidance");
}

compiler::Compiler_runtime::Compiler_runtime(const cxxopts::ParseResult& result)
{
    if (result.count("compile")) {
        compile_on = true;
    }
    if (result.count("debug")) {
        debug_on = true;
    }
    if (result.count("optimize")) {
        opt_level = result["optimize"].as<int>();
    }
    if (result.count("output")) {
        const std::string file_name = result["output"].as<std::string>();
        output_file = std::ofstream(file_name, std::ios::out);
    }
}

void compiler::Compiler_runtime::run(void)
{
    try {

    } catch (const std::runtime_error& e) {
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