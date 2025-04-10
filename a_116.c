#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};

void dfs(struct Node *node) {
    if (node != NULL) {
        if (node->left != NULL) {
            node->left->next = node->right;
        }

        if (node->next != NULL && node->right != NULL) {
            node->right->next = node->next->left;
        }

        dfs(node->left);
        dfs(node->right);
    }
}

struct Node* connect(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }

    dfs(root);

    return root;
}

int main() {
    struct Node *root = malloc(sizeof(struct Node));
    struct Node *node1 = malloc(sizeof(struct Node));
    struct Node *node2 = malloc(sizeof(struct Node));

    root->next = NULL;
    root->left = node1;
    root->right = node2;

    node1->next = NULL;
    node1->left = NULL;
    node1->right = NULL;

    node2->next = NULL;
    node2->left = NULL;
    node2->right = NULL;

    connect(root);

    free(node2);
    free(node1);
    free(root);

    return 0;
}