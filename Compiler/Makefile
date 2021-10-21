############# DRAFT. 
CXX = clang++
FLEX = flex
YACC = yacc		# or bison

INCLUDE = include
SRC_DIR = src
OBJ_DIR = obj
TARGET  = $(OBJ_DIR)/compiler.bin
SRC 	= $(wildcard $(SRC_DIR)/backend/parser/*.cc $(SRC_DIR)/frontend/nodes/*.cc)
LEXER   = $(SRC_DIR)/frontend/parser/lexer.l
PARSER	= $(SRC_DIR)/frontend/parser/parser.y
OBJ 	= $(patsubst $(SRC_DIR)/%.cc, $(OBJ_DIR)/%.o, $(SRC))

CXXFLAGS = -std=c++17 -I$(INCLUDE) -Wno-register -Wextra -Wno-nullability-completeness -O2

.phony: mk all

mk:
	mkdir -p $(OBJ_DIR)
	$(YACC) -d -o $(SRC_DIR)/frontend/parser.cc $(PARSER)
	$(FLEX) -o $(SRC_DIR)/frontend/lexer.cc $(LEXER)
	mv $(SRC_DIR)/frontend/yacc.h $(INCLUDE)

all: mk $(OBJ)
	$(CXX) -o $(TARGET) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $<