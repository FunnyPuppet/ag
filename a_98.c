#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#include "tree_node.h"

bool dfs(struct TreeNode* root, long long min, long long max) {
    if (root == NULL) {
        return true;
    }

    if (root->val <= min || root->val >= max) {
        return false;
    }

    return dfs(root->left, min, root->val) && dfs(root->right, root->val, max);
}

bool isValidBST(struct TreeNode* root) {
    return dfs(root, LONG_MIN, LONG_MAX);
}

int main() {

    return 0;
}