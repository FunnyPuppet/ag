#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize;

    for (int l = 0, r = n - 1; l < n && r >= 0; l++, r--) {
        for (int j = l; j < r; j++) {
            int top = matrix[l][j], right = matrix[j][r], bottom = matrix[r][n - j - 1], left = matrix[n - j - 1][l];

            matrix[l][j] = left;
            matrix[j][r] = top;
            matrix[r][n - j - 1] = right;
            matrix[n - j - 1][l] = bottom;
        }
    }
}

int main() {
    int n = 4;
    int matrix[4][4] = {{5,1,9,11}, {2,4,8,10}, {13,3,6,7}, {15,14,12,16}};
    int *arr[n];
    int *cols = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        arr[i] = matrix[i];
        cols[i] = n;
    }

    rotate(arr, n, cols);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}