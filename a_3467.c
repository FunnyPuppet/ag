#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int* transformArray(int* nums, int numsSize, int* returnSize) {
    int cnt = 0, n = numsSize;

    for (int i = 0; i < n; i++) {
        cnt += (nums[i] & 1);
    }

    for (int i = n - 1; i >= 0; i--) {
        if (cnt-- > 0) {
            nums[i] = 1;
        } else {
            nums[i] = 0;
        }
    }

    *returnSize = n;
    return nums;
}

int main() {
    for (int i = 0; i <= 10; i++) {
        int res = i & 1;

        printf("%d ", res);
    }

    return 0;
}