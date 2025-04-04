#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>


int numOfSubarrays(int* arr, int arrSize, int k, int threshold) {
    int sum = 0, t = k * threshold;

    int ans = 0;
    for (int i = 0; i < arrSize; i++) {
        sum += arr[i];
        if (i >= k - 1) {
            if (sum >= t) {
                ans++;
            }
            sum -= arr[i - k + 1];
        }
    }

    return ans;
}

int main() {
    int nums[] = {2,2,2,2,5,5,5,8};
    int len = sizeof(nums) / sizeof(nums[0]);

    int res = numOfSubarrays(nums, len, 3, 4);
    printf("%d\n", res);

    return 0;
}