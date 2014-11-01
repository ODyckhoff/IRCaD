#ifndef PARSE_H
#define PARSE_H

#include "token.h"
#include "ptree.h"

int parse(char *expr);
void shunt(struct tok_t **toklist);
struct ptree *mkptree(struct tok_t **toklist);

#endif /* PARSE_H */
