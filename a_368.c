#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int* largestDivisibleSubset(int* nums, int numsSize, int* returnSize) {
    int n = numsSize;
    qsort(nums, n, sizeof(int), cmp);

    int dp[n];
    memset(dp, 0, sizeof(dp));
    int maxLen = 1, maxVal = nums[0];

    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[i] % nums[j] == 0) {
                dp[i] = fmax(dp[i], dp[j] + 1);
            }
        }
        if (dp[i] > maxLen) {
            maxLen = dp[i];
            maxVal = nums[i];
        }
    }

    int *ans = malloc(sizeof(int) * maxLen);
    *returnSize = 0;
    int idx = n - 1;
    while (maxLen > 0) {
        for (; idx >= 0; idx--) {
            if (dp[idx] == maxLen && maxVal % nums[idx] == 0) {
                maxVal = nums[idx];
                break;
            }
        }
        ans[(*returnSize)++] = nums[idx];
        maxLen--;
    }

    return ans;
}

int main() {
    int nums[] = {3, 4, 16, 8};
    int len = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int* res = largestDivisibleSubset(nums, len, &returnSize);

    return 0;
}