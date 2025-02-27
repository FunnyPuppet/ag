#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

int compareInt(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int largestPerimeter(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compareInt);

    for (int i = numsSize - 1; i >= 2; i--) {
        if (nums[i - 2] + nums[i - 1] > nums[i]) {
            return nums[i - 2] + nums[i - 1] + nums[i];
        }
    }

    return 0;
}

int main() {
    int nums[] = {1, 2, 1, 10};
    int len = sizeof(nums) / sizeof(nums[0]);

    int res = largestPerimeter(nums, len);

    printf("%d\n", res);

    return 0;
}