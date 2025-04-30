#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int* pivotArray(int* nums, int numsSize, int pivot, int* returnSize) {
    int n = numsSize;

    int *ans = malloc(sizeof(int) * n);
    *returnSize = n;
    int idx = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] < pivot) {
            ans[idx++] = nums[i];
        }
        if (nums[i] == pivot) {
            cnt++;
        }
    }

    for (int i = 0; i < cnt; i++) {
        ans[idx++] = pivot;
    }

    for (int i = 0; i < n; i++) {
        if (nums[i] > pivot) {
            ans[idx++] = nums[i];
        }
    }

    return ans;
}

int main() {
    int arr[] = {};
    int len = sizeof(arr) / sizeof(arr[0]);
    int returnSize;
    int* res = pivotArray(arr, len, 10, &returnSize);
    free(res);
    return 0;
}
