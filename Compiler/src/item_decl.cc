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

#include <item_decl.hh>

compiler::Item_decl::Item_decl(const uint32_t& line_no, const basic_types& type, const std::vector<Item_def*>& def_list)
    : Item(line_no)
    , type(type)
{
    std::transform(def_list.begin(), def_list.end(), std::back_inserter(this->def_list),
        [](const Item_Def* const item_def) {
            return std::make_shared<Item_def>(item_def);
        });
}

compiler::Item_const_decl::Item_const_decl(const uint32_t& line_no, const basic_types& type, const std::vector<Item_def*>& def_list)
    : Item_decl(line_no, type, def_list)
{
}

compiler::Item_var_decl::Item_var_decl(const uint32_t& line_no, const basic_types& type, const std::vector<Item_def*>& def_list)
    : Item_decl(line_no, type, def_list)
{
}