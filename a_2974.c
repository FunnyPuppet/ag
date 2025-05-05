#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int compareInt(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int* numberGame(int* nums, int numsSize, int* returnSize) {
    int n = numsSize;
    qsort(nums, numsSize, sizeof(int), compareInt);

    int *ans = malloc(sizeof(int) * n);
    *returnSize = n;
    for (int i = 1; i < n; i += 2) {
        ans[i - 1] = nums[i];
        ans[i] = nums[i - 1];
    }

    return ans;
}

int main() {
    return 0;
}
