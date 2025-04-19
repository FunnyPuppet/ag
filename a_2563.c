#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int compareInt(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int lower_bound(int* arr, int size, int target) {
    int left = 0, right = size;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target){
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

long long countFairPairs(int* nums, int numsSize, int lower, int upper) {
    qsort(nums, numsSize, sizeof(int), compareInt);
    long long ans = 0;

    for (int j = 0; j < numsSize; j++) {
        int r = lower_bound(nums, j, upper - nums[j] + 1);
        int l = lower_bound(nums, j, lower - nums[j]);
        ans += (r - l);
    }

    return ans;
}

int main() {

    return 0;
}