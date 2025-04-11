#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int countSubstrings(char* s) {
    int n = strlen(s);
    bool dp[n];
    int ans = 0;

    for (int i = 0; i < n; i++) {
        dp[i] = true;
        ans++;
        for (int j = 0; j < i; j++) {
            if (s[i] == s[j] && dp[j + 1]) {
                dp[j] = true;
                ans++;
            } else {
                dp[j] = false;
            }
        }
    }

    return ans;
}

int main() {
    int res = countSubstrings("abc");
    printf("%d\n", res);

    return 0;
}