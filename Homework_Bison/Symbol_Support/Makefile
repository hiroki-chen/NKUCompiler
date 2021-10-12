# Makefile created by Haobin Chen (@Aoyamahiroki)

CXX = g++-11
CXXFLAGS = -g -o expr -Wno-register
SRC = yacc.c lex.c symbol.c

LEX = expr.l
YACC = expr.y

.PHONY: all

all: $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC)

$(SRC): $(LEX) $(YACC)
	yacc -d -o yacc.c $(YACC)
	lex -o lex.c $(LEX)

