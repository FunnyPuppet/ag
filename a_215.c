#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

int findKthLargest(int* nums, int numsSize, int k) {
    int max = INT_MIN, min = INT_MAX;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > max) max = nums[i];
        if (nums[i] < min) min = nums[i];
    }

    int len = max - min + 1;
    int hash[len];
    for (int i = 0; i < len; i++) {
        hash[i] = 0;
    }

    for (int i = 0; i < numsSize; i++) {
        hash[nums[i] - min]++;
    }

    for (int i = len - 1; i >= 0; i--) {
        int cnt = hash[i];
        if (cnt > 0) {
            if (k == 0 || cnt >= k) {
                return i + min;
            }
            k -= cnt;
        }
    }

    return nums[0];
}

int main() {
    int nums[] = {3,2,1,5,6,4};
    int len = sizeof(nums) / sizeof(nums[0]);
    int res = findKthLargest(nums, len, 2);
    printf("%d\n", res);

    return 0;
}