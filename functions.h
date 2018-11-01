#include <stdio.h>
#include <stdlib.h>

struct goe { 
    struct goe *wayback;
    char board[9];
    struct goe **moves;
    unsigned char mc; 
};

typedef struct goe * goeptr;
typedef unsigned int ui;

struct state {
    ui val;
    goeptr adr;
    struct state * left; 
    struct state * right; 
};

struct linklist {
    goeptr value;
    struct linklist *next;
};

typedef struct linklist * ll;

typedef struct state * stptr;
typedef unsigned int ui;


extern int nc;
extern int mode;
extern ui balance;


char *mright(char *cstate);
char *mleft(char *cstate);
char *mdown(char *cstate);
char *mup(char *cstate);
goeptr buildss(char initstate[9], stptr *ind);//build state-space
ui powoften(ui i); //power of ten
goeptr create_state(char *board);
void gpush(goeptr **gstack, ui *gss, goeptr node);
goeptr gpop(goeptr **gstack, ui *gss);
ui get_s_code(char *board);//get state code
goeptr buildss(char initstate[9],stptr *ind);//build state-space


int attach(stptr root, ui newval, stptr *hit);
void treedelete(stptr root);
stptr leaf(ui newval);

void checkbal(stptr *index);
stptr * collapse(stptr root);
void spush(stptr **stack, int *stsz, stptr node);
stptr spop(stptr **stack, int *stsz);
stptr rebalance(stptr root);
stptr restore(stptr *treearray, int start, int end);
ll addstart(ll head, goeptr node);
ll addend(ll tail, goeptr node);
void traceback(goeptr root, goeptr endstate);
void printboard(char board[9], FILE *fptr);
goeptr * solve(goeptr root, goeptr endstate);

