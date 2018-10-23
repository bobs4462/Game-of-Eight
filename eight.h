#include <stdio.h>
#include <stdlib.h>

struct goe {
    char board[9];
    struct goe **moves;
    unsigned char mcount;
};

typedef struct goe * goeptr;


char *mright(char *cstate, char pos);
char *mleft(char *cstate, char pos);
char *mdown(char *cstate, char pos);
char *mup(char *cstate, char pos);
    
