# Basic Framework for Project Compiler

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
sudo apt-get install qemu cmake clang-10 lldb-10 gcc-10 \
     gcc-arm-linux-gnueabihf \
     gcc-arm-none-eabi

# Create a symbolic link for future convenience.
sudo rm /usr/bin/c++ && sudo ln -s $(which clang++-10) /usr/bin/c++
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
gcc-arm -o test test.S -static -L../lib -lsysy -static
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

## 设计目标

* 纯C++实现；
* 采用多态和虚函数实现抽象语法树（Abstract Syntax Tree）的构建；
* 中间代码生成 （IR）；
* 汇编代码生成；
* 符号表查询

## 食用方法

* 在Unix系统中用`cmake`指令编译工程：

```shell
mkdir build
cd build
cmake ..
make
```

* 如果你指定了`-s`后面为目录，那么`-o`会被忽略，所有的输出都会存入`-s`指定目录下的`./output`目录。

* 对于编译指令不熟悉的可以输入-h查看使用指南。

```shell
./compiler --help

--------- Compiler by Takanashi Guidance ---------
Usage:
  Compiler [INPUT FILE POSITIONAL] [OTHER...] positional parameters

 INPUT FILE POSITIONAL options:

 OTHER options:
  -o, --output arg     The output file name. (default: a.out)
      --emit-llvm      Print the intermediate representation of the source 
                       code
      --print-ast      Print the abstract syntax tree
  -O, --opt-level arg  Enable Optimization (default: 0)
  -h, --help           Get the guidance
  -S, --assembly       Generate assembly code
```

## 项目布局（截止2021-12-19）

```txt
.├── build
│   ├── CMakeFiles
│   └── Testing
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

## 继承关系和几点说明

* 类和其文件名是一样的，想要找什么就直接去对应的文件里面找就行。
* 所有节点的基类都是`Item`，而该类是抽象基类，请不要实例化，它只能通过指针的形式使用。
* `Item_expr`继承自`Item`，基本上别的类都是从这里长出来的。
* `Item_stmt`继承自`Item_expr`，代表表达式类型。
* 为什么不把`Item_stmt`作为`Item`的子节点？那是因为`Item_stmt`包含`Item_expr`，但是如果`Item_expr`又是`item_stmt`的子节点的话，就会互相包含无穷无尽了。
* `frontend`为前端分析所需要的源文件和头文件，而`backend`存储了汇编指令生成和中间代码优化等相关文件；`common`是一些通用的枚举类以及一些工具。

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

