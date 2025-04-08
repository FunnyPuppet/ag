#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int minimumOperations(int* nums, int numsSize) {
    bool hash[101] = {false};

    for (int i = numsSize - 1; i >= 0; i--) {
        if (hash[nums[i]]) {
            return i / 3 + 1;
        }
        hash[nums[i]] = true;
    }

    return 0;
}

int main() {
    int nums[] = {3, 10, 5, 25, 2, 8};
    int len = sizeof(nums) / sizeof(nums[0]);
    int res = minimumOperations(nums, len);
    printf("%d\n", res);

    return 0;
}