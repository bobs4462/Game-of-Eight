#include <functions.h>
int nc; //node count

int attach(stptr root, ui newval, stptr *hit) 
{
    stptr tracker = root;
    while (1) {
        if (newval == tracker->val) {
            *hit = tracker;
            return 1;
        }
        else if ((newval < tracker->val) && (tracker->left != NULL)) tracker = tracker->left;
        else if ((newval < tracker->val) && (tracker->left == NULL)) {
            tracker->left = leaf(newval); 
            ++nc;
            *hit = tracker->left;
            return 0;
        }
        else if ((newval > tracker->val) && (tracker->right != NULL))
            tracker = tracker->right;
        else { 
            tracker->right = leaf(newval); 
            ++nc;
            *hit = tracker->right;
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


stptr rebalance(stptr root)
{
    stptr *treearray = collapse(root);
    stptr newroot = restore(treearray, 0, nc - 1);
    free(treearray);
    return newroot;
}

stptr * collapse(stptr root)
{
    stptr nullifier = NULL;
    stptr *treearray = malloc(sizeof(stptr) * nc);
    stptr *stack = malloc(sizeof(stptr));
    stptr tracker = root; 
    int stsz = 1, i = 0;
    do {
        while (tracker != NULL) {
            spush(&stack, &stsz, tracker); 
            tracker = tracker->left;
        }
        nullifier = spop(&stack, &stsz);
        treearray[i] = nullifier;  
        tracker = treearray[i++]->right;
        nullifier->left = nullifier->right = NULL;
    } while (i < nc);
    free(stack);
    return treearray;
}

void spush(stptr **stack, int *stsz, stptr node)
{
    *stack = realloc(*stack, sizeof(stptr) * (++(*stsz)));
    (*stack)[*stsz - 1] = node;
}

stptr spop(stptr **stack, int *stsz)
{
    int sts = *stsz;
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

void treedelete(stptr root)
{
    ui stsz = 1;
    stptr *stack = malloc(sizeof(stptr));
    stptr node = *stack = root;


    while (stsz) {
        if (node->left)
            spush(&stack, &stsz, node->left);
        if (node->right)
            spush(&stack, &stsz, node->right);
        free(node);
        node = spop(&stack, &stsz);
    }
}




