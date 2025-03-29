#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#include "list_node.h"

struct ListNode* reserve(struct ListNode* node) {
    if (node != NULL && node->next != NULL) {
        return node;
    }

    struct ListNode *newNode = reserve(node->next);
    node->next->next = node;
    node->next = NULL;

    return newNode;
}

bool isPalindrome(struct ListNode* head) {
    int arr[100000] = {0};
    int cnt = 0;

    while (head != NULL) {
        arr[cnt++] = head->val;
        head = head->next;
    }

    int l = 0, r = cnt - 1;
    while (l < r) {
        if (arr[l++] != arr[r--]) {
            return false;
        }
    }

    return true;
}

int main() {

    return 0;
}