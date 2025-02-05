#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int max = 0, count = 0;
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        if (num == 0) {
            max = count > max ? count : max;
            count = 0;
        } else {
            count++;
        }
    }

    max = count > max ? count : max;

    return max;
}

int main() {
    int nums[] = {0, 0};
    int len = sizeof(nums) / sizeof(nums[0]);
    int max = findMaxConsecutiveOnes(nums, len);

    printf("%d\n", max);

    for (int i = 0; i < len; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}

