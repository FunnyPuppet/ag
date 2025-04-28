#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
int minOperations(int* nums, int numsSize, int k) {
    for (int i = 0; i < numsSize; i++) {
        k ^= nums[i];
    }
    int ans = 0;

    while (k > 0) {
        ans += k & 1;
        k >>= 1;
    }

    return ans;
}

int main() {
    int arr[] = {2, 1, 3, 4};
    int len = sizeof(arr) / sizeof(arr[0]);
    int res = minOperations(arr, len, 1);
    printf("%d", res);

    return 0;
}