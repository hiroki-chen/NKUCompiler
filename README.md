# Basic Framework for Project Compiler

**Another LLVM-based compiler can be found in my repository:** [LLVM-based Compiler](https://github.com/hiroki-chen/LLVMCompiler)

## Prerequisites

* Make sure that your compiler supports -std=c++17
* Clang v10
* CMake v3.20
* Ubuntu >= 18.04 / macOS >= 10.13 (not recommended)
* QEMU-ARM
* gcc-arm-linux-gnueabihf (Ubuntu/Linaro 7.5.0-3ubuntu1~18.04)

To get all the needed packages, run the following commands:

```shell
sudo apt update && \
sudo apt install -y software-properties-common lsb-release && \
sudo apt clean all
wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null | gpg --dearmor - | sudo tee /etc/apt/trusted.gpg.d/kitware.gpg 2> /dev/null
sudo apt-add-repository "deb https://apt.kitware.com/ubuntu/ $(lsb_release -cs) main"
sudo apt update
sudo apt-get install qemu-user cmake clang-10 lldb-10 gcc-10 \
     bison flex \
     gcc-arm-linux-gnueabihf \
     gcc-arm-none-eabi

# Create a symbolic link for future convenience.
sudo ln -s $(which arm-linux-gnueabihf-gcc) /usr/bin/gcc-arm
```

## Debug our compiler

There is a way to use lldb to debug the compiler. Please first make sure that you have lldb installed via the above commands and then setup the lldb correctly by using `lldbinit.py`:

```shell
cp ./util/lldbinit.py ~/.lldbinit.py
echo "command script import  ~/.lldbinit.py" >> $HOME/.lldbinit
```

Change the build type in the `CMakeLists.txt`:
```shell
set(CMAKE_BUILD_TYPE DEBUG)
```

Then you can debug the compiler by

```shell
lldb ./compiler
```

## Assemble to binary

If you run the compiler and get the correct output file, you could assemble it by gcc-arm-linux-gnueabihf with the following command (assuming that you are in the correct directory):

```shell
./compiler -o test.S -S ../test/level1-1/foo.sy # Input the file.
gcc-arm -o test test.S -static -L../lib -lsysy -march=armv7-a
```

## Debug the target application

To debug the arm executable, you should first install gdb-multiarch:

```shell
sudo apt-get install gdb-multiarch
```

Then create a debug session by qemu-arm:

```shell
qemu-arm -g 1234 ./test
```

Connect gdb to qemu:

```shell
gdb-multiarch -q --nh \ 
  -ex 'set architecture arm' \
  -ex 'file test' \
  -ex 'target remote localhost:1234' \
  -ex 'layout split'
```

## Design Targets

* Written in pure C++ language.
* Construct the abstract syntax tree by polymorphism and virtual functions.
* Generate assembly-like three-address code (LLVM-like IR is implemented in branch `llvm_ir`). 
* Generate machine code and allocate physical registers by linear scan；

## How to build

* Build our compiler by `cmake` in unix-like OS.

```shell
mkdir build
cd build
cmake ..
make -j
```

```shell
$ ./compiler --help

--------- Compiler by Takanashi Guidance ---------
Usage:
  Compiler [INPUT FILE POSITIONAL] [OTHER...] positional parameters

 INPUT FILE POSITIONAL options:

 OTHER options:
  -c, --compile        Output the object file rather than executable
  -g, --debug          Enable debug mode
  -o, --output arg     The output file name. (default: a.out)
      --emit-llvm      Print the intermediate representation of the source 
                       code
      --print-ast      Print the abstract syntax tree
  -O, --opt-level arg  Enable Optimization (default: 0)
  -h, --help           Get the guidance
  -S, --assembly       Generate assembly code
```

An full workflow:

**You are in `build` directory.**

`./compiler -o test.S -S ../test/test.sy ` for compilation.
`arm-linux-gnueabihf-gcc -o test -static -L../lib -lsysy -march=armv7-a ./test.S` for assembly.
`qemu-arm ./test` for running the application.

## Project Layout

```txt
.
├── include
│   ├── backend
│   ├── common
│   ├── frontend
│   ├── ir
│   └── runtime
├── lib
├── src
│   ├── backend
│   ├── common
│   ├── frontend
│   ├── ir
│   └── runtime
├── test
│   ├── level1-1
│   ├── level1-2
│   ├── level2-1
│   ├── level2-2
│   ├── level2-3
│   ├── level2-4
│   └── level2-5
└── util
```

## Inheritance Diagram of Tree Nodes

```
Item -> Item_expr -> Item_expr_cond
                  -> Item_ident         -> Item_ident_array
                                        -> Item_ident_pointer

                  -> Item_literal       -> Item_literal_numeric     -> Item_literal_int
                                                                    -> Item_literal_real
                                                                    -> Item_literal_char
                                        -> Item_literal_string
                                        -> Item_literal_array_init

                  -> Item_expr_binary   -> Item_expr_add
                                        -> Item_expr_sub
                                        -> Item_expr_mul
                                        -> Item_expr_div
                                                
                  -> Item_stmt          -> Item_block
                                        -> Item_stmt_eif
                                        -> Item_stmt_while
                                        -> Item_stmt_for
                                        -> Item_stmt_return
                                        -> Item_stmt_break
                                        -> Item_stmt_continue
                                        -> Item_stmt_decl
                 
                 -> Item_func_def_list
                 -> Item_func_def_arg
                 -> Item_func_call
                 -> Item_func_call_list

     -> Item_decl -> Item_decl_var      -> Item_decl_var_init
                  -> Item_decl_array    -> Item_decl_array_init
                  -> Item_decl_pointer  -> Item_decl_pointer_init

     -> Item_func_def
```
