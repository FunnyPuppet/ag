#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


struct TreeNode* dfs(int level, int* idx, int n, char* s){
    int x = 0, h = 0;
    int i = *idx;
    for(; i < n && s[i] == '-'; i++) h++;
    if(h < level) return NULL;

    for(; i < n && isdigit(s[i]); i++) {
        x = x * 10 + (s[i] - '0');
    }

    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = x;
    *idx = i;
    node->left = dfs(level + 1, idx, n, s);
    node->right = dfs(level + 1, idx, n, s);
    return node;
};

struct TreeNode* recoverFromPreorder(char* traversal) {
    int n = strlen(traversal);
    int idx = 0;

    return dfs(0, &idx, n, traversal);
}

int main() {
    struct TreeNode* res = recoverFromPreorder("1-2--3--4-5--6--7");
    free(res);
    return 0;
}
