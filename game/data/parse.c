/* parse.c - provides the shunting yard algorithm, and parse tree building algorithm. */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int parse(char *expr) {
    
    tok_t **toklist;
    toklist = tokenise(expr);

    shunt(toklist);
    mkptree(toklist);

    return 0;
}
