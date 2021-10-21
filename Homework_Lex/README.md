#### LEX作业说明

如下是本项目的文件和文件夹分布。
```
.
├── Makefile            -> Makefile
├── README.md           
├── include             -> 头文件
├── obj                 -> object文件，用于编译成二进制可执行文件
├── src                 -> 存放lex、yacc和其他辅助C++文件的源文件
└── sy                -> 存放测试文件  
```

如果你想要使用这个东西的话，首先
1. 指定测试文件：
```shell
export SY_IN=<path/to/your/input/file>;
export SY_OUT=<path/to/your/output/file>; # 暂时没用到output，不过你还是指定一下
```
对于我目前设置的是：
```shell
export SY_IN=./sy/in;
export SY_IN=./sy/out;
```
你也可以自己修改Makefile，加入变量就行。

2. 目前指定的编译器是clang，你可以通过export改成g++，但是要记得Flex相关的动态链接库已经安装好了。

3. 船新安装只需要输入
```shell
export CXX=g++;
export SY_IN=./sy/in;
export SY_IN=./sy/out;
make all;
```
然后它自动就会运行：
```
mkdir -p obj
flex    -o src/lexer.cc src/lexer.l
yacc             -d -o src/yacc.cc src/tokenizer.ypp

mv src/yacc.hh include

clang++  -std=c++17 -Iinclude -Wno-register -Wextra -Wno-nullability-completeness -O2 -c -o obj/lexer.o src/lexer.cc
clang++  -std=c++17 -Iinclude -Wno-register -Wextra -Wno-nullability-completeness -O2 -c -o obj/yacc.o src/yacc.cc
clang++  -o  obj/lexer.bin  obj/item.o  obj/item_ident.o  obj/lexer.o  obj/symbol_table.o  obj/yacc.o -ll
obj/lexer.bin in out
```

### 其他
如果有啥不明白可以翻翻源文件，C++文件和头文件基本都加了注释:)