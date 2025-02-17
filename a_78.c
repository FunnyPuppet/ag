#include <stdio.h>
#include <stdlib.h>

void backtrack(int* nums, int numsSize, int* returnSize, int** returnColumnSizes, int** result, int start, int *tempArr, int ts) {
    int *arr = malloc(sizeof(int) * ts);
    for (int i = 0; i < ts; i++) {
        arr[i] = tempArr[i];
    }
    result[*returnSize] = arr;
    (*returnColumnSizes)[*returnSize] = ts;
    (*returnSize)++;

    for (int i = start; i < numsSize; i++) {
        tempArr[ts] = nums[i];
        backtrack(nums, numsSize, returnSize, returnColumnSizes, result, i + 1, tempArr, ts + 1);
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int **ans = malloc(sizeof(int*) * (1 << numsSize));
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * (1 << numsSize));
    int *tempArr = malloc(sizeof(int) * numsSize);
    backtrack(nums, numsSize, returnSize, returnColumnSizes, ans, 0, tempArr, 0);
    free(tempArr);
    return ans;
}

int main() {
    int nums[] = {1, 2, 3};
    int len = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int *returnColumnSizes;
    int **res = subsets(nums, len, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    free(res);

    return 0;
}