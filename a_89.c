#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

int* grayCode(int n, int* returnSize) {
    int len = 1 << n;
    int *res = malloc(sizeof(int) * len);

    for (int i = 0; i < len; i++) {
        res[i] = (i >> 1) ^ i;
    }

    *returnSize = len;
    return res;
}

int main() {
    int returnSize;
    int *res = grayCode(2, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");

    free(res);

    return 0;
}