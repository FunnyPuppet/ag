#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <tgmath.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *root = malloc(sizeof(struct ListNode));
    root->next = head;
    struct ListNode *f = root;
    struct ListNode *s = root;

    while (n >= 0) {
        f = f->next;
        n--;
    }

    while (f != NULL) {
        f = f->next;
        s = s->next;
    }

    s->next = s->next->next;

    return root->next;
}

int main() {
    struct ListNode* root = malloc(sizeof(struct ListNode));
    root->val = 1;
    root->next = NULL;

    removeNthFromEnd(root, 1);

    return 0;
}