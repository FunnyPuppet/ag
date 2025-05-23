#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int countPartitions(int* nums, int numsSize) {
    int sum = 0;

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }

    int prefix = 0, ans = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        prefix += nums[i];

        if (abs(sum - 2 * prefix) % 2 == 0) {
            ans++;
        }
    }

    return ans;
}

int main() {

    return 0;
}