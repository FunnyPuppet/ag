#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int minOperations(int* nums, int numsSize) {
    int ans = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            if (i > numsSize - 3) {
                return -1;
            }
            nums[i] ^= 1;
            nums[i + 1] ^= 1;
            nums[i + 2] ^= 1;
            ans++;
        }
    }

    return ans;
}

int main() {
    int nums[] = {0, 1, 1, 1, 0, 0};
    int len = sizeof(nums) / sizeof(nums[0]);
    int res = minOperations(nums, len);
    printf("%d\n", res);

    return 0;
}