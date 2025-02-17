#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compareInt(const void* a, const void* b) {
    int int_a = *(int*)a;
    int int_b = *(int*)b;

    return int_a - int_b;
}

void backtrack(int* nums, int numsSize, int* returnSize, int** returnColumnSizes, int** result, int start, int *tempArr, int ts, bool* used) {
    int *arr = malloc(sizeof(int) * ts);
    for (int i = 0; i < ts; i++) {
        arr[i] = tempArr[i];
    }
    result[*returnSize] = arr;
    (*returnColumnSizes)[*returnSize] = ts;
    (*returnSize)++;

    for (int i = start; i < numsSize; i++) {
        if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
            continue;
        }
        used[i] = true;
        tempArr[ts] = nums[i];
        backtrack(nums, numsSize, returnSize, returnColumnSizes, result, i + 1, tempArr, ts + 1, used);
        used[i] = false;
    }
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compareInt);
    int **ans = malloc(sizeof(int*) * (1 << numsSize));
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * (1 << numsSize));
    int *tempArr = malloc(sizeof(int) * numsSize);
    bool *used = malloc(sizeof(bool) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        used[i] = false;
    }
    backtrack(nums, numsSize, returnSize, returnColumnSizes, ans, 0, tempArr, 0, used);
    free(tempArr);
    free(used);
    return ans;
}

int main() {
    int nums[] = {2, 1, 2};
    int len = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int *returnColumnSizes;
    int **res = subsetsWithDup(nums, len, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    free(res);

    return 0;
}