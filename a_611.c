#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int compareInt(const void* a, const void* b) {
    return *(int*)a -*(int*)b;
}

int triangleNumber(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compareInt);

    int ans = 0;
    for (int i = numsSize - 1; i >= 2; i--) {
        int left = 0, right = i - 1;
        while (left < right) {
            if (nums[left] + nums[right] <= nums[i]) {
                left++;
            } else {
                ans += right - left;
                right--;
            }
        }
    }

    return ans;
}

int main() {

    return 0;
}