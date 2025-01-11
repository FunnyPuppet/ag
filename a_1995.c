#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int countQuadruplets(int* nums, int numsSize) {
    int hash[101] = {0};

    int count = 0;
    for (int b = numsSize - 3; b >= 1; b--) {
        for (int d = b + 2; d < numsSize; d++) {
            if (nums[d] > nums[b + 1]) {
                hash[nums[d] - nums[b + 1]]++;
            }
        }

        for (int a = 0; a < b; a++) {
            if (nums[a] + nums[b] <= 100) {
                count += hash[nums[a] + nums[b]];
            }
        }
    }

    return count;
}

int main() {
    int nums[8] = {28, 8, 49, 85, 37, 90, 20, 8};
    int count = countQuadruplets(nums, 8);

    printf("%d ", count);

    return 0;
}

