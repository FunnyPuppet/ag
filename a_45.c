#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int jump(int* nums, int numsSize) {
    int max = 0, end = 0, ans = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        max = i + nums[i] > max ? i + nums[i] : max;

        if (i == end) {
            end = max;
            ans++;
        }
    }

    return ans;
}

int main() {
    int nums[] = {1,2,1,1,1};
    int len = sizeof(nums) / sizeof(nums[0]);
    int res = jump(nums, len);

    printf("%d\n", res);

    return 0;
}