#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int nthUglyNumber(int n) {
    int dp[n + 1];
    dp[1] = 1;

    int p1 = 1, p2 = 1, p3 = 1;
    for (int i = 2; i <= n; i++) {
        int num1 = dp[p1] * 2, num2 = dp[p2] * 3, num3 = dp[p3] * 5;
        int num = fmin(fmin(num1, num2), num3);
        dp[i] = num;
        if (num == num1) {
            p1++;
        }
        if (num == num2) {
            p2++;
        }
        if (num == num3) {
            p3++;
        }
    }

    return dp[n];
}

int main() {
    int res = nthUglyNumber(10);
    printf("%d\n", res);

    return 0;
}