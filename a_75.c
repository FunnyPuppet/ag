#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void sortColors(int* nums, int numsSize) {
    int r = 0, w = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            swap(&nums[i], &nums[r]);
            if (r < w) {
                swap(&nums[i], &nums[w]);
            }
            r++;
            w++;
        } else if (nums[i] == 1) {
            swap(nums + i, nums + w);
            w++;
        }
    }
}

int main() {
    int nums[] = {2,0,2,1,1,0};
    int len = sizeof(nums) / sizeof(nums[0]);
    sortColors(nums, len);

    for (int i = 0; i < len; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}

