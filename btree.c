unsigned int nc; //state average and node count

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

sptr rebalance(stptr,

int reattach(stptr root, stptr orphan)
{
    stptr tracker = root;
    while (1) {
        if ((orphan->val < tracker->val) && (tracker->left != NULL))
            tracker = tracker->left;
        else if ((orphan->val < tracker->val) && (tracker->left == NULL)) {
            tracker->left = orphan; 
            orphan->parent = tracker;
            return 0;
        }
        else if ((orphan->val > tracker->val) && (tracker->right != NULL))
            tracker = tracker->right;
        else { 
            tracker->right = orphan; 
            orphan->parent = tracker;
            return 0;
        }
    }
}

stptr rootseek(stptr root, double savg)
{
    stptr tracker = root;

    while (1) {
        if ((tracker->val > savg) && (tracker->left != NULL))
            tracker = tracker->left;
        else if ((tracker->val > savg) && (tracker->left == NULL))
            return tracker;
        else if ((tracker->val < savg) && (tracker->right == NULL))
            return tracker;
        else if ((tracker->val < savg) && (tracker->right != NULL))
            tracker = tracker->left;
        else
            return tracker;
    }
}

double *average(stptr oldroot, stptr newroot)
{
    unsigned int counter[2] = {0};
    long unsigned int acc[2] = {0};
    double *result = malloc(sizeof(double) * 2);
    int opsz = 1;
    stptr *OPEN = malloc(sizeof(stptr));
    OPEN = oldroot;
    while(OPEN) {
        if (OPEN->left != NULL) {
            OPEN = realloc(OPEN, sizeof(stptr) * (++opsz));
            OPEN[opsz - 1] = OPEN->left;
        }
        if (OPEN->right != NULL) {
            OPEN = realloc(OPEN, sizeof(stptr) * (++opsz));
            OPEN[opsz - 1] = OPEN->right;
        }
        if (OPEN->val < newroot->val) {
            acc[0] += OPEN->val;
            ++counter[0];
        }
        else 
            acc[1] += OPEN->val;
        if (1 < opsz)
            for (int i = 0; i < opsz; ++i)
                OPEN[i] = OPEN[i + 1];
        OPEN = realloc(OPEN, sizeof(stptr) * (--opsz));
    }
    result[0] = acc[0] / double(counter[0]);
    result[1] = acc[1] / double(counter[1]);
    return result;
}



