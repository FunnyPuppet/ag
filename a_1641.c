#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int countVowelStrings(int n) {
    int dp[5];

    for (int i = 0; i < 5; i++) {
        dp[i] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < 5; j++) {
            dp[j] += dp[j - 1];
        }
    }

    int ans = 0;

    for (int i = 0; i < 5; i++) {
        ans += dp[i];
    }

    return ans;
}

int main() {
    int res = countVowelStrings(5);
    printf("%d\n", res);

    return 0;
}