#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

typedef struct {
    int matrixSize;
    int **prefix;
} NumMatrix;


NumMatrix* numMatrixCreate(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize, n = matrixColSize[0];
    int **prefix = malloc(sizeof(int*) * (m + 1));

    for (int i = 0; i <= m; i++) {
        prefix[i] = malloc(sizeof(int) * (n + 1));
    }

    for (int i = 0; i <= m; i++) {
        prefix[i][0] = 0;
    }

    for (int i = 0; i < n; i++) {
        prefix[0][i] = 0;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] + matrix[i - 1][j - 1] - prefix[i - 1][j - 1];
        }
    }

    NumMatrix *numMatrix = malloc(sizeof(NumMatrix));
    numMatrix->matrixSize = m + 1;
    numMatrix->prefix = prefix;

    return numMatrix;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2) {
    return obj->prefix[row2 + 1][col2 + 1] - obj->prefix[row1][col2 + 1] - obj->prefix[row2 + 1][col1] + obj->prefix[row1][col1];
}

void numMatrixFree(NumMatrix* obj) {
    for (int i = 0; i < obj->matrixSize; i++) {
        free(obj->prefix[i]);
    }
    free(obj->prefix);
    free(obj);
}

int main() {
    int m = 5, n = 5;
    int nums[5][5] = {{3,0,1,4,2}, {5,6,3,2,1}, {1,2,0,1,5},{4,1,0,1,7},{1,0,3,0,5}};
    int *cols = malloc(sizeof(int) * m);
    int *arr[m];

    for (int i= 0; i < m; i++) {
        arr[i] = nums[i];
        cols[i] = n;
    }

    NumMatrix *numMatrix = numMatrixCreate(arr, m, cols);

    printf("%d\n", numMatrixSumRegion(numMatrix, 2, 1, 4, 3));
    printf("%d\n", numMatrixSumRegion(numMatrix, 1, 1, 2, 2));
    printf("%d\n", numMatrixSumRegion(numMatrix, 1, 2, 2, 4));

    numMatrixFree(numMatrix);

    return 0;
}