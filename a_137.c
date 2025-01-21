#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int singleNumber(int* nums, int numsSize) {
    int ones = 0, twos = 0;

    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        // twos 保存出现了两次的位
        twos |= ones & num;
        // ones 保存出现了一次的位
        ones ^= num;
        // 当 ones 和 twos 都有 1 时，清除那些位
        int threes = ones & twos;
        ones &= ~threes;
        twos &= ~threes;
    }
    return ones;
}

int main() {
    int nums[] = {2, 2, 2, 1};
    int len = sizeof(nums) / sizeof(nums[0]);

    int res = singleNumber(nums, len);

    printf("%d", res);

    return 0;
}
