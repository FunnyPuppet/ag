#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    int n = strlen(s);

    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < wordDictSize; j++) {
            char *word = wordDict[j];
            int m = strlen(word);
            if (m <= i) {
                char t[m + 1];
                strncpy(t, s + (i - m), m);
                t[m] = '\0';

                if (strcmp(word, t) == 0 && dp[i - m]) {
                    dp[i] = 1;
                }
            }
        }
    }

    return dp[n];
}

int main() {
    char *words[] = {"leet", "code"};
    bool res = wordBreak("leetcode", words, 2);
    printf("%d\n", res);

    return 0;
}