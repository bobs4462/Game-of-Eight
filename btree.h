#include <eight.h>



struct state {
    ui val;
    goeptr adr;
    struct state * left; 
    struct state * right; 
};

typedef struct state * stptr;
typedef unsigned int ui;

extern int nc;

int attach(stptr root, ui newval, stptr *hit);
void treedelete(stptr root);
stptr leaf(ui newval);

void inline checkbal(void);
stptr * collapse(stptr root);
void spush(stptr **stack, int *stsz, stptr node);
stptr spop(stptr **stack, int *stsz);
stptr rebalance(stptr root);
stptr restore(stptr *treearray, int start, int end);
