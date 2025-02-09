#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define DUP_COUNT 2

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= DUP_COUNT) {
        return numsSize;
    }

    int j = DUP_COUNT;
    for (int i = DUP_COUNT; i < numsSize; i++) {
        if (nums[i] != nums[j - DUP_COUNT]) {
            nums[j] = nums[i];
            j++;
        }
    }
    return j;
}

int main() {
    int nums[] = {0,0,1,1,1,1,2,3,3};
    int len = sizeof(nums) / sizeof(nums[0]);
    int res = removeDuplicates(nums, len);

    for (int i = 0; i < res; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}