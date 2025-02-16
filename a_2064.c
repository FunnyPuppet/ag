#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <tgmath.h>

#define HASH_SIZE 50000

int minimizedMaximum(int n, int* quantities, int quantitiesSize) {
    int l = 1, r = INT_MIN;
    for (int i = 0; i < quantitiesSize; i++) {
        r = quantities[i] > r ? quantities[i] : r;
    }

    int ans = r;
    while (l <= r) {
        int mid = l + (r - l) / 2;

        int count = 0;

        for (int i = 0; i < quantitiesSize; i++) {
            count += (quantities[i] + mid - 1) / mid;
        }
        if (count > n) {
            l = mid + 1;
        } else {
            ans = mid;
            r = mid - 1;
        }
    }

    return ans;
}

int main() {
    int nums[] = {10000};
    int len = sizeof(nums) / sizeof(nums[0]);

    int res = minimizedMaximum(1, nums, len);
    printf("%d\n", res);

    return 0;
}