#include <stdio.h>
#include <stdlib.h>

struct goe { //game of eight
    char board[9];
    struct goe **moves;
    unsigned char mc; //move count
};

typedef struct goe * goeptr;


char *mright(char *cstate);
char *mleft(char *cstate);
char *mdown(char *cstate);
char *mup(char *cstate);
    
