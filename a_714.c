#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int maxProfit(int* prices, int pricesSize, int fee) {
    int n = pricesSize;

    int dp[n][2];
    memset(dp, 0, sizeof(int));
    dp[0][0] = 0, dp[0][1] = -prices[0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = fmax(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
        dp[i][1] = fmax(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }

    return dp[n - 1][0];
}

int main() {
    int nums[] = {1, 3, 2, 8, 4, 9};
    int len = sizeof(nums) / sizeof(nums[0]);
    int res = maxProfit(nums, len, 2);
    printf("%d\n", res);
    return 0;
}