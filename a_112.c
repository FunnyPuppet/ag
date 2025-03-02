#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include "tree_node.h"

bool hasPathSum(struct TreeNode* root, int targetSum) {
    if (root == NULL) {
        return false;
    }
    if (root->val == targetSum && root->left == NULL && root->right == NULL) {
        return true;
    }

    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
}

int main() {
    int nums[] = {1,2};
    int len = sizeof(nums) / sizeof(nums[0]);

    struct TreeNode *root = arrayToTree(nums, len, 0);
    bool res = hasPathSum(root, 1);

    printf("%d\n", res);

    free(root);

    return 0;
}