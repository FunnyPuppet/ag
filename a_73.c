#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <tgmath.h>

void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int cn = *matrixColSize;
    int *m = malloc(sizeof(int) * matrixSize);
    int *n = malloc(sizeof(int) * cn);

    for (int i = 0; i < matrixSize; i++) {
        m[i] = 0;
    }
    for (int i = 0; i < cn; i++) {
        n[i] = 0;
    }

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < cn; j++) {
            if (matrix[i][j] == 0) {
                m[i] = 1;
                n[j] = 1;
            }
        }
    }

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < cn; j++) {
            if (m[i] == 1 || n[j] == 1) {
                matrix[i][j] = 0;
            }
        }
    }
    free(m);
    free(n);
}

int main() {

    return 0;
}