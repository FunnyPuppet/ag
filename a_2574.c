#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int* leftRightDifference(int* nums, int numsSize, int* returnSize) {
    int n = numsSize;
    int leftSum[n], rightSum[n];
    memset(leftSum, 0, sizeof(leftSum));
    memset(rightSum, 0, sizeof(rightSum));

    for (int i = 1; i < n; i++) {
        leftSum[i] = leftSum[i - 1] + nums[i - 1];
    }

    for (int i = n - 2; i >= 0; i--) {
        rightSum[i] = rightSum[i + 1] + nums[i + 1];
    }

    int *ans = malloc(sizeof(int) * n);
    *returnSize = n;
    for (int i = 0; i < n; i++) {
        ans[i] = abs(leftSum[i] - rightSum[i]);
    }

    return ans;
}

int main() {
    int cardPoints[] = {10,4,8,3};
    int len = sizeof(cardPoints) / sizeof(cardPoints[0]);
    int returnSize;
    int *res = leftRightDifference(cardPoints, len, &returnSize);
    free(res);

    return 0;
}