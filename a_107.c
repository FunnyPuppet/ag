#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include "tree_node.h"

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    int **ans = malloc(sizeof(int*) * 2000);
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * 2000);

    if (root == NULL) {
        return ans;
    }

    struct TreeNode **nodeArr = malloc(sizeof(struct TreeNode*) * 2000);
    nodeArr[0] = root;
    int cnt = 1;
    while (cnt > 0) {
        struct TreeNode **tmp = malloc(sizeof(struct TreeNode*) * cnt);
        int *arr = malloc(sizeof(int) * cnt);
        for (int i = 0; i < cnt; i++) {
            tmp[i] = nodeArr[i];
        }

        int t = 0;
        for (int i = 0; i < cnt; i++) {
            struct TreeNode *node = tmp[i];
            arr[i] = node->val;
            if (node->left != NULL) nodeArr[t++] = node->left;
            if (node->right != NULL) nodeArr[t++] = node->right;
        }
        ans[*returnSize] = arr;
        (*returnColumnSizes)[*returnSize] = cnt;
        (*returnSize)++;
        cnt = t;
        free(tmp);
    }
    free(nodeArr);

    int l = 0, r = *returnSize - 1;
    while (l < r) {
        int *tmp = ans[l];
        ans[l] = ans[r];
        ans[r] = tmp;
        int t = (*returnColumnSizes)[l];
        (*returnColumnSizes)[l] = (*returnColumnSizes)[r];
        (*returnColumnSizes)[r] = t;
        l++;
        r--;
    }

    return ans;
}
int main() {
    int nums[] = {3,9,20,INT_MAX,INT_MAX,15,7};
    int len = sizeof(nums) / sizeof(nums[0]);

    struct TreeNode *root = arrayToTree(nums, len, 0);
    int returnSize;
    int *returnColumnSizes;
    int **res = levelOrderBottom(root, &returnSize, &returnColumnSizes);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", res[i][j]);
        }
        free(res[i]);
        printf("\n");
    }
    printf("\n");

    free(res);
    free(root);

    return 0;
}