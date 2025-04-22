#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int compareInt(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int maxSatisfaction(int* satisfaction, int satisfactionSize) {
    int n = satisfactionSize;
    qsort(satisfaction, n, sizeof(int), compareInt);

    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i - 1][j - 1] + satisfaction[i - 1] * j;
            if (j < i) {
                dp[i][j] = fmax(dp[i - 1][j], dp[i][j]);
            }
            ans = fmax(ans, dp[i][j]);
        }
    }
    return ans;
}

int main() {
    int arr[] = {-1, 0, -8, -9, 5};
    int len = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", maxSatisfaction(arr, len));

    return 0;
}