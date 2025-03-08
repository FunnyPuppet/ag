#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>


bool isMatch(char* s, char* p) {
    int m = strlen(s), n = strlen(p);
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        if (p[i - 1] == '*') {
            dp[0][i] = dp[0][i - 2];
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                dp[i][j] = dp[i - 1][j - 1];
            }
            if (p[j - 1] == '*') {
                dp[i][j] |= dp[i][j - 2];
                if (s[i - 1] == p[j - 2] || p[j - 2] == '.') {
                    dp[i][j] |= dp[i][j - 1] | dp[i - 1][j];
                }
            }
        }
    }

    return dp[m][n];
}

int main() {
    bool res = isMatch("aaa", "ab*ac*a");
    printf("%d\n", res);

    return 0;
}