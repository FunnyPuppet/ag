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
        if (p[i - 1] == '*' && dp[0][i - 1] == 1) {
            dp[0][i] = 1;
        }
    }
    for (int i = 1; i <= m; i++) {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if ((s[i - 1] == p[j - 1] || p[j - 1] == '?') && dp[i - 1][j - 1] == 1) {
                dp[i][j] = 1;
            }
            if (p[j - 1] == '*' && (dp[i][j - 1] == 1 || dp[i - 1][j] == 1)) {
                dp[i][j] = 1;
            }
        }
    }

    return dp[m][n];
}

int main() {
    int res = isMatch("aab", "?a*b");
    printf("%d\n", res);

    return 0;
}