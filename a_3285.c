#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int* stableMountains(int* height, int heightSize, int threshold, int* returnSize) {
    int *ans = malloc(sizeof(int) * (heightSize - 1));
    *returnSize = 0;
    for (int i = 1; i < heightSize; i++) {
        if (height[i - 1] > threshold) {
            ans[*returnSize] = i;
            (*returnSize)++;
        }
    }
    return ans;
}

int main() {
    int arr[] = {1,2,3,4,5};
    int len = sizeof(arr) / sizeof(arr[0]);
    int returnSize;
    int *res = stableMountains(arr, len, 2, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");

    free(res);

    return 0;
}