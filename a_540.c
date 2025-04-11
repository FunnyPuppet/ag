#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int singleNonDuplicate(int* nums, int numsSize) {
    int l = 0, r = numsSize - 1;

    while (l < r) {
        int mid = l + (r - l) / 2;

        if (nums[mid] == nums[mid ^ 1]) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    return nums[l];
}

int main() {
    int nums[] = {1,1,2};
    int len = sizeof(nums) / sizeof(nums[0]);
    int res = singleNonDuplicate(nums, len);
    printf("%d\n", res);

    return 0;
}