#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void recursive(int* res, struct TreeNode* node, int* returnSize) {
    if (node == NULL) {
        return;
    }

    recursive(res, node->left, returnSize);

    res[(*returnSize)++] = node->val;

    recursive(res, node->right, returnSize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int *res = malloc(sizeof(int) * 100);

    *returnSize = 0;

    recursive(res, root, returnSize);

    return res;
}

int main() {
    struct TreeNode *root = NULL;
    int returnSize;
    inorderTraversal(root, &returnSize);

    return 0;
}
