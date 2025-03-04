#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int numSquares(int n) {
    int dp[n + 1];
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        int cnt = INT_MAX;
        for (int j = 1; j * j <= i; j++) {
            cnt = fmin(cnt, dp[i - j * j]);
        }
        dp[i] = cnt + 1;
    }

    return dp[n];
}

int main() {
    int res = numSquares(32);

    printf("%d\n", res);

    return 0;
}