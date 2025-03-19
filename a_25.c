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

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode *P = malloc(sizeof(struct ListNode));
    P->next = head;
    struct ListNode *last = P;
    struct ListNode *root = head;
    struct ListNode *tail = head;

    int cnt = 1;
    while (tail != NULL) {
        if (cnt == k) {
            struct ListNode *tmp = root;
            struct ListNode *q = tail->next;
            tail->next = NULL;
            struct ListNode *node = reverseList(root);
            last->next = node;
            last = tmp;
            last->next = q;
            root = q;
            tail = q;
            cnt = 1;
        } else {
            tail = tail->next;
            cnt++;
        }
    }

    return P->next;
}

int main() {
    return 0;
}