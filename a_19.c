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
    int count = 0;

    struct ListNode* cur = head;
    while (cur != NULL) {
        count++;
        cur = cur->next;
    }

    if (count == 1) {
        return NULL;
    }

    if (count == n) {
        return head->next;
    }

    struct ListNode* ans = head;
    struct ListNode* pre = head;
    cur = head->next;

    for (int i = 0; i < count; i++) {
        if (i == count - n) {
            pre->next = cur->next;
            break;
        }
        pre = cur;
        cur = cur->next;
    }

    return ans;
}

int main() {
    struct ListNode* root = malloc(sizeof(struct ListNode));
    root->val = 1;
    root->next = NULL;

    removeNthFromEnd(root, 1);

    return 0;
}