#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

#include "list_node.h"

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int minDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;

    int min = INT_MAX;
    if (root->left != NULL) {
        min = fmin(min, minDepth(root->left));
    }

    if (root->right != NULL) {
        min = fmin(min, minDepth(root->right));
    }

    return min + 1;
}

int main() {

    return 0;
}