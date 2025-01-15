#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int maxArea(int* height, int heightSize) {
    int l = 0, r = heightSize - 1;
    int max = 0;

    while (l < r) {
        int hl = height[l];
        int hr = height[r];
        int num = (r - l) * (hl <= hr ? hl : hr);
        max = num > max ? num : max;
        if (hl <= hr) {
            l++;
        } else {
            r--;
        }
    }

    return max;
}

int main() {
    int nums[] = {1,8,6,2,5,4,8,3,7};
    int len = sizeof(nums) / sizeof(nums[0]);
    int returnSize = 0;

    int k = maxArea(nums, len);

    printf("%d", k);

    return 0;
}
