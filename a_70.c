#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int climbStairs(int n) {
    if (n == 1) {
        return 1;
    }
    int dp[n];

    dp[0] = 1;
    dp[1] = 2;

    for (int i = 2; i < n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n - 1];
}

int main() {
    int k = climbStairs(5);

    printf("%d", k);

    return 0;
}
