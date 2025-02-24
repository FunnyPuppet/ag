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

int height(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    return fmax(height(root->left), height(root->right)) + 1;
}

bool isBalanced(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }

    return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

int main() {

    return 0;
}