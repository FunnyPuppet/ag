#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

bool check(int* nums, int numsSize, int** queries, int k) {
    int n = numsSize;
    int diff[n + 1];
    memset(diff, 0, sizeof(diff));

    for (int i = 0; i < k; i++) {
        diff[queries[i][0]] += queries[i][2];
        diff[queries[i][1] + 1] -= queries[i][2];
    }

    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += diff[i];
        if(nums[i] > sum) {
            return false;
        }
    }

    return true;
}

int minZeroArray(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize) {
    int l = 0, r = queriesSize;
    if (!check(nums, numsSize, queries, r)) {
        return -1;
    }
    while (l < r) {
        int k = (l + r) / 2;
        if (check(nums, numsSize, queries, k)) {
            r = k;
        } else {
            l = k + 1;
        }
    }
    return l;
}

int main() {

    return 0;
}