#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int compareInt(const void *a, const void *b) {
    int s_a = *(const int*)a;
    int s_b = *(const int*)b;
    return s_a - s_b;
}

int arrayPairSum(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compareInt);

    int sum = 0;

    for (int i = 0; i < numsSize; i += 2) {
        int a = nums[i];
        int b = nums[i + 1];

        sum += a > b ? b : a;
    }

    return sum;
}

int main() {
    int nums[] = {1, 3, 2, 1};
    int len = sizeof(nums) / sizeof(nums[0]);
    int res = arrayPairSum(nums, len);

    printf("%d", res);

    return 0;
}
