#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int *hash = calloc(numsSize, sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        hash[nums[i] - 1] = 1;
    }

    int *res = malloc(sizeof(int) * numsSize);
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++) {
        if (hash[i] == 0) {
            res[*returnSize] = i + 1;
            (*returnSize)++;
        }
    }

    free(hash);

    return res;
}

int main() {
    int nums[] = {1, -2147483648, 2};
    int len = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int *res = findDisappearedNumbers(nums, len, &returnSize);

    for (int i = 0; i < len; i++) {
        printf("%d ", res[i]);
    }

    free(res);

    return 0;
}

