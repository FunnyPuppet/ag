#include <stdio.h>

int majorityElement(int* nums, int numsSize) {
    int count = 0, me = -1;

    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];

        if (count == 0) {
            me = num;
        }

        if (me == num) {
            count++;
        } else {
            count--;
        }
    }

    return me;
}

int main() {
    int nums[] = {3, 2, 3};
    int len = sizeof(nums) / sizeof(nums[0]);

    int res = majorityElement(nums, len);

    printf("%d", res);

    return 0;
}
