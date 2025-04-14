#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int countGoodTriplets(int* arr, int arrSize, int a, int b, int c) {
    int ans = 0, max = 0;
    for (int i = 0; i < arrSize; i++) {
        max = fmax(max, arr[i]);
    }
    int n = max + 2;
    int s[n];
    memset(s, 0, sizeof(s));
    for (int j = 0; j < arrSize; j++) {
        for (int k = j + 1; k < arrSize; k++) {
            if (abs(arr[j] - arr[k]) > b) {
                continue;
            }
            int l = fmax(fmax(arr[j] - a, arr[k] - c), 0);
            int r = fmin(fmin(arr[j] + a, arr[k] + c), max);
            ans += fmax(s[r + 1] - s[l], 0);
        }
        for (int v = arr[j] + 1; v < n; v++) {
            s[v]++;
        }
    }

    return ans;
}

int main() {
    int nums[] = {3,0,1,1,9,7};
    int len = sizeof(nums) / sizeof(nums[0]);
    int res = countGoodTriplets(nums, len, 7, 2, 3);
    printf("%d\n", res);
    return 0;
}