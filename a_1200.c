#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int compareInt(const void* a, const void* b) {
    int int_a = *(int*)a;
    int int_b = *(int*)b;

    return int_a - int_b;
}

int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes) {
    qsort(arr, arrSize, sizeof(int), compareInt);

    int min = INT_MAX;
    for (int i = 1; i < arrSize; i++) {
        int num = arr[i] - arr[i - 1];
        min = min < num ? min : num;
    }

    int **ans = malloc(sizeof(int*) * arrSize);
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * arrSize);
    for (int i = 1; i < arrSize; i++) {
        int num = arr[i] - arr[i - 1];
        if (num == min) {
            int *t = malloc(sizeof(int) * 2);
            t[0] = arr[i - 1];
            t[1] = arr[i];
            ans[*returnSize] = t;
            (*returnColumnSizes)[*returnSize] = 2;
            (*returnSize)++;
        }
    }

    return ans;
}

int main() {
    int nums[] = {0, 1, 2, 7, 3, 9, 5};
    int len = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int *returnColumnSizes;
    int **res = minimumAbsDifference(nums, len, &returnSize, &returnColumnSizes);

    free(res);

    return 0;
}