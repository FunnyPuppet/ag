#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

char* triangleType(int* nums, int numsSize) {
    int a = nums[0], b = nums[1], c = nums[2];

    if (a + b <= c || a + c <= b || b + c <= a) {
        return "none";
    }

    if (a == b && b == c) {
        return "equilateral";
    }

    if (a == b || b == c || c == a) {
        return "isosceles";
    }

    return "scalene";
}

int main() {
    int nums[] = {5, 3, 8};
    int len = sizeof(nums) / sizeof(nums[0]);

    char *res = triangleType(nums, len);
    printf("%s\n", res);

    return 0;
}