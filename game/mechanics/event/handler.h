#ifndef HANDLER_H
#define HANDLER_H

#include "event.h"

typedef struct event_t {
    int type;
    int category;
} event_t;

int makeevent(int type, int category);
    
#endif /* HANDLER_H */
