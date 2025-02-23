#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "list_node.h"

void merge(struct ListNode **arr, int left, int mid, int right) {
    int p = left, q = mid + 1, len = right - left + 1;
    int pos = 0;
    struct ListNode **temp = malloc(sizeof(struct ListNode*) * len);

    while (p <= mid && q <= right) {
        if (arr[p]->val < arr[q]->val) {
            temp[pos++] = arr[p++];
        } else {
            temp[pos++] = arr[q++];
        }
    }

    while (p <= mid) {
        temp[pos++] = arr[p++];
    }

    while (q <= right) {
        temp[pos++] = arr[q++];
    }

    pos = 0;
    while (pos < len) {
       arr[left++] = temp[pos++];
    }

    free(temp);
}

void mergeSort(struct ListNode **arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

struct ListNode* sortList(struct ListNode* head) {
    if (head == NULL) return head;
    int cnt = 0;

    struct ListNode **arr = malloc(sizeof(struct ListNode*) * 500000);
    struct ListNode* cur = head;
    while (cur != NULL) {
        arr[cnt++] = cur;
        cur = cur->next;
    }

    mergeSort(arr, 0, cnt - 1);

    struct ListNode* P = malloc(sizeof(struct ListNode));
    cur = P;
    for (int i = 0; i < cnt; i++) {
        arr[i]->next = NULL;
        cur->next = arr[i];
        cur = cur->next;
    }

    free(arr);

    return P->next;
}

int main() {
    int nums[] = {4, 2, 1, 3};
    int len = sizeof(nums) / sizeof(nums[0]);
    struct ListNode* root = arrayToLinkedList(nums, len);

    struct ListNode* res = sortList(root);

    printList(res);

    return 0;
}