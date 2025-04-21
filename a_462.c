#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int compareInt(const void* a, const void* b) {
    return *(int*)a -*(int*)b;
}

int minMoves2(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compareInt);

    int mid = nums[(numsSize + 1) / 2];
    int ans = 0;

    for (int i = 0; i < numsSize; i++) {
        ans += abs(mid - nums[i]);
    }

    return ans;
}

int main() {

    return 0;
}