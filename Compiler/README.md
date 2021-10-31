## Basic Framework for Project Compiler

* LAB5以后的作业直接在这里写吧。

### 设计目标
* 纯C++实现；
* 采用多态和虚函数实现抽象语法树（Abstract Syntax Tree）的构建；
* 中间代码生成 （IR）；
* 汇编代码生成；
* 符号表查询

### 食用方法
* 在Unix系统中用`make`指令编译工程：
```shell
cd Compiler && make all CXX=<your compiler>;
./build/compiler.bin -c -o ./output/output -s ./test/input.sy -t; # Command Line Parser :)
```
* 对于编译指令不熟悉的可以输入-h查看使用指南。

* **目前只支持打印抽象语法树，而且还有BUG没有改完！** 
样例输入`test.sy`：
```c++
void main(int a) {
    continue;
    return 1;

    if (~(false ^ 5) != !false) {
        while (true) {
            int a = 3 * 3 + 4 - b;
        }
    } else {
        continue;
    }
}
```
样例输出：
```
 Takanashi Compiler is running!! 
Program Root: 
└──Node: Function Definition with return type void
│  │  ├──Node: Identifier with name main
│  │  ├──Node: Function Definition Argument List
│  │  │  │  └──Node: Function Definition Argument with type int
│  │  │  │  │  │  └──Node: Identifier with name a
│  │  ├──Node: Block
│  │  │  │  ├──Node: Continue Statement
│  │  │  │  ├──Node: Return statement
│  │  │  │  │  │  └──Node: Literal Numeric with value 1
│  │  │  │  └──Node: If-else Statement
│  │  │  │  │  │  ├──Node: Binary Expression with type Conditional_nonequal
│  │  │  │  │  │  │  │  ├──Node: Unary Expression with type BIT_NEGATIVE
│  │  │  │  │  │  │  │  │  │  ├──Node: Binary Expression with type Bitwise_xor
│  │  │  │  │  │  │  │  │  │  │  │  ├──Node: Literal Numeric with value 0
│  │  │  │  │  │  │  │  │  │  │  │  └──Node: Literal Numeric with value 5
│  │  │  │  │  │  │  │  └──Node: Unary Expression with type LOGIC_NOT
│  │  │  │  │  │  │  │  │  │  ├──Node: Literal Numeric with value 0
│  │  │  │  │  │  ├──Node: Block
│  │  │  │  │  │  │  │  └──Node: While Statement
│  │  │  │  │  │  │  │  │  │  ├──Node: Literal Numeric with value 1
│  │  │  │  │  │  │  │  │  │  └──Node: Block
│  │  │  │  │  │  │  │  │  │  │  │  └──Node: Declaration
│  │  │  │  │  │  │  │  │  │  │  │  │  │  └──Node: Variale Declaration with initial value
│  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │  ├──Node: Identifier with name a
│  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │  └──Node: Binary Expression with type Sub
│  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │  ├──Node: Binary Expression with type Add
│  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │  ├──Node: Binary Expression with type Mul
│  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │  ├──Node: Literal Numeric with value 3
│  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │  └──Node: Literal Numeric with value 3
│  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │  └──Node: Literal Numeric with value 4
│  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │  └──Node: Identifier with name b
│  │  │  │  │  │  └──Node: Block
│  │  │  │  │  │  │  │  └──Node: Continue Statement
```

* TODO: 做个输出的美化~

### 项目布局（截止2021-10-30）
```
├── backup
├── include
│   ├── common
│   ├── frontend
│   │   ├── nodes
│   │   ├── parser
│   │   └── symbol_table
│   ├── ir
│   └── runtime
└── src
    ├── backend
    ├── common
    ├── frontend
    │   ├── ir
    │   ├── nodes
    │   ├── parser
    │   └── symbol_table
    └── runtime
```

### 继承关系和几点说明
🚧施工中🚧
* 类和其文件名是一样的，想要找什么就直接去对应的文件里面找就行。
* 所有节点的基类都是`Item`，而该类是抽象基类，请不要实例化，它只能通过指针的形式使用。
* `Item_expr`继承自`Item`，基本上别的类都是从这里长出来的。
* `Item_stmt`继承自`Item_expr`，代表表达式类型。
* 为什么不把`Item_stmt`作为`Item`的子节点？那是因为`Item_stmt`包含`Item_expr`，但是如果`Item_expr`又是`item_stmt`的子节点的话，就会互相包含无穷无尽了。
* `frontend`为前端分析所需要的源文件和头文件，而`backend`存储了汇编指令生成和中间代码优化等相关文件；`common`是一些通用的枚举类以及一些工具。

```
Item -> Item_expr -> Item_expr_cond
                  -> Item_ident         -> Item_ident_array

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

     -> Item_func_def
```

#### Prerequisites
* C++标准默认为17，请使用支持C++17以上的编译器进行编译，已知可以在clang 12和GCC-11（需要链接到flex和yacc）上运行。
* 采用了cxxopts库作为command line parser，具体实现已经放在了`src/runtime/runtime.cc`中了。