#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int n = temperaturesSize;
    int stk[n];
    int top = -1;

    int *ans = calloc(n, sizeof(int));
    *returnSize = n;
    for (int i = 0; i < n; i++) {
        while (top >= 0 && temperatures[i] > temperatures[stk[top]]) {
            ans[stk[top]] = i - stk[top];
            top--;
        }
        stk[++top] = i;
    }
    return ans;
}

int main() {
    int temperatures[] = {73,74,75,71,69,72,76,73};
    int len = sizeof(temperatures) / sizeof(temperatures[0]);
    int returnSize;
    int *res = dailyTemperatures(temperatures, len, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");

    free(res);
    return 0;
}