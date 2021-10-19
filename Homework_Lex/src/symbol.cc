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
#include <symbol.hh>
#include <utils.hh>

compiler::Symbol::Symbol(const std::string& id, const token_type& token_type, const int& value)
    : name(id)
    , type(token_type)
    , value(convert<int>(token_type, value))
{
    
}

compiler::Symbol::Symbol(const std::string& id, const token_type& token_type, const double& value)
    : name(id)
    , type(token_type)
    , value(convert<double>(token_type, value))
{
    
}

compiler::Symbol::Symbol(const std::string& id, const token_type& token_type, const float& value)
    : name(id)
    , type(token_type)
    , value(convert<float>(token_type, value))
{
    
}

compiler::Symbol::Symbol(const std::string& id, const token_type& token_type, const char& value)
    : name(id)
    , type(token_type)
    , value(convert<char>(token_type, value))
{
    
}

compiler::Symbol::Symbol(const std::string& id, const token_type& token_type, char* const value)
    : name(id)
    , type(token_type)
    , value(convert<char*>(token_type, value))
{
    
}