#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

int* sortArrayByParityII(int* nums, int numsSize, int* returnSize) {
    int l = 0, r = numsSize - 1;

    while (l < numsSize) {
        if (nums[l] % 2 == 1) {
            int tmp = nums[r];
            nums[r] = nums[l];
            nums[l] = tmp;
            r -= 2;
        } else {
            l += 2;
        }
    }

    *returnSize = numsSize;
    return nums;
}

int main() {
    int nums[] = {2, 4, 1, 3};
    int len = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int *res = sortArrayByParityII(nums, len, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");

    free(res);

    return 0;
}