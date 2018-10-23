struct state {
    unsigned int val;
    struct statetree * parent; 
    struct statetree * left; 
    struct statetree * right; 
};

typedef state * stptr;

int attach(stptr root, unsigned int newval) {
    stptr tracker = root;
    while (1) {
        if (newval == tracker->val)
            return 1;
        else if ((newval < tracker->val) && (tracker->left != NULL))
            tracker = tracker->left;
        else if ((newval < tracker->val) && (tracker->left == NULL)) {
            tracker->left = leaf(tracker, newval); 
            return 0;
        }
        else if ((newval > tracker->val) && (tracker->right != NULL))
            tracker = tracker->right;
        else { 
            tracker->right = leaf(tracker, newval); 
            return 0;
        }
    }
}


stptr leaf(stptr parent, unsigned int newval) 
{
    stptr temp = malloc(sizeof(struct state));
    if(!temp)
        exit(0);

    temp->val = newval;
    temp->parent = parent;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}

stptr ll(stptr root) //Linked list transform
{

    stptr tracker = root, scout = NULL; 
    while (tracker->left) 
        tracker = tracker->left;
    if (tracker->right == NULL)
        tracker->right = tracker->parent;
    else
    while (tracker->right) ;
}

