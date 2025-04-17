#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int countPairs(int* nums, int numsSize, int k) {
    int n = numsSize;

    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[j] == nums[i] && (i * j) % k == 0) {
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    int nums[] = {3,1,2,2,2,1,3};
    int len  = sizeof(nums) / sizeof(nums[0]);
    bool res = countPairs(nums, len, 2);
    printf("%d\n", res);

    return 0;
}