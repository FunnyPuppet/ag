#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <tgmath.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteMiddle(struct ListNode* head) {
    struct ListNode *root = malloc(sizeof(struct ListNode));
    root->next = head;
    struct ListNode *f = root->next;
    struct ListNode *s = root;

    while (f != NULL && f->next != NULL) {
        f = f->next->next;
        s = s->next;
    }

    s->next = s->next->next;

    return root->next;
}

int main() {
    struct ListNode* root = malloc(sizeof(struct ListNode));
    root->val = 1;
    root->next = NULL;

    deleteMiddle(root);

    return 0;
}