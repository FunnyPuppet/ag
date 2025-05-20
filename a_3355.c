#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

bool isZeroArray(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize) {
    int n = numsSize;
    int diff[n + 1];
    memset(diff, 0, sizeof(diff));

    for (int i = 0; i < queriesSize; i++) {
        diff[queries[i][0]]++;
        diff[queries[i][1] + 1]--;
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

int main() {

    return 0;
}