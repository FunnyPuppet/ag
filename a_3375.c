#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int minOperations(int* nums, int numsSize, int k) {
    bool hash[101] = {false};

    int ans = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < k) {
            return -1;
        }
        if (nums[i] != k && !hash[nums[i]]) {
            ans++;
            hash[nums[i]] = true;
        }
    }

    return ans;
}

int main() {
    int nums[] = {5, 4, 2, 5, 5};
    int len = sizeof(nums) / sizeof(nums[0]);
    int res = minOperations(nums, len, 2);

    printf("%d\n", res);
    return 0;
}