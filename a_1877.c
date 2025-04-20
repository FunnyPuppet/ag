#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int compareInt(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int minPairSum(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compareInt);

    int l = 0, r = numsSize - 1;
    int ans = 0;
    while (l < r) {
        ans = fmax(ans, nums[l++] + nums[r--]);
    }

    return ans;
}

int main() {

    return 0;
}