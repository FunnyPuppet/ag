#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int triangularSum(int* nums, int numsSize) {
    while (numsSize > 1) {
        for (int i = 0; i < numsSize - 1; i++) {
            nums[i] = (nums[i] + nums[i + 1]) % 10;
        }

        numsSize = numsSize - 1;
    }
    return nums[0];
}

int main() {
    return 0;
}
