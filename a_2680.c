#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

long long maximumOr(int* nums, int numsSize, int k) {
    long long m = 0, n = 0;

    for (int i = 0; i < numsSize; i++) {
        m |= n & nums[i];
        n |= nums[i];
    }

    long long ans = 0;
    for (int i = 0; i < numsSize; i++) {
        ans = fmax(ans, (n ^ nums[i]) | ((long long)nums[i] << k) | m);
    }

    return ans;
}

int main() {
    int nums[] = {8, 9};
    int len = sizeof(nums) / sizeof(nums[0]);
    int res = maximumOr(nums, len, 1);
    printf("%d\n", res);

    return 0;
}