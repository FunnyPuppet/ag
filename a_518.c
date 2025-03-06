#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int change(int amount, int* coins, int coinsSize) {
    unsigned long long dp[amount + 1];
    dp[0] = 1;

    for (int i = 1; i <= amount; i++) {
        dp[i] = 0;
    }

    for (int i = 0; i < coinsSize; i++) {
        for (int j = coins[i]; j <= amount; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    return dp[amount];
}

int main() {
    int nums[] = {1,2,5};
    int len = sizeof(nums) / sizeof(nums[0]);
    int res = change(5, nums, len);

    printf("%d\n", res);

    return 0;
}