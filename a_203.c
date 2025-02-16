#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <tgmath.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *root = malloc(sizeof(struct ListNode));
    root->next = head;
    struct ListNode *pre = root;
    struct ListNode *cur = root->next;

    while (cur != NULL) {
        if (cur->val == val) {
            pre->next = cur->next;
            cur = cur->next;
        } else {
            pre = cur;
            cur = cur->next;
        }
    }

    return root->next;
}

int main() {
    struct ListNode* root = malloc(sizeof(struct ListNode));
    root->val = 1;
    root->next = NULL;

    removeElements(root, 6);

    return 0;
}