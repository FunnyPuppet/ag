#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int maxProduct(int* nums, int numsSize) {
    long max = nums[0], min = nums[0], ans = nums[0];

    for (int i = 1; i < numsSize; ++i) {
        long mx = max, mn = min;
        max = fmax(mx * nums[i], fmax(nums[i], mn * nums[i]));
        min = fmin(mn * nums[i], fmin(nums[i], mx * nums[i]));
        if(min < INT_MIN) {
            min = nums[i];
        }
        ans = fmax(max, ans);
    }

    return ans;
}

int main() {
    int nums[] = {2, 3, 0, -2, 4, -1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int res = maxProduct(nums, numsSize);
    printf("%d\n", res);

    return 0;
}