#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int largestRectangleArea(int* heights, int heightsSize) {
    int *rs = malloc(sizeof(int) * heightsSize);
    int *ls = malloc(sizeof(int) * heightsSize);
    int *stack = malloc(sizeof(int) * heightsSize);

    int ans = 0, top = -1;

    for (int i = 0; i < heightsSize; i++) {
        rs[i] = -1;
    }
    for (int i = 0; i < heightsSize; i++) {
        ls[i] = -1;
    }

    for (int i = 0; i < heightsSize; i++) {
        while (top >= 0 && heights[stack[top]] > heights[i]) {
            rs[stack[top]] = i;
            top--;
        }
        stack[++top] = i;
    }

    top = -1;
    for (int i = heightsSize - 1; i >= 0; i--) {
        while (top >= 0 && heights[stack[top]] > heights[i]) {
            ls[stack[top]] = i;
            top--;
        }
        stack[++top] = i;
    }
    for (int i = 0; i < heightsSize; i++) {
        int l = ls[i], r = rs[i];
        if (r == -1) {
            r = heightsSize;
        }
        rs[i] = r - l - 1;
    }

    for (int i = 0; i < heightsSize; i++) {
        int area;
        if (rs[i] == -1) {
            area = heights[i] * (heightsSize - i);
        } else {
            area = heights[i] * rs[i];
        }
        ans = ans > area ? ans : area;
    }

    free(stack);
    free(rs);
    free(ls);
    return ans;
}

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize, n = matrixColSize[0];
    int tmp[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            tmp[i][j] = matrix[i][j] - '0';
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (tmp[i - 1][j] != 0 && tmp[i][j] != 0) {
                tmp[i][j] += tmp[i - 1][j];
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        int area = largestRectangleArea(tmp[i], n);
        ans = ans > area ? ans : area;
    }

    return ans;
}

int main() {
    int arr[] = {1, 0};
    int len = sizeof(arr) / sizeof(arr[0]);
    int res = largestRectangleArea(arr, len);
    printf("%d\n", res);

    return 0;
}