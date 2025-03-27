#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

long long minimumCost(char* s) {
    int n = strlen(s);
    long long dp[n + 1][2];
    memset(dp, 0, sizeof(dp));

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1') {
            dp[i][0] = dp[i + 1][1] + n - i;
            dp[i][1] = dp[i + 1][1];
        } else {
            dp[i][0] = dp[i + 1][0];
            dp[i][1] = dp[i + 1][0] + n - i;
        }
    }

    long long pre[2] = {0};
    long long ans = LONG_MAX;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            pre[0] = pre[1] + i + 1;
        } else {
            pre[1] = pre[0] + i + 1;
        }

        ans = fmin(ans, fmin(pre[0] + dp[i + 1][0], pre[1] + dp[i + 1][1]));
    }

    return ans;
}

int main() {
    long long res = minimumCost("101011");
    printf("%lld", res);

    return 0;
}