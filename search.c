#define SEARCHH
#include <functions.h>
int mode = 0;

goeptr * solve(goeptr root, goeptr endstate)
{
    nc = 1;
    stptr index = leaf(get_s_code(root->board));
    stptr hit = NULL;
    goeptr temp = NULL;
    ll head = malloc(sizeof(struct linklist));
    ll tail = head;
    ll useless = NULL;
    head->value = root;
    head->next = NULL;

    while (head->value != endstate) {
        useless = head;
        if (mode)
            head = head->next;
        for (int i = 0; i < useless->value->mc; i++) {
            temp = useless->value->moves[i];
            if (!attach(index, get_s_code(temp->board), &hit)) {
                temp->wayback = useless->value;
                if (mode) 
                    head = addstart(head, temp);
                else
                    tail = addend(tail, temp);
            }
        }
        if (!mode)
            head = head->next;
        free(useless);
    }
    traceback(root, endstate);
    treedelete(index);
}

ll addstart(ll head, goeptr node)
{
    ll temp = malloc(sizeof(struct linklist));
    temp->value = node;
    temp->next = head;
    return temp;
}

ll addend(ll tail, goeptr node)
{
    ll temp = malloc(sizeof(struct linklist));
    temp->value = node;
    temp->next = NULL;
    tail->next = temp;
    return temp; 
}
   
void traceback(goeptr root, goeptr endstate)
{
    goeptr tracker = endstate;
    FILE *fptr = fopen("/home/bobur/Solution.txt", "w+");
    while (tracker != root) {
        printboard(tracker->board, fptr);
        tracker = tracker->wayback;
    } 
    printboard(tracker->board,fptr);
}

void printboard(char board[9], FILE *fptr)
{
    static int calls = 1;
    fprintf(fptr, "%d.\n\t\t======", calls++);
    for (int i = 0; i < 9; ++i)
        if (i % 3)
            fprintf(fptr, "%c ", board[i] + '0');
        else 
            fprintf(fptr, "\n\t\t%c ", board[i] + '0');
    fprintf(fptr, "\n\t\t======\n");
}





        


