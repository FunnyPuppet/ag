#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int thirdMax(int* nums, int numsSize) {
    int min = INT_MAX;
    for (int i = 0; i < numsSize; i++) {
        min = nums[i] < min ? nums[i] : min;
    }

    int one = min, two = min, three = min;

    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];

        if (num > one) {
            three = two;
            two = one;
            one = num;
            count++;
        } else if (num > two && num < one) {
            three = two;
            two = num;
            count++;
        } else if (num > three && num < two) {
            three = num;
            count++;
        }
    }

    return count >= 2 ? three : one;
}

int main() {
    int nums[] = {1, -2147483648, 2};
    int len = sizeof(nums) / sizeof(nums[0]);
    int res = thirdMax(nums, len);

    printf("%d\n", res);


    return 0;
}

