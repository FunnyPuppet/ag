#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool containsDuplicate(int* nums, int numsSize) {
    if (numsSize <= 1) {
        return false;
    }

    int min = nums[0], max = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < min) {
            min = nums[i];
            continue;
        }
        if (nums[i] > max) {
            max = nums[i];
            continue;
        }

        for (int j = 0; j < i; j++) {
            if (nums[j] == nums[i])
                return true;
        }
    }
    return false;
}

int main() {
    int nums[] = {};
    int len = sizeof(nums) / sizeof(nums[0]);
    bool flag = containsDuplicate(nums, len);

    printf("%d\n", flag);

    return 0;
}

