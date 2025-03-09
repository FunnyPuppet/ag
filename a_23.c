#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#include "list_node.h"

struct ListNode* merge(struct ListNode* l, struct ListNode* r) {
    struct ListNode *P = malloc(sizeof(struct ListNode));
    P->next = NULL;
    struct ListNode *cur = P;
    while (l != NULL && r != NULL) {
        if (l->val < r->val) {
            cur->next = l;
            l = l->next;
        } else {
            cur->next = r;
            r = r->next;
        }
        cur = cur->next;
    }

    if (l != NULL) {
        cur->next = l;
    }

    if (r != NULL) {
        cur->next = r;
    }

    return P->next;
}

struct ListNode* mergeSort(struct ListNode** lists, int left, int right) {
    if (left == right) {
        return lists[left];
    }
    if (left < right) {
        int mid = left + ((right - left) >> 1);

        struct ListNode* l = mergeSort(lists, left, mid);
        struct ListNode* r = mergeSort(lists, mid + 1, right);

        return merge(l ,r);
    }

    return NULL;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    return mergeSort(lists, 0, listsSize - 1);
}

int main() {
    int len  = 5;
    struct ListNode** lists = malloc(sizeof(struct ListNode*) * len);

    for (int i = 0; i < len; i++) {
        lists[i] = NULL;
    }
    mergeKLists(lists, len);

    free(lists);
    return 0;
}