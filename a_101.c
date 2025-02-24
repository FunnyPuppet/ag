#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "list_node.h"

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool _isSymmetric(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) {
        return true;
    }

    if (p == NULL || q == NULL) {
        return false;
    }

    if (p->val != q->val) {
        return false;
    }

    return _isSymmetric(p->left, p->right) && _isSymmetric(q->left, q->right);
}

bool isSymmetric(struct TreeNode* root) {
    return _isSymmetric(root->left, root->right);
}

int main() {

    return 0;
}