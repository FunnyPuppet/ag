#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxDistance(int** arrays, int arraysSize, int* arraysColSize) {
    int m = arraysSize;
    int ans = INT_MIN;
    int max = arrays[0][arraysColSize[0] - 1], min = arrays[0][0];

    for (int i = 1; i < m; i++) {
        int n = arraysColSize[i];

        int curMax = abs(arrays[i][n - 1] - min) > abs(max - arrays[i][0])? abs(arrays[i][n - 1] - min) : abs(max - arrays[i][0]);
        ans = ans > curMax ? ans : curMax;
        max = arrays[i][n - 1] > max ? arrays[i][n - 1] : max;
        min = arrays[i][0] < min ? arrays[i][0] : min;
    }

    return ans;
}

int main() {

    return 0;
}