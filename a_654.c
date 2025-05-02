#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* dfs(int * nums, int left, int right) {
    if (left > right) {
        return NULL;
    }

    int max = nums[left], idx = left;
    for (int i = left; i <= right; i++) {
        if (nums[i] > max) {
            idx = i;
            max = nums[i];
        }
    }

    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->val = max;
    node->left = dfs(nums, left, idx - 1);
    node->right  =dfs(nums, idx + 1, right);

    return node;
}

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize) {
    return dfs(nums, 0, numsSize - 1);
}

int main() {
    return 0;
}
