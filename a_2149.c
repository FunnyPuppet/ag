#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int* rearrangeArray(int* nums, int numsSize, int* returnSize) {
    int n = numsSize;

    int pi = 0, ni = 1;

    int *ans = malloc(sizeof(int) * n);
    *returnSize = n;
    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) {
            ans[pi] = nums[i];
            pi += 2;
        }
        if (nums[i] < 0) {
            ans[ni] = nums[i];
            ni += 2;
        }
    }

    return ans;
}

int main() {
    int arr[] = {3, 1, -2, -5, 2, -4};
    int len = sizeof(arr) / sizeof(arr[0]);
    int returnSize;
    int *res = rearrangeArray(arr, len, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");

    free(res);

    return 0;
}