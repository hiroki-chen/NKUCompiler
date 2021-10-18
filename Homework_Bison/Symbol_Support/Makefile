# Makefile created by Haobin Chen (@Aoyamahiroki)

CXX = g++-11
CXXFLAGS = -g -o expr -Wno-register
SRC = yacc.c symbol.c

YACC = expr.y

.PHONY: all

all: $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC)

$(SRC): $(YACC)
	yacc -d -o yacc.c $(YACC)
