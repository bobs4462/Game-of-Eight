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


