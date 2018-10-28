#include "btree.h"

int main(void)
{
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    stptr root = malloc(sizeof(struct state));
    root->val = array[0];
    int i = 1;
    while(i < 10)
        attach(root, array[i++]);
    nc = 10;
    root = rebalance(root);
}
