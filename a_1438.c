#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int longestSubarray(int* nums, int numsSize, int limit) {
    int queMax[numsSize], queMin[numsSize];
    int leftMax = 0, rightMax = 0;
    int leftMin = 0, rightMin = 0;
    int left = 0, right = 0;
    int ans = 0;
    while (right < numsSize) {
        while (leftMax < rightMax && queMax[rightMax - 1] < nums[right]) {
            rightMax--;
        }
        while (leftMin < rightMin && queMin[rightMin - 1] > nums[right]) {
            rightMin--;
        }
        queMax[rightMax++] = nums[right];
        queMin[rightMin++] = nums[right];
        while (leftMax < rightMax && leftMin < rightMin && queMax[leftMax] - queMin[leftMin] > limit) {
            if (nums[left] == queMin[leftMin]) {
                leftMin++;
            }
            if (nums[left] == queMax[leftMax]) {
                leftMax++;
            }
            left++;
        }
        ans = fmax(ans, right - left + 1);
        right++;
    }
    return ans;
}

int main() {
    int cardPoints[] = {10,1,2,4,7,2};
    int len = sizeof(cardPoints) / sizeof(cardPoints[0]);
    int res = longestSubarray(cardPoints, len, 5);
    printf("%d\n", res);

    return 0;
}