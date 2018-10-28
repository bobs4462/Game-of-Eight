#include <stdlib.h>
#include <stdio.h>
#include <eight.h>

typedef unsigned int ui;

struct state {
    ui val;
    goeptr adr;
    struct state * left; 
    struct state * right; 
};

typedef struct state * stptr;
typedef unsigned int ui;

extern ui nc;

int attach(stptr root, ui newval);
stptr leaf(ui newval);
stptr * collapse(stptr root);
void push(stptr **stack, ui *stsz, stptr node);
stptr rebalance(stptr root);
stptr pop(stptr **stack, ui *stsz);
stptr restore(stptr *treearray, int start, int end);
