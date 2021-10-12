/*
 Copyright (c) 2021 Haobin Chen

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include "symbol.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct symbol* get_symbol(struct symbol* symbol_table, const char* name)
{
    struct symbol* sym;
    for (unsigned int i = 0; i < MAXIMUM_SYMBOL; i++) {
        sym = &symbol_table[i];
        if (sym->name != NULL && strcmp(sym->name, name) == 0) {
            return sym;
        }
    }

    for (unsigned int i = 0; i < MAXIMUM_SYMBOL; i++) {
        sym = &symbol_table[i];
        if (sym->name == NULL) {
            sym->name = strdup(name);
            sym->value = 0.0;
            return sym;
        }
    }

    fprintf(stderr, "Too many symbols!\n");
    exit(1);
}