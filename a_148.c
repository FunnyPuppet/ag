#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "list_node.h"

int compareInt(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

struct ListNode* sortList(struct ListNode* head) {
    if (head == NULL) return head;
    int cnt = 0;

    int arr[500000];
    struct ListNode* cur = head;
    while (cur != NULL) {
        arr[cnt++] = cur->val;
        cur = cur->next;
    }

    qsort(arr, cnt, sizeof(int), compareInt);

    cur = head;
    for (int i = 0; i < cnt; i++) {
        cur->val = arr[i];
        cur = cur->next;
    }

    return head;
}

int main() {
    int nums[] = {4, 2, 1, 3};
    int len = sizeof(nums) / sizeof(nums[0]);
    struct ListNode* root = arrayToLinkedList(nums, len);

    struct ListNode* res = sortList(root);

    printList(res);

    return 0;
}