#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int trap(int* height, int heightSize) {
    int l = 0, r = heightSize - 1;
    int lm = height[l], rm = height[r];
    int sum = 0;

    while (l < r) {
        lm = lm > height[l] ? lm : height[l];
        rm = rm > height[r] ? rm : height[r];

        if (height[l] < height[r]) {
            sum += lm - height[l];
            l++;
        } else {
            sum += rm - height[r];
            r--;
        }
    }

    return sum;
}

int main() {
    int nums[] = {0, 7, 1, 4, 6};
    int size = sizeof(nums) / sizeof(nums[0]);

    int res = trap(nums, size);
    printf("%d", res);

    return 0;
}

