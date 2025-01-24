#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHILDREN_SIZE 26

typedef struct TrieNode TrieNode;

struct TrieNode {
    TrieNode *children[CHILDREN_SIZE];
    bool isEnd;
};

TrieNode* createTrieNode() {
    TrieNode *node = malloc(sizeof(TrieNode));

    node->isEnd = false;
    for (int i = 0; i < CHILDREN_SIZE; i++) {
        node->children[i] = NULL;
    }

    return node;
}

void insertNode(TrieNode* root, char* str) {
    int len = strlen(str);

    if (len == 0) {
        return;
    }

    TrieNode *cur = root;
    for (int i = 0; i < len; i++) {
        int index = str[i] - 'a';
        if (cur->children[index] == NULL) {
            TrieNode *newNode = createTrieNode();
            cur->children[index] = newNode;
        }
        cur = cur->children[index];
    }

    cur->isEnd = true;
}

void freeTrie(TrieNode* node) {
    if (node == NULL) {
        return;
    }

    for (int i = 0; i < CHILDREN_SIZE; i++) {
        if (node->children[i] != NULL) {
            freeTrie(node->children[i]);
        }
    }

    free(node);
}

char* longestCommonPrefix(char** strs, int strsSize) {
    TrieNode *root = createTrieNode();

    for (int i = 0; i < strsSize; i++) {
        if (strlen(strs[i]) == 0) {
            return "";
        }

        insertNode(root, strs[i]);
    }

    TrieNode *cur = root;
    char *ans = malloc(sizeof(char) * 201);
    int al = 0;
    while (1) {
        int count = 0;
        int index = -1;
        for (int i = 0; i < CHILDREN_SIZE; i++) {
            if (cur->children[i] != NULL) {
                count++;
                index = i;
            }
        }

        if (count != 1 || cur->isEnd == true) {
            break;
        }

        ans[al++] = index + 'a';
        cur = cur->children[index];
    }
    ans[al] = '\0';
    freeTrie(root);

    return ans;
}

int main() {
    int *strs[] = {"flower", "flow", "flight"};

    int strSize = sizeof(strs) / sizeof(strs[0]);

    char *res = longestCommonPrefix(strs, strSize);

    printf("%s\n", res);

    free(res);

    return 0;
}

