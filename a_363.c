#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int maxSumSubmatrix(int** matrix, int matrixSize, int* matrixColSize, int k) {
    int m = matrixSize, n = matrixColSize[0];

    int prefix[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            prefix[i][j] = 0;
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] + matrix[i - 1][j - 1] - prefix[i - 1][j - 1];
        }
    }

    int ans = INT_MIN;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int p = i; p < m; p++) {
                for (int q = j; q < n; q++) {
                    int num = prefix[p + 1][q + 1] - prefix[i][q + 1] - prefix[p + 1][j] + prefix[i][j];
                    if (num <= k) {
                        ans = fmax(ans, num);
                    }
                }
            }
        }
    }

    return ans;
}

int main() {
    int m = 2, n = 3;
    int nums[2][3] = {{1,0,1}, {0,-2,3}};
    int *cols = malloc(sizeof(int) * m);
    int *arr[m];

    for (int i= 0; i < m; i++) {
        arr[i] = nums[i];
        cols[i] = n;
    }

    int res = maxSumSubmatrix(arr, m, cols, 2);
    printf("%d\n", res);
    free(cols);

    return 0;
}