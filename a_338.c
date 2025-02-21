#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int* countBits(int n, int* returnSize) {
    int *ans = malloc(sizeof(int) * (n + 1));
    *returnSize = n + 1;
    if (n == 0) {
        ans[0] = 0;
        return ans;
    }
    ans[0] = 0, ans[1] = 1;
    if (n == 1) return ans;
    int factor = 2;
    for (int i = 2; i <= n; i++) {
        if ((i + 1) / 2 == factor) {
            ans[i] = ans[(i + 1) / 2 - 1] + 1;
            factor <<= 1;
        } else {
            ans[i] = ans[(i + 1) % factor - 1] + 1;
        }
    }

    return ans;
}

int main() {
    int nums[] = {7, 15, 31, 63};
    int len  = sizeof(nums) / sizeof(nums[0]);

    for (int j = 0; j < len; j++) {
        int returnSize;
        int *res = countBits(nums[j], &returnSize);

        for (int i = 0; i < returnSize; i++) {
            printf("%d ", res[i]);
        }
        printf("\n");

        free(res);
    }

    return 0;
}