#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int* getSneakyNumbers(int* nums, int numsSize, int* returnSize) {
    int hash[numsSize];
    memset(hash, 0, sizeof(hash));

    int *ans = malloc(sizeof(int) * 2);
    *returnSize = 0;

    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        if (hash[num] > 0) {
            ans[*returnSize] = num;
            (*returnSize)++;
        }
        hash[num]++;
    }

    return ans;
}

int main() {
    int nums[] = {};
    int len = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int *res = getSneakyNumbers(nums, len, &returnSize);
    free(res);

    return 0;
}