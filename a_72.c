#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include "list_node.h"

int minDistance(char* word1, char* word2) {
    int m = strlen(word1), n = strlen(word2);

    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        dp[0][i] = i;
    }

    for (int i = 1; i <= m; i++) {
        dp[i][0] = i;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = fmin(fmin(dp[i - 1][j], dp[i][j - 1]) , dp[i - 1][j - 1]) + 1;
            }
        }
    }

    return dp[m][n];
}

int main() {
    int res = minDistance("", "");
    printf("%d\n", res);

    return 0;
}