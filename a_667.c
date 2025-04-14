#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int* constructArray(int n, int k, int* returnSize) {
    int *ans = malloc(sizeof(int) * n);
    *returnSize = 0;

    int start = 1, end = k + 1;
    while (start < end) {
        ans[(*returnSize)++] = start++;
        ans[(*returnSize)++] = end--;
    }
    if (k % 2 == 0) {
        ans[(*returnSize)++] = start;
    }
    for (int i = k + 2; i <= n; i++) {
        ans[(*returnSize)++] = i;
    }

    return ans;
}

int main() {
    int returnSize;
    int* res = constructArray(10, 6, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
    free(res);
    return 0;
}