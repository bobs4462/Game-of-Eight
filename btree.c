#include "btree.h"
ui nc; //node count

int attach(stptr root, ui newval) 
{
    stptr tracker = root;
    while (1) {
        if (newval == tracker->val)
            return 1;
        else if ((newval < tracker->val) && (tracker->left != NULL))
            tracker = tracker->left;
        else if ((newval < tracker->val) && (tracker->left == NULL)) {
            tracker->left = leaf(newval); 
            return 0;
        }
        else if ((newval > tracker->val) && (tracker->right != NULL))
            tracker = tracker->right;
        else { 
            tracker->right = leaf(newval); 
            return 0;
        }
    }
}


stptr leaf(ui newval) 
{
    stptr temp = malloc(sizeof(struct state));
    if(!temp)
        exit(0);
    temp->val = newval;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}

stptr * collapse(stptr root)
{
    stptr *treearray = malloc(sizeof(stptr) * nc);
    stptr *stack = malloc(sizeof(stptr));
    stptr tracker = root; ui stsz = 1, i = 0;
    do {
        while (tracker) {
            push(&stack, &stsz, tracker); 
            tracker = tracker->left;
        }
        treearray[i] = pop(&stack, &stsz);
        tracker = treearray[i++]->right;
    } while (i < nc);
    return treearray;
}

void push(stptr **stack, ui *stsz, stptr node)
{
    *stack = realloc(*stack, sizeof(stptr) * (++(*stsz)));
    (*stack)[*stsz - 1] = node;
}

stptr rebalance(stptr root)
{
    stptr * treearray = collapse(root);
    stptr newroot = restore(treearray, 0, nc - 1);
    free(treearray);
    return newroot;
}

stptr pop(stptr **stack, ui *stsz)
{
    stptr temp = (*stack)[*stsz - 1];
    *stack = realloc(*stack, sizeof(stptr) * (--(*stsz)));
    return temp;
}

stptr restore(stptr *treearray, int start, int end)
{
    if (start > end)
        return NULL;
    int middle = (start + end) / 2;
    stptr newroot = treearray[middle];
    newroot->left = restore(treearray, start, middle - 1);
    newroot->right = restore(treearray, middle + 1, end);
    return newroot;
}

   

