#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int **res = malloc(numRows * sizeof(int*));

    *returnSize = numRows;

    *returnColumnSizes = malloc(numRows * sizeof(int));

    for (int i = 0; i < numRows; i++) {
        int *arr = malloc((i + 1) * sizeof(int));
        (*returnColumnSizes)[i] = i + 1;
        for (int j = 0; j < i + 1; j++) {
            if (j == 0 || j == i) {
                arr[j] = 1;
            } else {
                arr[j] = res[i - 1][j] + res[i - 1][j - 1];
            }
        }

        res[i] = arr;
    }

    return res;
}

int main() {
    int returnSize = 0;
    int *returnColumnSizes = NULL;
    int **res = generate(6, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < returnSize; i++) {
        free(res[i]);
    }

    free(res);
    free(returnColumnSizes);
    return 0;
}
