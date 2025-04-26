#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

long long countSubarrays(int* nums, int numsSize, int minK, int maxK) {
    int min = -1, max = -1, border = -1;

    long long ans = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < minK || nums[i] > maxK) {
            min = -1;
            max = -1;
            border = i;
        }

        if (nums[i] == minK) {
            min = i;
        }

        if (nums[i] == maxK) {
            max = i;
        }

        if (min != -1 && max != -1) {
            ans += fmin(min, max) - border;
        }
    }

    return ans;
}

int main() {
    int cardPoints[] = {8,8,8,1,3,5,2,7,5};
    int len = sizeof(cardPoints) / sizeof(cardPoints[0]);
    int returnSize;
    long long res = countSubarrays(cardPoints, len, 1, 5);
    printf("%lld\n", res);

    return 0;
}