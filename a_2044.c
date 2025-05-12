#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int countMaxOrSubsets(int* nums, int numsSize){
    int n = numsSize, maxValue = 0, cnt = 0, stateNumber = 1 << n;

    for (int i = 0; i < stateNumber; i++) {
        int cur = 0;
        for (int j = 0; j < n; j++) {
            if (((i >> j) & 1) == 1) {
                cur |= nums[j];
            }
        }
        if (cur == maxValue) {
            cnt++;
        } else if (cur > maxValue) {
            maxValue = cur;
            cnt = 1;
        }
    }

    return cnt;
}

int main() {
    int nums[] = {3, 1};
    int len = sizeof(nums) / sizeof(nums[0]);
    int res = countMaxOrSubsets(nums, len);
    printf("%d\n", res);

    return 0;
}