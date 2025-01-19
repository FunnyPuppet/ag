#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int search(int* nums, int numsSize, int target) {
    int l = 0, r = numsSize - 1;

    while (l <= r) {
        int m = l + (r - l) / 2;

        if (nums[m] == target) {
            return m;
        } else if (nums[m] > target) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    return -1;
}

int main() {
    int nums[] = {-1,0,3,5,9,12};
    int len = sizeof(nums) / sizeof(nums[0]);

    int res = search(nums, len, 3);

    printf("%d", res);

    return 0;
}
