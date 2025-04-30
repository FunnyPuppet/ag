#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int findNumbers(int* nums, int numsSize) {
    int ans = 0;

    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];

        int n = 0;
        while (num > 0) {
            n++;
            num /= 10;
        }

        if (n % 2 == 0) {
            ans++;
        }
    }

    return ans;
}

int main() {
    int nums[] = {1, 3, 2, 1};
    int len = sizeof(nums) / sizeof(nums[0]);
    int res = findNumbers(nums, len);

    printf("%d", res);

    return 0;
}
