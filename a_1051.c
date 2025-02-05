#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int heightChecker(int* heights, int heightsSize) {
    // 找到数组中的最大值和最小值
    int max = heights[0], min = heights[0];
    for (int i = 1; i < heightsSize; i++) {
        if (heights[i] > max) max = heights[i];
        if (heights[i] < min) min = heights[i];
    }

    // 计算计数数组的大小
    int range = max - min + 1;
    int* count = calloc(range, sizeof(int));
    int* output = malloc(heightsSize * sizeof(int));

    // 统计每个元素的出现次数
    for (int i = 0; i < heightsSize; i++) {
        count[heights[i] - min]++;
    }

    // 计算累加计数
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // 构建排序后的数组
    for (int i = heightsSize - 1; i >= 0; i--) {
        output[count[heights[i] - min] - 1] = heights[i];
        count[heights[i] - min]--;
    }

    // 计算与原数组不同的元素个数
    int diff = 0;
    for (int i = 0; i < heightsSize; i++) {
        if (output[i] != heights[i]) diff++;
    }
    free(count);
    free(output);
    return diff;
}

int main() {
    int nums[] = {9,1,2,3,4};
    int len = sizeof(nums) / sizeof(nums[0]);
    int max = heightChecker(nums, len);

    printf("%d\n", max);

    for (int i = 0; i < len; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}

