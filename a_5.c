#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <tgmath.h>

char* longestPalindrome(char* s) {
    int len = strlen(s);

    if (len == 1) {
        return s;
    }

    int start = 0, max = 0;

    int dp[len][len];
    memset(dp, 0, sizeof(dp));

    for (int i = len - 1; i >= 0; i--) {
        for (int j = i; j < len; j++) {
            if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])) {
                dp[i][j] = 1;
                if (j - i + 1 > max) {
                    max = j - i + 1;
                    start = i;
                }
            }
        }
    }

    char *ans = malloc(sizeof(char) * (max + 1));
    strncpy(ans, s + start, max);
    ans[max] = '\0';

    return ans;
}

int main() {
    char *res = longestPalindrome("bbacc");
    printf("%s\n", res);

    return 0;
}