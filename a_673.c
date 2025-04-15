#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int findNumberOfLIS(int* nums, int numsSize) {
    int n = numsSize;
    int dp[n], cnt[n];
    memset(dp, 0, sizeof(dp));
    memset(cnt, 0, sizeof(cnt));
    int ans = 0, maxLen = 0;

    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        cnt[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    cnt[i] = cnt[j];
                } else if (dp[i] == dp[j] + 1) {
                    cnt[i] += cnt[j];
                }
            }
        }
        if (dp[i] > maxLen) {
            maxLen = dp[i];
            ans = cnt[i];
        } else if (dp[i] == maxLen) {
            ans += cnt[i];
        }
    }

    return ans;
}

int main() {
    int nums[] = {1,3,5,4,7};
    int len = sizeof(nums) / sizeof(nums[0]);
    int res = findNumberOfLIS(nums, len);
    printf("%d\n", res);
    return 0;
}