#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#include "list_node.h"

struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode *node = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;

    return node;
}

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (left == right) {
        return head;
    }

    struct ListNode *P = malloc(sizeof(struct ListNode));
    P->next = head;
    struct ListNode *last = NULL;
    struct ListNode *L = NULL, *R = NULL;

    struct ListNode *cur = P;
    int idx = 0;

    while (cur != NULL) {
        if (idx == left - 1) {
            last = cur;
            L = cur->next;
        }
        if (idx == right) {
            R = cur;
            break;
        }

        cur = cur->next;
        idx++;
    }

    struct ListNode *next = R->next;
    R->next = NULL;

    struct ListNode *rl = reverseList(L);
    last->next = rl;
    L->next = next;

    return P->next;
}

int main() {
    return 0;
}