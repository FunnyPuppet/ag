#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#include "tree_node.h"

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL) {
        return NULL;
    }

    if (root == p || root == q) {
        return root;
    }

    struct TreeNode *l = lowestCommonAncestor(root->left, p, q);
    struct TreeNode *r = lowestCommonAncestor(root->right, p, q);

    if (l && r) {
        return root;
    }

    if (l) {
        return l;
    }

    return r;
}

int main() {

    return 0;
}