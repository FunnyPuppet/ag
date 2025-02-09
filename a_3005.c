#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define HASH_SIZE 100

int maxFrequencyElements(int* nums, int numsSize) {
    int hash[HASH_SIZE] = {0};

    int max = 0;
    for (int i = 0; i < numsSize; i++) {
        hash[nums[i] - 1]++;

        int count = hash[nums[i] - 1];
        max = max > count ? max : count;
    }

    int ans = 0;
    for (int i = 0; i < HASH_SIZE; i++) {
        if (hash[i] == max) {
            ans += max;
        }
    }

    return ans;
}

int main() {
    int nums[] = {0,0,1,1,1,1,2,3,3};
    int len = sizeof(nums) / sizeof(nums[0]);
    int res = maxFrequencyElements(nums, len);

    printf("%d\n", res);

    return 0;
}