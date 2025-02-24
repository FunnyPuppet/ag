#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "list_node.h"

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool compare(struct TreeNode** left, struct TreeNode** right, int ll, int rl) {
    if (ll == 0 || rl == 0) return true;
    struct TreeNode** l = malloc(sizeof(struct TreeNode*) * (ll * 2));
    struct TreeNode** r = malloc(sizeof(struct TreeNode*) * (rl * 2));

    int ps = 0, qs = 0;

    for (int i = 0, j = 0; i < ll && j < rl; i++, j++) {
        struct TreeNode *p = left[i], *q = right[j];
        if (p == NULL && q == NULL)
            continue;
        if (p == NULL || q == NULL) {
            free(l);
            free(r);
            return false;
        }

        if (p->val != q->val) {
            free(l);
            free(r);
            return false;
        }

        l[ps++] = p->left, l[ps++] = p->right;
        r[qs++] = q->right, r[qs++] = q->left;
    }

    return compare(l, r, ps, qs);
}

bool isSymmetric(struct TreeNode* root) {
    if (root->left == NULL && root->right == NULL)
        return true;

    struct TreeNode** l = malloc(sizeof(struct TreeNode*));
    struct TreeNode** r = malloc(sizeof(struct TreeNode*));

    l[0] = root->left;
    r[0] = root->right;

    return compare(l, r, 1, 1);
}

int main() {

    return 0;
}