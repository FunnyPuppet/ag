#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int maxSubArray(int* nums, int numsSize) {
    int dp[numsSize];
    dp[0] = nums[0];

    int max = dp[0];
    for (int i = 1; i < numsSize; i++) {
        dp[i] = fmax(nums[i], dp[i - 1] + nums[i]);
        max = fmax(dp[i], max);
    }

    return max;
}

int main() {
    int nums[] = {-1, 0, -2};
    int len = sizeof(nums) / sizeof(nums[0]);

    int res = maxSubArray(nums, len);
    printf("%d\n", res);

    return 0;
}