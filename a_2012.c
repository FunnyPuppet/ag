#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int sumOfBeauties(int* nums, int numsSize) {
    int ans = 0;
    int lx = nums[0], rx = nums[numsSize - 1];
    int *ls = calloc(numsSize, sizeof(int));

    for (int i = 1; i < numsSize - 1; i++) {
        if (nums[i] > lx) {
            ls[i] = 1;
            lx = nums[i];
        }
    }

    for (int i = numsSize - 2; i > 0; i--) {
        if (ls[i] && nums[i] < rx) {
            ans += 2;
        } else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
            ans += 1;
        }
        rx = fmin(nums[i], rx);
    }
    free(ls);

    return ans;
}

int main() {
    int nums[] = {2, 2, 6};
    int len = sizeof(nums) / sizeof(nums[0]);
    int res = sumOfBeauties(nums, len);
    printf("%d\n", res);

    return 0;
}