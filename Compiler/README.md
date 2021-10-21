## Basic Framework for Project Compiler

### 设计目标
* 纯C++实现；
* 采用多态和虚函数实现抽象语法树（Abstract Syntax Tree）的构建；
* 中间代码生成 （IR）；
* 汇编代码生成；


### 项目布局（截止2021-10-21）
```
├── include
│   ├── compiler_body.hh
│   ├── item.hh
│   ├── item_decl.hh
│   ├── item_def.hh
│   ├── item_expr.hh
│   ├── item_ident.hh
│   ├── item_stmt.hh
│   ├── symbol_table.hh
│   ├── types.hh
│   └── utils.hh
└── src
    ├── item.cc
    ├── item_expr.cc
    ├── item_ident.cc
    ├── item_stmt.cc
    └── symbol_table.cc
```

### 继承关系和几点说明
🚧施工中🚧
* 类和其文件名是一样的，想要找什么就直接去对应的文件里面找就行。
* 所有节点的基类都是`Item`，而该类是抽象基类，请不要实例化，它只能通过指针的形式使用。
* `Item_stmt`继承自`Item`，基本上别的类都是从这里长出来的。
* `Item_expr`继承自`Item_stmt`，代表表达式类型。

```
Item -> Item_stmt -> Item_expr -> Item_expr_cond
                               -> Item_ident        -> Item_ident_int
                                                    -> Item_ident_real
                                                    -> Item_ident_char
                                                    -> Item_ident_str
                  -> Item_block
                  -> Item_stmt_eif
                  -> Item_stmt_while
                  -> Item_stmt_for
                  -> Item_stmt_return
                  -> Item_stmt_break
                  -> Item_stmt_continue
                  -> Item_decl           
```