#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    int *ans = malloc(sizeof(int) * numsSize);

    *returnSize = 0;

    for (int i = 0; i < numsSize; i++) {
        int index = abs(nums[i]) - 1;

        if (nums[index] < 0) {
            ans[*returnSize] = abs(nums[i]);
            (*returnSize)++;
        } else {
            nums[index] = -nums[index];
        }
    }

    return ans;
}

int main() {
    int nums[] = {4,3,2,7,8,2,3,1};
    int len = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int *res = findDuplicates(nums, len, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
    free(res);

    return 0;
}