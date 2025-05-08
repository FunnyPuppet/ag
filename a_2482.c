#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int** onesMinusZeros(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    int m = gridSize, n = gridColSize[0];
    int or[m], oc[n];
    memset(or, 0, sizeof(or));
    memset(oc, 0, sizeof(oc));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                or[i]++;
                oc[j]++;
            }
        }
    }

    int **ans = malloc(sizeof(int*) * m);
    *returnSize = m;
    *returnColumnSizes = malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        ans[i] = malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
        for (int j = 0; j < n; j++) {
            ans[i][j] = or[i] + oc[j] - (n - or[i]) - (m - oc[j]);
        }
    }

    return ans;
}

int main() {
    int m = 3;
    int n = 4;
    int *col = malloc(sizeof(int) * m);
    int nums[3][4] = {{0, 1, 1, 1}, {1, 0, 0, 1}, {0, 0, 1, 1}};

    int **arr = malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i++) {
        arr[i] = nums[i];
        col[i] = n;
    }
    int returnSize;
    int *returnColumnSizes;
    int **res = onesMinusZeros(arr, m, col, &returnSize, &returnColumnSizes);

    free(res);
    free(col);
    free(arr);

    return 0;
}