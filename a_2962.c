#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>


long long countSubarrays(int* nums, int numsSize, int k) {
    int n = numsSize;

    int max = 0;

    for (int i = 0; i < n ; i++) {
        max = fmax(max, nums[i]);
    }

    int cnt[n + 1];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
        cnt[i + 1] = cnt[i] + (nums[i] == max ? 1 : 0);
    }

    long long ans = 0;
    for (int l = 0, r = 1; l < n; l++) {
        while (r < n && cnt[r] - cnt[l] < k) {
            r++;
        }

        if (cnt[r] - cnt[l] >= k) {
            ans += n - r + 1;
        }
    }

    return ans;
}

int main() {
    int arr[] = {28,5,58,91,24,91,53,9,48,85,16,70,91,91,47,91,61,4,54,61,49};
    int len = sizeof(arr) / sizeof(arr[0]);
    long long res = countSubarrays(arr, len, 1);
    printf("%lld", res);

    return 0;
}