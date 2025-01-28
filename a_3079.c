#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int encrypt(int num) {
    int max = 0,count = 0;
    while (num > 0) {
        int n = num % 10;
        max = max > n ? max : n;
        num /= 10;
        count++;
    }

    int res = 0;
    for (int i = 0; i < count; i++) {
        res = 10 * res + max;
    }
    return res;
}

int sumOfEncryptedInt(int* nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += encrypt(nums[i]);
    }

    return sum;
}

int main() {
    int nums[] = {3,51,734,0,5};
    int len = sizeof(nums) / sizeof(nums[0]);

    int count = sumOfEncryptedInt(nums, len);

    return 0;
}

