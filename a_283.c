#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void moveZeroes(int* nums, int numsSize) {
    int l = 0;

    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        if (num != 0) {
            nums[i] = nums[l];
            nums[l] = num;
            l += 1;
        }
    }
}

int main() {
    int nums[] = {0, 1, 2, 3};
    int len = sizeof(nums) / sizeof(nums[0]);
    moveZeroes(nums, len);

    for (int i = 0; i < len; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}

