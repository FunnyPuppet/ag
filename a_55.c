#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

bool canJump(int* nums, int numsSize) {
    int max = 0;

    for (int i = 0; i < numsSize - 1; i++) {
        if ((i > 0 && max == 0) || max < i) {
            return false;
        }
        int dis = i + nums[i];
        max = max > dis ? max : dis;
    }

    return max >= numsSize - 1;
}

int main() {
    int nums[] = {1,0,1,0};
    int len = sizeof(nums) / sizeof(nums[0]);
    bool res = canJump(nums, len);

    printf("%d\n", res);

    return 0;
}