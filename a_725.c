#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#include "list_node.h"

struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize) {
    int cnt = 0;
    struct ListNode *cur = head;

    while (cur != NULL) {
        cnt++;
        cur = cur->next;
    }
    int m = cnt / k, n = cnt % k;

    struct ListNode** ans = malloc(sizeof(struct ListNode*) * k);
    *returnSize = 0;
    struct ListNode *l = head;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m - (i < n ? 0 : 1); j++) {
            if (head != NULL) {
                head = head->next;
            }
        }
        ans[*returnSize] = l;
        (*returnSize)++;
        if (head != NULL) {
            struct ListNode *tmp = head;
            head = head->next;
            tmp->next = NULL;
        }
        l = head;
    }

    return ans;
}

int main() {

    return 0;
}