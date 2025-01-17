#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int fib(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int res = fib(4);

    printf("%d ", res);

    return 0;
}
