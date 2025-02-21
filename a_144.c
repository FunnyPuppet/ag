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

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int *ans = malloc(sizeof(int) * 100);

    struct TreeNode *stack[100];
    stack[0] = root;
    int top = 0;

    while (top >= 0) {
        struct TreeNode *node = stack[top--];
        if (node != NULL) {
            ans[*returnSize] = node->val;
            (*returnSize)++;

            if (node->right != NULL) {
                stack[++top] = node->right;
            }

            if (node->left != NULL) {
                stack[++top] = node->left;
            }
        }
    }

    return ans;
}

int main() {
    int returnSize;
    struct TreeNode* root = NULL;
    int *res = preorderTraversal(root, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", res[i]);
    }

    free(res);

    return 0;
}