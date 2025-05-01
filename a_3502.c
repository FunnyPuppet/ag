#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int* minCosts(int* cost, int costSize, int* returnSize) {
    int n = costSize;

    int *ans = malloc(sizeof(int) * n);
    *returnSize = n;
    int min = cost[0];

    for (int i = 0; i < n; i++) {
        min = fmin(min, cost[i]);
        ans[i] = min;
    }

    return ans;
}

int main() {
    int arr[] = {5,3,4,1,3,2};
    int len = sizeof(arr) / sizeof(arr[0]);
    int returnSize;
    int* res = minCosts(arr, len, &returnSize);
    free(res);
    return 0;
}
