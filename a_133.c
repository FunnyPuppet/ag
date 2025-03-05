#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

struct Node *dfs(struct Node** visited, struct Node* node) {
    if (node == NULL) {
        return NULL;
    }

    if (visited[node->val] != NULL) {
        return visited[node->val];
    }

    struct Node *cloneNode = malloc(sizeof(struct Node));
    cloneNode->val = node->val;
    cloneNode->numNeighbors = node->numNeighbors;
    cloneNode->neighbors = malloc(sizeof(struct Node*) * node->numNeighbors);

    visited[node->val] = cloneNode;
    for (int i = 0; i < node->numNeighbors; i++) {
        cloneNode->neighbors[i] = dfs(visited, node->neighbors[i]);
    }

    return cloneNode;
}

struct Node *cloneGraph(struct Node *s) {
    struct Node **visited = malloc(sizeof(struct Node*) * 101);
    memset(visited, 0, sizeof(struct Node*) * 101);
    return dfs(visited, s);
}

int main() {

    return 0;
}