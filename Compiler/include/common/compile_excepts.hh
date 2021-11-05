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
#ifndef COMPILE_EXCEPTS_HH
#define COMPILE_EXCEPTS_HH

#include <stdexcept>
#include <string>

namespace compiler {
/**
 * @brief Maybe we could ignore the function \ref{yyerror} and implement our exception handlers.
 * 
 */
typedef class parse_error : public std::exception {
protected:
    const std::string information;

public:
    explicit parse_error(const std::string& information)
        : information(information)
    {
    }

    const char* what(void) const noexcept override { return information.data(); }
} parse_error;

typedef class type_error : public std::exception {
protected:
    const std::string information;

public:
    explicit type_error(const std::string& information)
        : information(information)
    {
    }

    const char* what(void) const noexcept override { return information.data(); }
} type_error;

typedef class undeclared_symbol : public std::exception {
protected:
    const std::string information;

public:
    explicit undeclared_symbol(const std::string& information)
        : information(information)
    {
    }

    const char* what(void) const noexcept override { return information.data(); }
} undeclared_symbol;

typedef class redefined_symbol : public std::exception {
protected:
    const std::string information;

public:
    explicit redefined_symbol(const std::string& information)
        : information(information)
    {
    }

    const char* what(void) const noexcept override { return information.data(); }
} redefined_symbol;

typedef class unknown_character : public std::exception {
protected:
    const std::string information;

public:
    explicit unknown_character(const std::string& information)
        : information(information)
    {
    }

    const char* what(void) const noexcept override { return information.data(); }
} unknown_character;

typedef class fatal_error : public std::exception {
protected:
    const std::string information;

public:
    explicit fatal_error(const std::string& information)
        : information(information)
    {
    }

    const char* what() const noexcept override { return information.data(); }
} fatal_error;

typedef class unimplemented_error : public std::exception {
protected:
    const std::string information;

public:
    explicit unimplemented_error(const std::string& information)
        : information(information)
    {
    }

    const char* what(void) const noexcept override { return information.data(); }
} unimplemented_error;
} // namespace compiler

#endif