############# DRAFT. 
FLEX = flex
YACC = yacc		# or bison

INCLUDE = include
SRC_DIR = src
OBJ_DIR = obj
TARGET  = $(OBJ_DIR)/compiler.bin
SRC 	= $(wildcard $(SRC_DIR)/*.cc)
LEXER   = $(SRC_DIR)/lexer.l
PARSER	= $(SRC_DIR)/tokenizer.ypp
OBJ 	= $(patsubst $(SRC_DIR)/%.cc, $(OBJ_DIR)/%.o, $(SRC))

CXXFLAGS = -std=c++17 -I$(INCLUDE) -Wno-register -Wextra -Wno-nullability-completeness -O2

.phony: mk all

mk:
	mkdir -p $(OBJ_DIR)
	$(YACC) -d -o $(PARSER)
	$(FLEX) -o $(LEXER)
	mv $(SRC_DIR)/yacc.h $(INCLUDE)

all: mk $(OBJ)
	$(CXX) -o $(TARGET) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $<