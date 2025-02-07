#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    *returnSize = n;
    int **ans = malloc(sizeof(int*) * n);
    *returnColumnSizes = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        int *col = calloc(n, sizeof(int));
        (*returnColumnSizes)[i] = n;
        ans[i] = col;
    }

    int index = 1;
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            ans[top][i] = index++;
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            ans[i][right] = index++;
        }
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                ans[bottom][i] = index++;
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                ans[i][left] = index++;
            }
            left++;
        }
    }

    return ans;
}


int main() {
    int n = 3;
    int returnSize;
    int *returnColumnSizes;
    int **result = generateMatrix(n, &returnSize, &returnColumnSizes);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
        free(result[i]);
    }
    free(returnColumnSizes);
    free(result);

    return 0;
}

