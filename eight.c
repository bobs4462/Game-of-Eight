#include <eight.h>

const char (*p[4]) (char *, char) = { mright, mleft, mdown, mup };

goeptr buildss(char initstate[9])
{
    unsigned int 
    int clw = 0; nlw = 0; 
    goeptr *cl = NULL, *nl = NULL;
    goeptr root = malloc(sizeof(struct goe)); 
    for (int i = 9; i--; root->board[i] = initstate[i]);
    cl = malloc(sizeof(goeptr));
    cl = root;
    while (1) {
        
}

char *mright(char *cstate, char pos)
{
    int t = 0;
    if (((pos + 1) / 3 == pos / 3) && ((pos + 1) != 9)) {
        t = cstate[pos];
        cstate[pos] = cstate[pos + 1];
        cstate[++pos] = t;
        return cstate;
    }
    else return NULL;
}

char *mleft(char *cstate, char pos)
{
    int t = 0;
    if (((pos - 1) / 3 == pos / 3) && ((pos - 1) >= 0)) {
        t = cstate[pos];
        cstate[pos] = cstate[pos - 1];
        cstate[--pos] = t;
        return cstate;
    }
    else return NULL;
}

char *mdown(char *cstate, char pos)
{
    int t = 0;
    if ((pos + 3) < 9) {
        t = cstate[pos];
        cstate[pos] = cstate[pos + 1];
        cstate[++pos] = t;
        return cstate;
    }
    else return NULL;
}

char *mup(char *cstate, char pos)
{
    int t = 0;
    if ((pos - 3) >= 0) {
        t = cstate[pos];
        cstate[pos] = cstate[pos + 1];
        cstate[++pos] = t;
        return cstate;
    }
    else return NULL;
}
