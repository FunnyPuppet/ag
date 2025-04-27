#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int countSubarrays(int* nums, int numsSize) {
    int ans = 0;

    for (int i = 1; i < numsSize - 1; i++) {
        if ((nums[i - 1] + nums[i + 1]) * 2 == nums[i]) {
            ans++;
        }
    }

    return ans;
}

int main() {
    int nums[] = {1,2,1,4,1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int res = countSubarrays(nums, numsSize);
    printf("%d\n", res);

    return 0;
}