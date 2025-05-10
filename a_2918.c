#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

long long minSum(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    long long oneSum = 0, twoSum = 0;
    int oneCnt = 0, twoCnt = 0;
    for (int i = 0; i < nums1Size; i++) {
        if (nums1[i] == 0) {
            oneCnt++;
        }
        oneSum += nums1[i];
    }

    for (int i = 0; i < nums2Size; i++) {
        if (nums2[i] == 0) {
            twoCnt++;
        }
        twoSum += nums2[i];
    }

    if ((oneSum + oneCnt > twoSum && twoCnt == 0) || (twoSum + twoCnt > oneSum && oneCnt == 0)) {
        return -1;
    }

    return oneSum + oneCnt >= twoSum + twoCnt ? oneSum + oneCnt : twoSum + twoCnt;
}

int main() {
    int nums1[] = {};
    int len1 = sizeof(nums1) / sizeof(nums1[0]);
    int nums2[] = {};
    int len2 = sizeof(nums2) / sizeof(nums2[0]);
    long long res = minSum(nums1, len1, nums2, len2);
    printf("%lld\n", res);

    return 0;
}