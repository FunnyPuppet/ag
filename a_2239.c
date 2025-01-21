#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int findClosestNumber(int* nums, int numsSize) {
    int m = nums[0], n = abs(nums[0]);

    for (int i = 1; i < numsSize; i++) {
        int num = nums[i];

        if (abs(num) < n) {
            m = num;
            n = abs(num);
        } else if (abs(num) == n) {
            m = num > m ? num : m;
        }
    }

    return m;
}

int main() {
    int nums[] = {-10,-12,-54,-12,-544,-10000};
    int len = sizeof(nums) / sizeof(nums[0]);

    int res = findClosestNumber(nums, len);

    printf("%d", res);

    return 0;
}
