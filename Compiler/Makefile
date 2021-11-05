############# DRAFT. 
FLEX := flex
YACC := yacc		# or bison
UNIX := $(shell uname)

INCLUDE := ./include
SRC_DIR := ./src
BUILD_DIR := ./build
TARGET  := $(BUILD_DIR)/compiler.bin
SHARED  := $(BUILD_DIR)/shared/libruntime.so
# Invoke shell command to find all source files recursively.
SRC 	:= $(shell find $(SRC_DIR) -regex ".*.cc")
LEXER   := $(shell find $(SRC_DIR) -regex ".*.l")
PARSER	:= $(shell find $(SRC_DIR) -regex ".*.ypp")
OBJ 	:= $(patsubst $(SRC_DIR)/%.cc, $(BUILD_DIR)/%.o, $(SRC))
SOBJ    := $(patsubst $(BUILD_DIR)/rumtime/%.o, $(BUILD_DIR)/runtime/%.so, $(OBJ))

BRANCH := $(shell git rev-parse --abbrev-ref HEAD)

ifeq ($(UNIX), "Linux")
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

LINK_FLAG := -shared -fPIC

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

$(SHARED): $(SOBJ)
	@$(CXX) $(LINK_FLAG) $^ -o $@

$(TARGET): mk $(OBJ) $(SHARED)
	@$(CXX) -o $(TARGET) $(OBJ) -L$(BUILD_DIR)/shared -lruntime
	@echo "LINKER => $(TARGET)"

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

# Prompt warning to ensure remove.
clean:
ifneq ("$(wildcard $(BUILD_DIR))", "")
	@echo "Do you want to remove build path? [Y/n]"
	@read line; if [ $$line = "n" ]; then echo aborting; exit 1 ; fi
	@rm -rf $(BUILD_DIR)
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
endif