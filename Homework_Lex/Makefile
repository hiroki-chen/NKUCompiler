CXX = clang++ # Specify your compiler version
FLEX = flex
YACC = yacc		# or bison

INCLUDE = include
SRC_DIR = src
OBJ_DIR = obj
TARGET  = $(OBJ_DIR)/lexer.bin
SRC 	= $(wildcard $(SRC_DIR)/*.cc)
LEXER   = $(SRC_DIR)/lexer.l
PARSER	= $(SRC_DIR)/tokenizer.ypp
OBJ 	= $(patsubst $(SRC_DIR)/%.cc, $(OBJ_DIR)/%.o, $(SRC))

CXXFLAGS = -std=c++17 -I$(INCLUDE) -Wno-register -Wextra -Wno-nullability-completeness -O2

.phony: clean mk

clean:
	rm -rf $(OBJ_DIR)

mk:
	mkdir -p $(OBJ_DIR)
	$(FLEX)    -o $(SRC_DIR)/lexer.cc $(LEXER)
	$(YACC) -d -o $(SRC_DIR)/yacc.cc $(PARSER)
	mv $(SRC_DIR)/yacc.hh $(INCLUDE)

all: mk $(OBJ)
	$(CXX) -o  $(TARGET) $(OBJ) -ll
	$(TARGET) $(SY_IN) $(SY_OUT)

# DO AN EXPORT FIRST.

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $<