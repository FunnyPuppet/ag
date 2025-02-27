#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

int compareInt(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int *res = malloc(sizeof(int) * numsSize);

    for (int i = 0; i < numsSize; i++) {
        res[i] = nums[i] * nums[i];
    }

    qsort(res, numsSize, sizeof(int), compareInt);

    *returnSize = numsSize;
    return res;
}

int main() {
    int nums[] = {1, 2, 1, 10};
    int len = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int *res = sortedSquares(nums, len, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");

    free(res);

    return 0;
}