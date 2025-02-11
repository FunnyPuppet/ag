#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <tgmath.h>

int* findMissingAndRepeatedValues(int** grid, int gridSize, int* gridColSize, int* returnSize) {
    int n = gridSize * gridSize;

    int* hash = calloc(n, sizeof(int));
    int* ans = malloc(sizeof(int) * 2);

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            int num = grid[i][j];

            if (hash[num - 1] == 1) {
                ans[0] = num;
            }
            hash[num - 1]++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (hash[i] == 0) {
            ans[1] = i + 1;
        }
    }
    *returnSize = 2;

    free(hash);
    return ans;
}

int main() {
    // 定义一个静态二维数组
    int nums[3][3] = {{9, 1, 7}, {8, 9, 2}, {3, 4, 6}};

    // 将静态二维数组转换为动态二维数组（int**）
    int* grid[3];
    for (int i = 0; i < 3; i++) {
        grid[i] = nums[i];  // 将每一行的指针赋值给 grid
    }

    int gridSize = 3;       // 行数
    int gridColSize[3] = {3, 3, 3};  // 每一行的列数
    int returnSize;         // 返回结果数组的大小

    // 调用函数
    int* res = findMissingAndRepeatedValues(grid, gridSize, gridColSize, &returnSize);

    // 释放结果数组的内存
    free(res);

    return 0;
}