#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

long long countSubarrays(int* nums, int numsSize, long long k) {
    int n = numsSize;
    long long prefix[n + 1];
    memset(prefix, 0, sizeof(prefix));

    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + nums[i];
    }

    long long ans = 0;
    for (int l = 0, r = 1; r <= n; r++) {
        while (l < r && (prefix[r] - prefix[l]) * (r - l) >= k) {
            l++;
        }
        ans += r - l;
    }

    return ans;
}

int main() {
    int arr[] = {1, 1, 1};
    int len = sizeof(arr) / sizeof(arr[0]);
    long long res = countSubarrays(arr, len, 5);
    printf("%lld", res);

    return 0;
}