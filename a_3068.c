#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

long long maximumValueSum(int* nums, int numsSize, int k, int** edges, int edgesSize, int* edgesColSize) {
    long long ans = 0;
    int diff[numsSize];

    for (int i = 0; i < numsSize; ++i) {
        ans += nums[i];
        diff[i] = (nums[i] ^ k) - nums[i];
    }

    qsort(diff, numsSize, sizeof(int), cmp);

    for (int i = numsSize - 1; i > 0 && diff[i] + diff[i - 1] >= 0; i -= 2) {
        ans += diff[i] + diff[i - 1];
    }

    return ans;
}

int main() {

    return 0;
}