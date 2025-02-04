#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];

        int index = abs(num) - 1;

        if (nums[index] > 0) {
            nums[index] = -nums[index];
        }
    }

    int *res = malloc(sizeof(int) * numsSize);
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            res[*returnSize] = i + 1;
            (*returnSize)++;
        }
    }

    return res;
}

int main() {
    int nums[] = {4, 3, 2, 7, 8, 2, 3, 1};
    int len = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int *res = findDisappearedNumbers(nums, len, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", res[i]);
    }

    free(res);

    return 0;
}

