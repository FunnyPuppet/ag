#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#include "tree_node.h"

void flatten(struct TreeNode* root) {
    struct TreeNode* curr = root;
    while (curr != NULL) {
        if (curr->left != NULL) {
            struct TreeNode* next = curr->left;
            struct TreeNode* predecessor = next;
            while (predecessor->right != NULL) {
                predecessor = predecessor->right;
            }
            predecessor->right = curr->right;
            curr->left = NULL;
            curr->right = next;
        }
        curr = curr->right;
    }
}

int main() {

    return 0;
}