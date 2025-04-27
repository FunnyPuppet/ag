#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

long long maxStrength(int* nums, int numsSize) {
    long long min = nums[0], max = min;

    for (int i = 1; i < numsSize; i++) {
        int num = nums[i];
        long long tmp = min;

        min = fmin(fmin(min, num), fmin(num * min, num * max));
        max = fmax(fmax(max, num), fmax(num * tmp, num * max));
    }

    return max;
}

int main() {
    int nums[] = {1,2,1,4,1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int res = maxStrength(nums, numsSize);
    printf("%d\n", res);

    return 0;
}