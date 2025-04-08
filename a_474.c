#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

void getZerosOnes(int* zerosOnes, char* str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        zerosOnes[str[i] - '0']++;
    }
}

int findMaxForm(char** strs, int strsSize, int m, int n) {
    int length = strsSize;
    int dp[length + 1][m + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= length; i++) {
        int zerosOnes[2] = {0};
        getZerosOnes(zerosOnes, strs[i - 1]);
        int zeros = zerosOnes[0], ones = zerosOnes[1];
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= n; k++) {
                dp[i][j][k] = dp[i - 1][j][k];
                if (j >= zeros && k >= ones) {
                    dp[i][j][k] = fmax(dp[i][j][k], dp[i - 1][j - zeros][k - ones] + 1);
                }
            }
        }
    }
    return dp[length][m][n];
}

int main() {
    char *strs[] = {"10", "0001", "111001", "1", "0"};
    int len = sizeof(strs) / sizeof(strs[0]);
    findMaxForm(strs, len, 5 , 3);
    return 0;
}