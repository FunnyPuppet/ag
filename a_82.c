#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#include "list_node.h"

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) {
        return head;
    }
    struct ListNode *P = malloc(sizeof(struct ListNode));
    P->next = head;

    struct ListNode *prev = P;
    struct ListNode *cur = head;
    struct ListNode *next = head->next;

    while (cur != NULL && next != NULL) {
        if (cur->val == next->val) {
            while (next != NULL && next->val == cur->val) {
                next = next->next;
            }
            prev->next = next;
            cur = next;
            if (next != NULL) {
                next = next->next;
            }
        } else {
            prev = cur;
            cur = next;
            next = next->next;
        }
    }

    return P->next;
}

int main() {
    return 0;
}