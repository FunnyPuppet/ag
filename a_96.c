#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#include "list_node.h"

int numTrees(int n) {
    int dp[n + 1];

    for (int i = 0; i <= n; i++) {
        dp[i] = 0;
    }

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        for(int j = 1; j < i + 1; j++) {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }

    return dp[n];
}

int main() {
    for (int i = 1; i < 20; i++) {
        printf("%d\n", numTrees(i));
    }

    return 0;
}