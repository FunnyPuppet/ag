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

int _maxDepth(struct TreeNode* root, int depth) {
    if (root == NULL) {
        return depth;
    }

    return fmax(_maxDepth(root->left, depth + 1), _maxDepth(root->right, depth + 1));
}

int maxDepth(struct TreeNode* root) {
    return _maxDepth(root, 0);
}

int main() {

    return 0;
}