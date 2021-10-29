CXX = clang++ # Specify your compiler version
FLEX = flex
YACC = yacc		# or bison

INCLUDE = ./include
SRC_DIR = ./src
BUILD_DIR = ./build
TARGET  = $(BUILD_DIR)/lexer.bin
SRC 	= $(wildcard $(SRC_DIR)/*.cc)
LEXER   = $(SRC_DIR)/lexer.l
PARSER	= $(SRC_DIR)/tokenizer.ypp
OBJ 	= $(patsubst $(SRC_DIR)/%.cc, $(BUILD_DIR)/%.o, $(SRC))

CXXFLAGS = -std=c++17 -I$(INCLUDE) -Wno-register -Wextra -Wno-nullability-completeness -O2

.phony: clean mk

clean:
	rm -rf $(BUILD_DIR)

mk:
ifeq ("$(wildcard $(BUILD_DIR))", "")
	mkdir -p $(BUILD_DIR)
endif
	$(FLEX)    -o $(SRC_DIR)/lexer.cc $(LEXER)
	$(YACC) -d -o $(SRC_DIR)/yacc.cc $(PARSER)
	mv $(SRC_DIR)/yacc.hh $(INCLUDE)

all: mk $(OBJ)
	$(CXX) -o  $(TARGET) $(OBJ) -ll
	$(TARGET) $(SY_IN) $(SY_OUT)

# DO AN EXPORT FIRST.

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $<