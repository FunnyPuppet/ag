#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *res = malloc(sizeof(int) * (digitsSize + 1));

    int r = 0;
    for (int i = digitsSize - 1; i >= 0; i--) {
        int num = digits[i];
        int n = (i == digitsSize - 1 ? num + 1 : num) + r;

        res[i] = n % 10;

        r = n / 10;
    }

    if (r == 1) {
        res[0] = 1;
        res[digitsSize] = 0;
        *returnSize = digitsSize + 1;
    } else {
        *returnSize = digitsSize;
    }

    return res;
}

int main() {
    int nums[] = {1, 0, 9};
    int len = sizeof(nums) / sizeof(nums[0]);
    int returnSize = 0;

    int *k = plusOne(nums, len, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", k[i]);
    }

    free(k);

    return 0;
}
