#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#include "list_node.h"

struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode *left = malloc(sizeof(struct ListNode));
    struct ListNode *right = malloc(sizeof(struct ListNode));

    struct ListNode *small = left;
    struct ListNode *large = right;
    while (head != NULL) {
        if (head->val < x) {
            small->next = head;
            small = small->next;
        } else {
            large->next = head;
            large = large->next;
        }
        head = head->next;
    }

    large->next = NULL;
    small->next = right->next;

    return left->next;
}

int main() {

    return 0;
}