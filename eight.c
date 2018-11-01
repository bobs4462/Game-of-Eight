#include <functions.h>

char * (*m[4]) (char *) = { mright, mleft, mdown, mup }; 

goeptr buildss(char initstate[9], stptr *ind) //build state-space
{
    ui balance = 500;
    ui f = 0, grl = 0, gss = 1;  //function index, general counter, goeptr stack size
    goeptr *gstack = malloc(sizeof(goeptr)); //goeptr stack for keeping intermediate board states before processing
    char testboard[9];//temporary array for storing board states

    stptr index = malloc(sizeof(struct state)); //root of index b tree
   
    nc = 1;//index entry count
    stptr hit = NULL; //vertex of index tree where new node was attached or match was found

    goeptr root = create_state(initstate);//first vertex of state space aka initial state
    goeptr imt = NULL; //intermediate pointer to goe struct, to keep popped values from gstack 

    index->val = get_s_code(root->board);//initalizing root of index btree
    index->adr = root;
    index->left = index->right = NULL;

    *gstack = root; //"pushing" first element to stack to kickstart SS build process

    while (gstack) {//loop will terminate once all possible states have been processed and added to graph
        imt = gpop(&gstack, &gss); //getting board state from stack for subsequent processing

        for (f = 4; f-->0;) { //apply 4 operators to board state to get new states
            for (int i = 9; i--; testboard[i] = imt->board[i]); //copy board state to temporary place

            if ((*m[f]) (testboard)) //true only if move is possible
                if (attach(index, get_s_code(testboard), &hit)) {//if state already has been processed returns true
                    imt->moves = realloc(imt->moves, sizeof(goeptr) * (++(imt->mc)));//add connection between state under
                    imt->moves[imt->mc - 1] = hit->adr;                              //processing and the one that already has been processed
                }
                else {
                    gpush(&gstack, &gss, create_state(testboard));      //if state is new push it to stack
                    imt->moves = realloc(imt->moves, sizeof(goeptr) * (++(imt->mc)));//and add necessary connection
                    imt->moves[imt->mc - 1] = hit->adr = gstack[gss - 1];
                    --balance;
                }
        } 
        if (!balance) {//500 insertions have been performed
            index = rebalance(index);//rebalance the tree
            balance = 500; //resetting balance counter
        }

        if (!gss)//all states have been processed, time to get out of loop
            gstack = NULL;
    }
    *ind = index;
    return root;//for subsequent search algorithm;

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
    ui code = 0, i = 0;
    while (i < 9) {
        code += board[i] * powoften(9 - i - 1);
        ++i;
    }
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

void gpush(goeptr **gstack, ui *gss, goeptr node)
{
    *gstack = realloc(*gstack, sizeof(goeptr) * (++(*gss)));
    (*gstack)[*gss - 1] = node;
}

goeptr gpop(goeptr **gstack, ui *gss)
{
    goeptr temp = (*gstack)[*gss - 1];
    *gstack = realloc(*gstack, sizeof(goeptr) * (--(*gss)));
    return temp;
}
