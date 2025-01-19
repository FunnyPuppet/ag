#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int maximumCount(int* nums, int numsSize) {
    int l = 0, r = numsSize - 1;

    while (l <= r) {
        int m = l + (r - l) / 2;

        if (nums[m] > 0) {
            r = m - 1;
        } else if (nums[m] < 0) {
            l = m + 1;
        } else {
            int min = m, max = m;
            while (min >= l) {
                if (nums[min] != 0) {
                    break;
                }
                min--;
            }
            while (max <= r) {
                if (nums[max] != 0) {
                    break;
                }
                max++;
            }

            r = min;
            l = max;
            break;
        }
    }

    return numsSize - l > r + 1 ? numsSize - l : r + 1;
}

int main() {
    int nums[] = {-1,0,3,5,9,12};
    int len = sizeof(nums) / sizeof(nums[0]);

    int res = maximumCount(nums, len);

    printf("%d", res);

    return 0;
}
