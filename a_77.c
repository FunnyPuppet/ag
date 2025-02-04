#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int combination(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }
    if (k == 0 || k == n) {
        return 1;
    }
    if (k > n - k) {
        k = n - k;
    }
    long result = 1;
    for (int i = 1; i <= k; i++) {
        result *= n - k + i;
        result /= i;
    }
    return result;
}

void backtrack(int start, int n, int k, int* temp, int tempSize, int** res, int* returnSize, int** returnColumnSizes) {
    if (k == tempSize) {
        int *comb = malloc(k * sizeof(int));
        memcpy(comb, temp, k * sizeof(int));
        (*returnColumnSizes)[*returnSize] = k;
        res[*returnSize] = comb;
        (*returnSize)++;
        return;
    }

    int max = n - (k - tempSize) + 1;
    for (int i = start; i <= max; i++) {
        temp[tempSize] = i;
        backtrack(i + 1, n, k, temp, tempSize + 1, res, returnSize, returnColumnSizes);
    }
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
    int total = combination(n, k);
    int **res = malloc(sizeof(int*) * total);
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * total);
    int *temp = malloc(sizeof(int) * k);

    if (total > 0) {
        backtrack(1, n ,k, temp, 0, res, returnSize, returnColumnSizes);
    }

    free(temp);

    return res;
}

int main() {
    int returnSize;
    int *returnColumnSizes;
    int** res = combine(100, 50, &returnSize, &returnColumnSizes);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
        free(res[i]);
    }
    free(res);

    return 0;
}

