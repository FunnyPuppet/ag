#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int minDistance(char* word1, char* word2) {
    int m = strlen(word1);
    int n = strlen(word2);
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= m; i++) {
        char c1 = word1[i - 1];
        for (int j = 1; j <= n; j++) {
            char c2 = word2[j - 1];
            if (c1 == c2) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = fmax(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int lcs = dp[m][n];
    return m - lcs + n - lcs;
}

int main() {

    return 0;
}