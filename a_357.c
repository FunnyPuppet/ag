#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int countNumbersWithUniqueDigits(int n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return 10;
    }
    int dp[n + 1];
    for (int i = 0; i < n; i++) {
        dp[i] = 0;
    }
    dp[0] = 1;
    dp[1] = 10;

    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 1] - dp[i - 2]) * (10 - i + 1) + dp[i - 1];
    }

    return dp[n];
}

int main() {
    int res = countNumbersWithUniqueDigits(5);
    printf("%d\n", res);

    return 0;
}