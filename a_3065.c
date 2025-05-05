#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int minOperations(int* nums, int numsSize, int k) {
    int ans = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < k) {
            ans++;
        }
    }

    return ans;
}

int main() {
    return 0;
}
