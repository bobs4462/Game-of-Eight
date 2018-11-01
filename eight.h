#include <stdio.h>
#include <stdlib.h>
struct goe { //game of eight
    struct goe *wayback; //for creating bread crumbs for search algorithms
    char board[9];
    struct goe **moves;
    unsigned char mc; //move count
};

typedef struct goe * goeptr;
typedef unsigned int ui;

#ifdef EIGHTH
char *mright(char *cstate);
char *mleft(char *cstate);
char *mdown(char *cstate);
char *mup(char *cstate);
goeptr buildss(char initstate[9], stptr *ind);//build state-space
ui powoften(ui i); //power of ten
goeptr create_state(char *board);
void gpush(goeptr **gstack, ui *gss, goeptr node);
goeptr gpop(goeptr **gstack, ui *gss);
#endif
ui get_s_code(char *board);//get state code

#ifdef MAINH
goeptr buildss(char initstate[9],stptr *ind);//build state-space
#endif
