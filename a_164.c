#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <tgmath.h>

int maximumGap(int* nums, int numsSize) {
    if (numsSize < 2) {
        return 0;
    }

    // 找到数组中的最小值和最大值
    int min = INT_MAX;
    int max = INT_MIN;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < min) {
            min = nums[i];
        }
        if (nums[i] > max) {
            max = nums[i];
        }
    }

    // 计算桶的数量和宽度
    int bucketCount = numsSize - 1;
    int bucketWidth = (max - min) / bucketCount + 1;

    // 初始化桶
    int* bucketMin = malloc(sizeof(int) * bucketCount);
    int* bucketMax = malloc(sizeof(int) * bucketCount);
    int* bucketFilled = malloc(sizeof(int) * bucketCount);
    for (int i = 0; i < bucketCount; i++) {
        bucketMin[i] = INT_MAX;
        bucketMax[i] = INT_MIN;
        bucketFilled[i] = 0;
    }

    // 将元素分配到桶中
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == min || nums[i] == max) {
            continue; // 跳过最小值和最大值
        }
        int index = (nums[i] - min) / bucketWidth;
        bucketMin[index] = nums[i] < bucketMin[index] ? nums[i] : bucketMin[index];
        bucketMax[index] = nums[i] > bucketMax[index] ? nums[i] : bucketMax[index];
        bucketFilled[index] = 1;
    }

    // 计算相邻桶之间的最大差值
    int prevMax = min;
    int maxGap = 0;
    for (int i = 0; i < bucketCount; i++) {
        if (bucketFilled[i]) {
            int gap = bucketMin[i] - prevMax;
            maxGap = (gap > maxGap) ? gap : maxGap;
            prevMax = bucketMax[i];
        }
    }

    // 处理最大值
    int gap = max - prevMax;
    maxGap = (gap > maxGap) ? gap : maxGap;

    // 释放内存
    free(bucketMin);
    free(bucketMax);
    free(bucketFilled);

    return maxGap;
}

int main() {
    int nums[] = {3, 6, 9, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = maximumGap(nums, numsSize);
    printf("%d\n", result);

    return 0;
}