############# DRAFT.
CXX  := clang++
FLEX := flex
YACC := yacc		# or bison
UNIX := $(shell uname)
MODE ?= DEBUG

INCLUDE   := ./include
SRC_DIR   := ./src
BUILD_DIR := ./build
LIB_DIR   := ./lib
TARGET    := $(BUILD_DIR)/compiler.bin
# Invoke shell command to find all source files recursively.
SRC 	  := $(shell find $(SRC_DIR) -regex ".*.cc")
LEXER     := $(shell find $(SRC_DIR) -regex ".*.l")
PARSER	  := $(shell find $(SRC_DIR) -regex ".*.ypp")
OBJ 	  := $(patsubst $(SRC_DIR)/%.cc, $(BUILD_DIR)/%.o, $(SRC))
RUN_FILES := $(wildcard $(SRC_DIR)/runtime/*.cc)
RUNTIME   := $(patsubst $(SRC_DIR)/runtime/%.cc, $(BUILD_DIR)/runtime/%.o, $(RUN_FILES))
SHARED    := $(LIB_DIR)/libsysy.so $(LIB_DIR)/libruntime.so

BRANCH := $(shell git rev-parse --abbrev-ref HEAD)

ifneq ($(CXX), "clang++")
	CXXFLAGS := -std=c++17 -I$(INCLUDE) -I$(LIB_DIR) -Wextra -Werror \
				-Wno-sign-compare \
				-Wno-unused-parameter
else
	CXXFLAGS := -std=c++17 -I$(INCLUDE) -I$(LIB_DIR) -Wextra -Werror \
				-Wno-sign-compare \
				-Wno-unused-parameter \
				-Wno-nullability-completeness \
				-Wno-register
endif

# Load SysY runtime library.
LD_FLAG := -Wl,-rpath=$(LIB_DIR) -L$(LIB_DIR) -lstdc++fs  -lsysy -lruntime

ifeq ($(MODE), "DEBUG")
	CXXFLAGS += -O0 -g
else
	CXXFLAGS += -O2
endif

.phony: mk all clean push
# Create directories for object files.
mk:
ifeq ("$(wildcard $(BUILD_DIR))", "")
	@mkdir -p $(BUILD_DIR)/frontend/nodes $(BUILD_DIR)/frontend/ir \
	 		  $(BUILD_DIR)/frontend/parser $(BUILD_DIR)/frontend/symbol_table
	@mkdir -p $(BUILD_DIR)/backend
	@mkdir -p $(BUILD_DIR)/common
	@mkdir -p $(BUILD_DIR)/runtime
	@mkdir -p $(BUILD_DIR)/ir
	@mkdir -p $(BUILD_DIR)/shared
endif

$(TARGET): mk $(OBJ) $(SHARED) 
	@$(CXX) -o $(TARGET) $(OBJ) $(LD_FLAG) 
	@echo "LINKER => $(TARGET)"

# Create libsysy library
$(LIB_DIR)/libsysy.so: $(LIB_DIR)/sylib.o
	@$(CXX) -shared $< -o $@
	@echo "SHARED => $@"

$(LIB_DIR)/libruntime.so: $(RUNTIME)
	@$(CXX) -shared $^ -o $@
	@echo "SHARED => $@"

$(LIB_DIR)/sylib.o: $(LIB_DIR)/sylib.cc
	@$(CXX) $(CXXFLAGS) -fPIC -c $< -o $@
	@echo "CXX => $@"

# Compile runtime objects.
$(BUILD_DIR)/runtime/%.o: $(SRC_DIR)/runtime/%.cc
	@$(CXX) $(CXXFLAGS) -fPIC -c $< -o $@
	@echo "CXX => $@"

# Compile to object files.
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "CXX => $@"

$(SRC_DIR)/frontend/parser/parser.cc: $(SRC_DIR)/frontend/parser/parser.ypp
	@printf "\033[4;90;107mPreparing necessary yacc file...\033[0m\n"
	@$(YACC) -d -o $(SRC_DIR)/frontend/parser/parser.cc $(PARSER)
	@echo "YACC => $@"
	@mv $(SRC_DIR)/frontend/parser/parser.hh $(INCLUDE)/frontend/parser

$(SRC_DIR)/frontend/parser/lexer.cc: $(SRC_DIR)/frontend/parser/lexer.l
	@printf "\033[4;90;107mPreparing necessary lex file...\033[0m\n"
	@$(FLEX) -o $(SRC_DIR)/frontend/parser/lexer.cc $(LEXER)
	@echo "flex => $@"
	
all: $(TARGET)
	@echo "Target built."

# Prompt warning to ensure remove.
clean:
ifneq ("$(wildcard $(BUILD_DIR))", "")
	@echo "Do you want to remove build path? [Y/n]"
	@read line; if [ $$line = "n" ]; then echo aborting; exit 1 ; fi
	@rm -rf $(BUILD_DIR)
	@rm -rf ./test/functional/output
	@printf "\033[4;90;107mCleaned up the build path:)\033[0m\n"
endif

# You can push to the Git repository by make push.
push:
ifeq ($(BRANCH), "main")
	@printf "\033[4;31;107mYou are trying to push to main branch, stop.\033[0m\n"
	@exit 1
else
	@git add .
	@echo "Enter some commit information.";
	@read line; git commit -m "$$line";
	@printf "Do you want to push to the branch \033[4;31;107m origin \033[0m ? [Y/n]\n"
	@read line; if [ $$line = "n" ]; then echo aborting; exit 1 ; fi
	@git push origin $(BRANCH)
	@git push --mirror github
	@git checkout main
	@git merge $(BRANCH)
	@git checkout $(BRANCH)
endif