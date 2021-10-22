## Basic Framework for Project Compiler

### 设计目标
* 纯C++实现；
* 采用多态和虚函数实现抽象语法树（Abstract Syntax Tree）的构建；
* 中间代码生成 （IR）；
* 汇编代码生成；


### 项目布局（截止2021-10-22）
```
├── backup
├── include
│   ├── common
│   ├── frontend
│   │   └── nodes
│   ├── ir
│   └── runtime
├── src
│   ├── backend
│   ├── frontend
│   │   ├── ir
│   │   ├── nodes
│   │   └── parser
│   └── runtime
```

### 继承关系和几点说明
🚧施工中🚧
* 类和其文件名是一样的，想要找什么就直接去对应的文件里面找就行。
* 所有节点的基类都是`Item`，而该类是抽象基类，请不要实例化，它只能通过指针的形式使用。
* `Item_expr`继承自`Item`，基本上别的类都是从这里长出来的。
* `Item_stmt`继承自`Item_expr`，代表表达式类型。
* 为什么不把`Item_stmt`作为`Item`的子节点？那是因为`Item_stmt`包含`Item_expr`，但是如果`Item_expr`又是`item_stmt`的子节点的话，就会互相包含无穷无尽了。

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

     -> Item_decl -> Item_decl_var      -> Item_decl_var_init
                  -> Item_decl_array    -> Item_decl_array_init
                  
     -> Item_func_def
```

#### Prerequisites
* C++标准默认为17，请使用支持C++17以上的编译器进行编译，已知可以在clang 12和GCC-11上运行。
* 采用了cxxopts库作为command line parser，具体实现已经放在了`src/runtime/runtime.cc`中了。