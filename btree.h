#include <eight.h>


struct state {
    ui val;
    goeptr adr;
    struct state * left; 
    struct state * right; 
};

typedef struct state * stptr;
typedef unsigned int ui;

extern ui nc;

int attach(stptr root, ui newval, stptr *hit);
stptr leaf(ui newval);
stptr * collapse(stptr root);
void spush(stptr **stack, ui *stsz, stptr node);
stptr spop(stptr **stack, ui *stsz);
stptr rebalance(stptr root);
stptr restore(stptr *treearray, ui start, ui end);
