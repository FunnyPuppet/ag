#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int compareInt(const void *a, const void *b) {
    int int_a = *(const int*)a;
    int int_b = *(const int*)b;
    return int_a - int_b;
}

void backtrack(int curSize, int* cur, bool* used, int** res, int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    if (curSize == numsSize) {
        int *temp = malloc(sizeof(int) * numsSize);
        memcpy(temp, cur, sizeof(int) * numsSize);
        res[*returnSize] = temp;
        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }

    for (int i = 0; i < numsSize; i++) {
        if (used[i]) {
            continue;
        }
        if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
            continue;
        }
        cur[curSize] = nums[i];
        used[i] = true;
        backtrack(curSize + 1, cur, used, res, nums, numsSize, returnSize, returnColumnSizes);
        used[i] = false;
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int **res = malloc(sizeof(int*) * 100000);
    bool *used = calloc(numsSize, sizeof(bool));
    int *cur = malloc(sizeof(int) * numsSize);
    *returnColumnSizes = malloc(sizeof(int) * 100000);
    *returnSize = 0;
    qsort(nums, numsSize, sizeof(int), compareInt);
    backtrack(0, cur, used, res, nums, numsSize, returnSize, returnColumnSizes);

    free(cur);
    free(used);
    return res;
}

int main() {
    int nums[] = {2, 2, 1, 1};
    int len = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int *returnColumnSizes;
    int **res = permuteUnique(nums, len, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf(" %d ", res[i][j]);
        }
        printf("\n");
        free(res[i]);
    }

    free(returnColumnSizes);
    free(res);

    return 0;
}
