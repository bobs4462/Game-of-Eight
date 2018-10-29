//make cl movable
#include <eight.h>
#include <btree.h>

const char * (*m[4]) (char *) = { mright, mleft, mdown, mup }; 

goeptr buildss(char initstate[9]) //build state-space
{
    ui clw = 1, nlw = 0, f = 0, grl = 0; 
    goeptr *cl = NULL, *nl = NULL;
    char testboard[9];
    stptr index = malloc(sizeof(struct state));
    nc = 0;
    stptr hit = NULL;
    goeptr root = create_state(initstate);

    index->val = get_s_code(root->board);
    index->adr = root;
    index->left = index->right = NULL;

    cl = malloc(sizeof(goeptr));
    cl = root;

    while (clw) {
        for (f = 4; f-->0;) {
            for (int i = 9; i--; testboard[i] = cl->board[i]); 
            if ((*m[0]) (testboard))
                if (attach(index, (grl = get_s_code(testboard)), &hit)) {
                    cl->moves = realloc(cl->moves, sizeof(goeptr) * (++(cl->mc)));
                    cl->moves[cl->mc - 1] = hit;
                }
                else {
                    nl = realloc(nl, sizeof(goeptr) * (++nlw));
                    nl[nlw - 1] = create_state(testboard);
                    hit->adr = nl[nlw - 1];
                    cl->moves = realloc(cl->moves, sizeof(goeptr) * (++(cl->mc)));
                    cl->moves[cl->mc - 1] = nl[nlw - 1];
                }
        } 
    }

}

char *mright(char *cstate)//move right
{
    int pos = -1;
    while (cstate[++pos]);
    if (((pos + 1) / 3 == pos / 3) && ((pos + 1) != 9)) {
        cstate[pos] = cstate[pos + 1];
        cstate[++pos] = 0;
        return cstate;
    }
    else return NULL;
}

char *mleft(char *cstate)//move left
{
    int pos = -1;
    while (cstate[++pos]);
    if (((pos - 1) / 3 == pos / 3) && ((pos - 1) >= 0)) {
        cstate[pos] = cstate[pos - 1];
        cstate[--pos] = 0;
        return cstate;
    }
    else return NULL;
}

char *mdown(char *cstate) //move down
{
    int pos = -1;
    while (cstate[++pos]);
    if ((pos + 3) < 9) {
        cstate[pos] = cstate[pos + 3];
        cstate[pos + 3] = 0;
        return cstate;
    }
    else return NULL;
}

char *mup(char *cstate) //move up
{
    int pos = -1;
    while (cstate[++pos]);
    if ((pos - 3) >= 0) {
        cstate[pos] = cstate[pos - 3];
        cstate[pos - 3] = 0;
        return cstate;
    }
    else return NULL;
}

ui get_s_code(char *board) //get state code
{
    ui code = 0, i = 9;
    while (i-->0)
        if (board[i])
            code = (board[i] - '0') * powoften(i);
    return code;
}

ui powoften(ui i) //power of ten
{
    ui num = 1;
    while (i-->0)
       num *= 10; 
    return num;
}

goeptr create_state(char *board)
{
    goeptr st = malloc(sizeof(struct goe));
    for (int i = 9; i--; st->board[i] = board[i]);
    st->moves = NULL;
    st->mc = 0;
    return st;
}
