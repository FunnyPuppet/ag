#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define HASH_SZIE 1000001

int firstMissingPositive(int* nums, int numsSize) {
    // 将数组所有小于等于0的数设置为numsSize + 1
    for (size_t i = 0; i < numsSize; i++) {
        if (nums[i] <= 0) {
            nums[i] = numsSize + 1;
        }
    }

    // 将小于numsSize的数字对于下标的数字设置为负数，用于标记数字出现过
    for (size_t i = 0; i < numsSize; i++) {
        int index = abs(nums[i]);
        if (index <= numsSize) {
            nums[index - 1] = -abs(nums[index - 1]);
        }
    }

    // 第一次出现大于0的数字对应的下标加1则是缺失的第一个正整数
    for (size_t i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            return i + 1;
        }
    }

    // 如果所有的数字都满足条件，则缺失的数字为numsSize + 1
    return numsSize + 1;
}

int main() {
    int nums[] = {3, 4, -1, 1};
    int len = sizeof(nums) / sizeof(nums[0]);

    int res = firstMissingPositive(nums, len);

    printf("%d", res);

    return 0;
}
