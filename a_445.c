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

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p = reverseList(l1);
    struct ListNode *q = reverseList(l2);
    struct ListNode *head = NULL;
    struct ListNode *cur = NULL;

    int add = 0;
    while (p != NULL || q != NULL) {
        int sum = add;
        if (p != NULL) {
            sum += p->val;
            p = p->next;
        }
        if (q != NULL) {
            sum += q->val;
            q = q->next;
        }
        struct ListNode *node = malloc(sizeof(struct ListNode));
        node->val = sum % 10;
        node->next = NULL;
        if (cur == NULL) {
            head = node;
            cur = node;
        } else {
            cur->next = node;
            cur = cur->next;
        }
        add = sum / 10;
    }
    if (add > 0) {
        struct ListNode *node = malloc(sizeof(struct ListNode));
        node->val = add;
        node->next = NULL;
        cur->next = node;
        cur = cur->next;
    }

    return reverseList(head);
}

int main() {

    return 0;
}