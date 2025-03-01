#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

int compareInt(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    int **ans = malloc(sizeof(int*) * 1001);
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * 1001);

    if (numsSize < 4) {
        return ans;
    }

    qsort(nums, numsSize, sizeof(int), compareInt);

    int len = numsSize;
    for (int a = 0; a < len - 3; a++) {
        if (a > 0 && nums[a] == nums[a - 1]) {
            continue;
        }
        for (int b = a + 1; b < len - 2; b++) {
            if (b > a + 1 && nums[b] == nums[b - 1]) {
                continue;
            }
            long num = (long) target - nums[a] - nums[b];

            int c = b + 1, d = len - 1;

            while (c < d) {
                if (nums[c] + nums[d] == num) {
                    int *arr = malloc(sizeof(int) * 4);

                    arr[0] = nums[a];
                    arr[1] = nums[b];
                    arr[2] = nums[c];
                    arr[3] = nums[d];
                    ans[*returnSize] = arr;
                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;
                    while (c < d && nums[c] == nums[c + 1]) {
                        c++;
                    }
                    while (c < d && nums[d] == nums[d - 1]) {
                        d--;
                    }
                    c++;
                    d--;
                } else if (nums[c] + nums[d] < num) {
                    c++;
                } else {
                    d--;
                }
            }
        }
    }

    return ans;
}

int main() {
    int nums[] = {2, 2, 2, 2, 2};
    int len = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int *returnColumnSizes;
    int target = 8;
    int **res = fourSum(nums, len, target, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
        free(res[i]);
    }
    free(res);

    return 0;
}