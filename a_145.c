#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void addNode(struct TreeNode* node, int *ans, int* returnSize) {
    if (node != NULL) {
        ans[*returnSize] = node->val;
        (*returnSize)++;
        addNode(node->left, ans, returnSize);
        addNode(node->right, ans, returnSize);
    }
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ans = malloc(sizeof(int) * 100);

    *returnSize = 0;
    addNode(root, ans, returnSize);

    return ans;
}

int main() {
    int returnSize;
    struct TreeNode* root = NULL;
    int *res = postorderTraversal(root, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", res[i]);
    }

    free(res);

    return 0;
}