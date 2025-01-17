#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int minCostClimbingStairs(int* cost, int costSize) {
    int dp[costSize + 1];
    dp[0] = dp[1] = 0;
    for (int i = 2; i <= costSize; i++) {
        int m = dp[i - 1] + cost[i - 1];
        int n = dp[i - 2] + cost[i - 2];

        dp[i] = m < n ? m : n;
    }

    return dp[costSize];
}

int main() {
    int nums[] = {1,100,1,1,1,100,1,1,100,1};
    int len = sizeof(nums) / sizeof(nums[0]);

    int res = minCostClimbingStairs(nums, len);

    printf("%d ", res);

    return 0;
}
