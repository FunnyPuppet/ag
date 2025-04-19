#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int minOperations(int* nums, int numsSize, int k) {
    int sum = 0;

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }

    return sum % k;
}

int main() {

    return 0;
}