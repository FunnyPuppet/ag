#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int removeElement(int* nums, int numsSize, int val) {
    if (numsSize == 0) {
        return 0;
    }

    int l = 0, r = 0;

    int k = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[r] != val) {
            nums[l++] = nums[r];
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

    int k = removeElement(nums, len, 1);

    for (int i = 0; i < len; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
