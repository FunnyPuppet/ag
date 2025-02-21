#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int *left = malloc(sizeof(int) * numsSize);
    int *right = malloc(sizeof(int) * numsSize);

    left[0] = nums[0], right[numsSize - 1] = nums[numsSize - 1];
    for (int i = 1; i < numsSize - 1; i++) {
        left[i] = nums[i] * left[i - 1];
        right[numsSize - i - 1] = right[numsSize - i] * nums[numsSize - i - 1];
    }

    int *ans = malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    ans[0] = right[1], ans[numsSize - 1] = left[numsSize - 2];
    for (int i = 1; i < numsSize - 1; i++) {
        ans[i] = left[i - 1] * right[i + 1];
    }
    free(left);
    free(right);

    return ans;
}

int main() {
    int nums[] = {1, 2, 3, 4, 5};
    int len = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int *res = productExceptSelf(nums, len, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", res[i]);
    }
    free(res);

    return 0;
}