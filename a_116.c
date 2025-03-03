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

void bfs(struct Node **nodes, int size) {
    if (size > 0) {
        struct Node **arr = malloc(sizeof(struct Node*) * (size * 2));
        int len = 0;
        for (int i = 0; i < size; i++) {
            struct Node *node = nodes[i];
            if (i != size - 1) {
                node->next = nodes[i + 1];
            }

            if (node->left != NULL) arr[len++] = node->left;
            if (node->right != NULL) arr[len++] = node->right;
        }
        free(nodes);
        bfs(arr, len);
    } else {
        free(nodes);
    }
}

struct Node* connect(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }

    struct Node **nodes = malloc(sizeof(struct Node*) * 1);
    nodes[0] = root;

    bfs(nodes, 1);

    return root;
}

int main() {

    return 0;
}