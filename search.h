#ifdef SEARCHH
#include <btree.h>

struct linklist {
    goeptr value;
    struct linklist *next;
};

typedef struct linklist * ll;
ll addstart(ll head, goeptr node);
void addend(ll tail, goeptr node);
void traceback(goeptr root, goeptr endstate);
void printboard(char board[9]);
#endif
extern int mode;
goeptr * solve(goeptr root, goeptr endstate);

