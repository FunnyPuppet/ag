#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

bool canPartition(int* nums, int numsSize) {
    int n = numsSize;
    if (n < 2) {
        return false;
    }
    int sum = 0, max = INT_MIN;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        max = fmax(max, nums[i]);
    }
    if (sum & 1) {
        return false;
    }
    int target = sum >> 1;
    if (max > target) {
        return false;
    }

    bool dp[n][target + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }
    dp[0][nums[0]] = true;
    for (int i = 1; i < n; i++) {
        int num = nums[i];
        for (int j = 1; j <= target; j++) {
            if (j >= num) {
                dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n - 1][target];
}

int main() {
    int nums[] = {1, 5, 5, 11};
    int len = sizeof(nums) / sizeof(nums[0]);
    bool res = canPartition(nums, len);
    printf("%d\n", res);

    return 0;
}