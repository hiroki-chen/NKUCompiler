#!/bin/bash

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

# This shell script will automatically scan all the files
# from a given path and then send them to the compiler.
# Execute the script after your environment variable is set.
# E.g.:
#           $ export SOURCE_FILE_PATH=./some/path
# Check if the environment variable is already set.
if [[ -z "${SOURCE_FILE_PATH}" ]]; then
	echo "The environment is not set. Abort."
	echo "You should set SOURCE_FILE_PATH=./some/path"
	exit
fi

if [[ -z "${LIB_PATH}" ]]; then
	echo "The sysy library path is not set. Abort."
	echo "You should set LIB_PATH=./some/path"
	exit
fi

if ! command -v arm-none-eabi-gcc &> /dev/null && ! command -v arm-linux-gnueabihf-gcc &> /dev/null;
then
	echo "There is no ARM-GCC on your machine. Please install it in the correct path."
	exit
fi

# Store the directories that store different testcases at different levels.
IFS=$'\n'
dirs=$(ls -d ${SOURCE_FILE_PATH}/level*-*)
unset IFS

for dir in ${dirs[@]}; do
	echo "Starting Tests for ${dir} ..."

	# Wildcard all the files to the array.
	IFS=$'\n'
	files=($(find ${dir} -regex ".*\.sy"))
	files=($(sort <<< "${files[*]}"))
	unset IFS

	# Set replace extension
	ext=".S"
	find=".sy"
	binary=".bin"

	# Iterate through the current folder.
	for file in "${files[@]}"; do
		# Do a pattern substitution.
		output=${file/${find}/${ext}}
		qemu=${file/${find}/${binary}}
		./compiler ${file} -S -o ${output} &> /dev/null

		arm-linux-gnueabihf-gcc -o ${qemu} ${output} ${LIB_PATH}/libsysy.a -static -march=armv7-a
		qemu-arm ${qemu}
		echo $?
		echo '\n'
	done
done
