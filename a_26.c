#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }

    int l = 0, r = 1;

    int k = 1;
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[l] < nums[r]) {
            nums[++l] = nums[r];
            k++;
        }
        r++;
    }

    return k;
}

// 主函数
int main() {
    int nums[] = {1, 1, 2};
    int len = sizeof(nums) / sizeof(nums[0]);

    int k = removeDuplicates(nums, len);

    for (int i = 0; i < len; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
