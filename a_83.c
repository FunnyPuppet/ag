#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }

    struct ListNode* cur = head->next;
    struct ListNode* pre = head;

    while (cur != NULL) {
        if (pre->val == cur->val) {
            pre->next = cur->next;

        } else {
            pre = cur;
        }
        cur = cur->next;
    }

    return head;
}

int main() {
    struct ListNode* head = NULL;

    deleteDuplicates(head);

    return 0;
}

