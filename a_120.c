#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    int dp[triangleSize][triangleSize];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < triangleSize; i++) {
        dp[i][0] = dp[i - 1][0] + triangle[i][0];
        for (int j = 1; j < i; j++) {
            dp[i][j] = fmin(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
        }
        dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
    }

    int ans = dp[triangleSize - 1][0];

    for (int i = 1; i < triangleSize; i++) {
        ans = fmin(ans, dp[triangleSize - 1][i]);
    }

    return ans;
}

int main() {
    int m = 4;
    int questions[4][4] = {{1}, {2, 3}, {4, 5, 6}, {7, 8, 9, 10}};
    int *arr[m];

    for (int i = 0; i < m; i++) {
        arr[i] = questions[i];
    }

    minimumTotal(arr, m, NULL);

    return 0;
}