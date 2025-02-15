#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <tgmath.h>

#define HASH_SIZE 50000

int findShortestSubArray(int* nums, int numsSize) {
    int hash[HASH_SIZE] = {0};
    int first[HASH_SIZE] = {0};

    for (int i = 0; i < HASH_SIZE; i++) {
        first[i] = -1;
    }

    int max = INT_MIN;
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        hash[num]++;
        int count = hash[num];
        max = max > count ? max : count;
        if (first[num] == -1) {
            first[num] = i;
        }
    }

    int last[HASH_SIZE] = {0};

    for (int i = 0; i < HASH_SIZE; i++) {
        last[i] = -1;
    }

    for (int i = numsSize - 1; i >= 0; i--) {
        int num = nums[i];
        if (last[num] == -1) {
            last[num] = i;
        }
    }

    int minDist = INT_MAX;
    for (int i = 0; i < HASH_SIZE; i++) {
        if (hash[i] == max) {
            int dist = last[i] - first[i] + 1;
            minDist = dist < minDist ? dist : minDist;
        }
    }

    return minDist;
}

int main() {
    int nums[] = {1, 2, 2, 3, 1};
    int len = sizeof(nums) / sizeof(nums[0]);

    int res = findShortestSubArray(nums, len);
    printf("%d\n", res);

    return 0;
}