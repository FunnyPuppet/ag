#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    int m = obstacleGridSize, n = obstacleGridColSize[0];
    int dp[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        if (obstacleGrid[0][i] == 1) break;
        dp[0][i] = 1;
    }
    for (int i = 0; i < m; i++) {
        if (obstacleGrid[i][0] == 1) break;
        dp[i][0] = 1;
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    return dp[m - 1][n - 1];
}

int main() {
    int m = 3, n = 3;
    int *col = malloc(sizeof(int) * m);
    int obstacleGrid[3][3] = {{0,0,0},{0,1,0},{0,0,0}};

    int *arr[m];

    for (int i = 0; i < m; i++) {
        arr[i] = obstacleGrid[i];
        col[i] = n;
    }
    int res = uniquePathsWithObstacles(arr, m, col);
    printf("%d\n", res);

    free(col);

    return 0;
}