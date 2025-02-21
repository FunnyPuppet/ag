#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int l = 0, r = numbersSize - 1;

    int* ans = malloc(sizeof(int) * 2);

    while (l < r) {
        if (numbers[l] + numbers[r] == target) {
            *returnSize = 2;
            ans[0] = l + 1;
            ans[1] = r + 1;
            return ans;
        }
        if (numbers[l] + numbers[r] > target) {
            r--;
        } else {
            l++;
        }
    }

    return ans;
}

int main() {
    int nums[] = {1, 2, 3, 6};
    int len = sizeof(nums) / sizeof(nums[0]);
    int target = 4;
    int returnSize;
    int *res = twoSum(nums, len, target, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", res[i]);
    }
    free(res);

    return 0;
}