#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include "list_node.h"

struct ListNode* insertionSortList(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }

    struct ListNode *P = malloc(sizeof(struct ListNode));
    P->val = -5001;
    P->next = head;
    struct ListNode *last = head;
    struct ListNode *cur = head->next;

    while (cur != NULL) {
        if (last->val <= cur->val) {
            last = last->next;
        } else {
            struct ListNode *tmp = P;
            while (tmp->next->val <= cur->val) {
                tmp = tmp->next;
            }
            last->next = cur->next;
            cur->next = tmp->next;
            tmp->next = cur;
        }
        cur = last->next;
    }

    return P->next;
}

int main() {
    struct ListNode *root = malloc(sizeof(struct ListNode));
    struct ListNode *node1 = malloc(sizeof(struct ListNode));
    struct ListNode *node2 = malloc(sizeof(struct ListNode));
    struct ListNode *node3 = malloc(sizeof(struct ListNode));

    root->val = 4;
    root->next = node1;
    node1->val = 1;
    node1->next = node2;
    node2->val = 3;
    node2->next = node3;
    node3->val = 2;
    node3->next = NULL;

    struct ListNode *res = insertionSortList(root);

    return 0;
}