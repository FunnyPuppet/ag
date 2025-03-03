#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include "tree_node.h"

void dfs(struct TreeNode* node) {
    if (node != NULL) {
        struct TreeNode *tmp = node->left;

        node->left = node->right;
        node->right = tmp;

        dfs(node->left);
        dfs(node->right);
    }
}

struct TreeNode* invertTree(struct TreeNode* root) {
    dfs(root);

    return root;
}

int main() {

    return 0;
}