#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <tgmath.h>

int* findPeakGrid(int** mat, int matSize, int* matColSize, int* returnSize) {
    int* ans = malloc(2 * sizeof(int));
    int l = 0, r = *matColSize - 1;

    *returnSize = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;

        int maxRow = 0;
        for (int i = 1; i < matSize; i++) {
            if (mat[i][mid] > mat[maxRow][mid]) {
                maxRow = i;
            }
        }

        int leftVal = (mid > l) ? mat[maxRow][mid - 1] : -1;
        int rightVal = (mid < r) ? mat[maxRow][mid + 1] : -1;
        int cur = mat[maxRow][mid];

        if (cur > leftVal && cur > rightVal) {
            ans[0] = maxRow;
            ans[1] = mid;
            *returnSize = 2;
            return ans;
        }
        if (leftVal > cur) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return ans;
}

int main() {
    int m = 2, n = 5;
    int mat[2][5] = {{70,50,40,30,20}, {100,1,2,3,4}};
    int* matPtrs[3];
    for (int i = 0; i < m; i++) {
        matPtrs[i] = mat[i];
    }

    int returnSize;
    int *res = findPeakGrid(matPtrs, m, &n, &returnSize);
    printf("[%d %d]\n", res[0], res[1]);

    free(res);

    return 0;
}