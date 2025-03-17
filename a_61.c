#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#include "list_node.h"

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (k == 0 || head == NULL || head->next == NULL) {
        return head;
    }

    int n = 1;
    struct ListNode *tail = head;

    while (tail->next != NULL) {
        tail = tail->next;
        n++;
    }

    int cnt = k % n;

    if (cnt == 0) {
        return head;
    }
    tail->next = head;
    cnt = n - cnt - 1;
    while (cnt > 0) {
        head = head->next;
        cnt--;
    }

    struct ListNode *ans = head->next;
    head->next = NULL;

    return ans;
}

int main() {
    return 0;
}