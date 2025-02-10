#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isMonotonic(int* nums, int numsSize) {
    if (numsSize <= 1) {
        return true;
    }

    if (nums[0] < nums[numsSize - 1]) {
        for (int i = 1; i < numsSize; i++) {
            if (nums[i] < nums[i - 1]) {
                return false;
            }
        }
    } else if (nums[0] > nums[numsSize - 1]) {
        for (int i = 1; i < numsSize; i++) {
            if (nums[i] > nums[i - 1]) {
                return false;
            }
        }
    } else {
        for (int i = 1; i < numsSize; i++) {
            if (nums[i] != nums[i - 1]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int nums[] = {0, 1, 2};
    int len = sizeof(nums) / sizeof(nums[0]);
    bool res = isMonotonic(nums, len);

    printf("%d\n", res);

    return 0;
}