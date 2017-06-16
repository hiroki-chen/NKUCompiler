# Copyright (c) 2021 Haobin Chen & Jiawei Xu
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

# !/bin/bash

# This shell script will automatically scan all the files 
# from a given path and then send them to the compiler.
# Execute the script after your environment variable is set.
# E.g.:
#           $ export SOURCE_FILE_PATH=./some/path

# Check if the environment variable is already set.
if [[ -z "${SOURCE_FILE_PATH}" ]];
then
    echo "The environment is not set. Abort."
    echo "You should set SOURCE_FILE_PATH=./some/path"
    exit
fi

# Wildcard all the files to the array.
IFS=$'\n'
files=($(find ${SOURCE_FILE_PATH} -regex ".*\.sy"))
unset IFS

# Set replace extension
ext=".ir"
find=".sy"

# Iterate through the current folder.
for file in "${files[@]}";
do
    echo "Reading file ${file}..."
    # Do a pattern substitution.
    output=${file//${find}/${ext}}
    ./compiler ${file} --print-ir -o ${output}
done


