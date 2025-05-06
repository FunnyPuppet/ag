#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int* buildArray(int* nums, int numsSize, int* returnSize) {
    int n = numsSize;
    int *ans = malloc(sizeof(int) * n);
    *returnSize = n;

    for (int i = 0; i < n; i++) {
        ans[i] = nums[nums[i]];
    }

    return ans;
}

int main() {
    int nums[] = {0, 2, 1, 5, 3, 4};
    int len = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int *res = buildArray(nums, len, &returnSize);
    free(res);

    return 0;
}