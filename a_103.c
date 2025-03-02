#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include "tree_node.h"

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    int **ans = malloc(sizeof(int*) * 2000);
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * 2000);

    if (root == NULL) {
        return ans;
    }

    struct TreeNode **nodeArr = malloc(sizeof(struct TreeNode*) * 2000);
    nodeArr[0] = root;
    bool flag = true;
    int cnt = 1;
    while (cnt > 0) {
        struct TreeNode **tmp = malloc(sizeof(struct TreeNode*) * cnt);
        int *arr = malloc(sizeof(int) * cnt);

        for (int i = 0; i < cnt; i++) {
            tmp[i] = nodeArr[i];
            if (flag) {
                arr[i] = nodeArr[i]->val;
            } else {
                arr[cnt - i -1] = nodeArr[i]->val;
            }
        }

        int t = 0;

        for (int i = 0; i < cnt; i++) {
            struct TreeNode *node = tmp[i];
            if (node->left != NULL) nodeArr[t++] = node->left;
            if (node->right != NULL) nodeArr[t++] = node->right;
        }

        ans[*returnSize] = arr;
        (*returnColumnSizes)[*returnSize] = cnt;
        (*returnSize)++;
        cnt = t;
        flag = !flag;
        free(tmp);
    }
    free(nodeArr);

    return ans;
}
int main() {
    int nums[] = {1,2,3,4,INT_MAX,INT_MAX,5};
    int len = sizeof(nums) / sizeof(nums[0]);

    struct TreeNode *root = arrayToTree(nums, len, 0);
    int returnSize;
    int *returnColumnSizes;
    int **res = levelOrder(root, &returnSize, &returnColumnSizes);
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