#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>


int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    int l = 0, r = 0;

    while (r < numsSize) {
        if (nums[r] % 2 == 0) {
            int tmp = nums[r];
            nums[r] = nums[l];
            nums[l] = tmp;
            l++;
        }
        r++;
    }

    *returnSize = numsSize;
    return nums;
}

int main() {
    int nums[] = {3, 1, 2, 4};
    int size = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int *res = sortArrayByParity(nums, size, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");

    return 0;
}