############# DRAFT. 
CXX = clang++
FLEX = flex
YACC = yacc		# or bison

INCLUDE = ./include
SRC_DIR = ./src
BUILD_DIR = ./build
TARGET  = $(BUILD_DIR)/compiler.bin
# Invoke shell command to find all source files recursively.
SRC 	= $(shell find $(SRC_DIR) -regex ".*.cc")
LEXER   = $(shell find $(SRC_DIR) -regex ".*.l")
PARSER	= $(shell find $(SRC_DIR) -regex ".*.ypp")
OBJ 	= $(patsubst $(SRC_DIR)/%.cc, $(BUILD_DIR)/%.o, $(SRC))

ifeq ($(CXX), "clang++")
	CXXFLAGS := -std=c++17 -I$(INCLUDE) -g -Wextra -Werror -O2 \
				-Wno-sign-compare \
				-Wno-unused-parameter
else
	CXXFLAGS := -std=c++17 -I$(INCLUDE) -g -Wextra -Werror -O2 \
				-Wno-sign-compare \
				-Wno-unused-parameter \
				-Wno-nullability-completeness \
				-Wno-register
endif

.phony: mk all clean

mk:
ifeq ("$(wildcard $(BUILD_DIR))", "")
# Create directories for object files.
	@mkdir -p $(BUILD_DIR)/frontend/nodes $(BUILD_DIR)/frontend/ir \
	 		  $(BUILD_DIR)/frontend/parser $(BUILD_DIR)/frontend/symbol_table
	@mkdir -p $(BUILD_DIR)/backend 
	@mkdir -p $(BUILD_DIR)/common
	@mkdir -p $(BUILD_DIR)/runtime
endif
# Create yacc and lex source files.
	@printf "\033[4;90;107mPreparing necessary yacc and lex files...\033[0m\n"
	$(YACC) -d -o $(SRC_DIR)/frontend/parser/parser.cc $(PARSER)
	@mv $(SRC_DIR)/frontend/parser/parser.hh $(INCLUDE)/frontend/parser
	$(FLEX) -o $(SRC_DIR)/frontend/parser/lexer.cc $(LEXER)

all: mk $(OBJ)
	$(CXX) -o $(TARGET) $(OBJ)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc
# Compile to object files.
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
ifneq ("$(wildcard $(BUILD_DIR))", "")
# Prompt warning to ensure remove.
	@echo "Do you want to remove build path? [Y/n]"
	@read line; if [ $$line = "n" ]; then echo aborting; exit 1 ; fi
	@rm -rf $(BUILD_DIR)
	@printf "\033[4;90;107mCleaned up the build path:)\033[0m\n"
endif