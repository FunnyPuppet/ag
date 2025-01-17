#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;

    int *pre = malloc(1 * sizeof(int));
    pre[0] = 1;
    int *cur = pre;
    for (int i = 1; i <= rowIndex; i++) {
        cur = malloc((i + 1) * sizeof(int));

        for (int j = 0; j < i + 1; j++) {
            if (j == 0 || j == i) {
                cur[j] = 1;
            } else {
                cur[j] = pre[j] + pre[j - 1];
            }
        }

        free(pre);
        pre = cur;
    }

    return cur;
}

int main() {
    int returnSize = 0;
    int *res = getRow(6, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", res[i]);
    }

    free(res);
    return 0;
}
