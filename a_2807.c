#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#include "list_node.h"

int gcd(int a, int b) {
    while (b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

struct ListNode* insertGreatestCommonDivisors(struct ListNode* head) {
    struct ListNode * node = head;
    while (node->next) {
        struct ListNode *newNode = malloc(sizeof(struct ListNode));
        newNode->val = gcd(node->val, node->next->val);
        newNode->next = node->next;
        node->next = newNode;
        node = newNode->next;
    }
    return head;
}

int main() {

    return 0;
}