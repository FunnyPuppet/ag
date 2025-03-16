#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include "list_node.h"


int largestVariance(char* s) {
    int n = strlen(s);
    int dp[26][n];
    int cs[26] = {0};

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        int j = s[i] - 'a';
        dp[j][cs[j]] = i;
        cs[j]++;
    }

    int ans = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (i != j && cs[i] > 0 && cs[j] > 0) {
                int p = 0, q = 0;
                int f = 0, g = INT_MIN;
                while (p < cs[i] || q < cs[j]) {
                    if (q == cs[j] || (p < cs[i] && dp[i][p] < dp[j][q])) {
                        f = fmax(f, 0) + 1;
                        g = g + 1;
                        p++;
                    } else {
                        g = fmax(f, fmax(g, 0)) - 1;
                        f = fmax(f, 0) - 1;
                        q++;
                    }
                    ans = fmax(g, ans);
                }
            }
        }
    }


    return ans;
}

int main() {
    int res = largestVariance("abcde");
    printf("%d\n", res);

    return 0;
}