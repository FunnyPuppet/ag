#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int m = matrixSize;
    int n = *matrixColSize;

    *returnSize = m * n;
    int *ans = malloc(sizeof(int) * *returnSize);
    int index = 0;

    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            ans[index++] = matrix[top][i];
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            ans[index++] = matrix[i][right];
        }
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                ans[index++] = matrix[bottom][i];
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                ans[index++] = matrix[i][left];
            }
            left++;
        }
    }

    return ans;
}


int main() {
    int matrixSize = 3;
    int matrixColSize = 3;
    int **matrix = malloc(matrixSize * sizeof(int *));
    for (int i = 0; i < matrixSize; i++) {
        matrix[i] = (int *)malloc(matrixColSize * sizeof(int));
        for (int j = 0; j < matrixColSize; j++) {
            matrix[i][j] = i * matrixColSize + j + 1;
        }
    }

    int returnSize;
    int *result = spiralOrder(matrix, matrixSize, &matrixColSize, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    // 释放内存
    for (int i = 0; i < matrixSize; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(result);

    return 0;
}

