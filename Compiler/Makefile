############# DRAFT. 
CXX = clang++
FLEX = flex
YACC = yacc		# or bison

INCLUDE = ./include
SRC_DIR = ./src
BUILD_DIR = ./build
TARGET  = $(OBJ_DIR)/compiler.bin
SRC 	= $(wildcard $(SRC_DIR)/frontend/parser/*.cc $(SRC_DIR)/frontend/nodes/*.cc $(SRC_DIR)/common/*.cc)
LEXER   = $(SRC_DIR)/frontend/parser/lexer.l
PARSER	= $(SRC_DIR)/frontend/parser/parser.ypp
OBJ 	= $(patsubst $(SRC_DIR)/%.cc, $(BUILD_DIR)/%.o, $(SRC))

CXXFLAGS = -std=c++17 -I$(INCLUDE) -Wno-register -Wextra -Wno-nullability-completeness -Werror -O2

.phony: mk all clean

mk:
ifeq ("$(wildcard $(BUILD_DIR))", "")
	mkdir -p $(BUILD_DIR)/frontend/nodes $(BUILD_DIR)/frontend/ir $(BUILD_DIR)/frontend/parser
	mkdir -p $(BUILD_DIR)/backend 
	mkdir -p $(BUILD_DIR)/common/runtime
endif

	$(YACC) -d -o $(SRC_DIR)/frontend/parser/parser.cc $(PARSER)
	mv $(SRC_DIR)/frontend/parser/parser.hh $(INCLUDE)/frontend/parser
	$(FLEX) -o $(SRC_DIR)/frontend/parser/lexer.cc $(LEXER)

all: mk $(OBJ)
	$(CXX) -o $(TARGET) $(OBJ)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
ifneq ("$(wildcard $(BUILD_DIR))", "")
	rm -rf $(BUILD_DIR)
	$(info "\033[4;90;107mCleaned up the build path\033[0m:)")
endif