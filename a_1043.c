#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxSumAfterPartitioning(int* arr, int arrSize, int k) {
    int n = arrSize;
    int dp[arrSize + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++) {
        int maxVal = arr[i - 1];

        for (int j = i - 1; j >= 0 && j >= i - k; j--) {
            dp[i] = MAX(dp[i], dp[j] + maxVal * (i - j));

            if (j > 0) {
                maxVal = MAX(maxVal, arr[j - 1]);
            }
        }
    }

    return dp[n];
}

int main() {

    return 0;
}