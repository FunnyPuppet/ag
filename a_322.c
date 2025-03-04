#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int coinChange(int* coins, int coinsSize, int amount) {
    int dp[amount + 1];
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        dp[i] = amount + 1;
    }

    for (int i = 1; i <= amount; i++) {
        int cnt = INT_MAX;
        for (int j = 0; j < coinsSize; j++) {
            if (i - coins[j] >= 0) {
                cnt = fmin(cnt, dp[i - coins[j]]);
            }
        }
        if (cnt != INT_MAX && cnt != -1) {
            dp[i] = cnt + 1;
        }
    }

    return dp[amount] > amount ? -1 : dp[amount];
}

int main() {
    int nums[] = {186,419,83,408};
    int len = sizeof(nums) / sizeof(nums[0]);
    int res = coinChange(nums, len, 6249);

    printf("%d\n", res);

    return 0;
}