#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int singleNumber(int* nums, int numsSize) {
    int res = 0;

    for (int i = 0; i < numsSize; i++) {
        res = res ^ nums[i];
    }

    return res;
}

int main() {
    int nums[] = {2, 2, 1};
    int len = sizeof(nums) / sizeof(nums[0]);

    int res = singleNumber(nums, len);

    printf("%d", res);

    return 0;
}
