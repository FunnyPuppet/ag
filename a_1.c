#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize);

int main(int argc, char *argv[]) {
    int nums[] = {2, 5, 7, 9};

    int size = sizeof(nums) / sizeof(nums[0]);

    int returnSize = 0;

    int *res = twoSum(nums, size, 11, &returnSize);

    if (res != NULL) {
        printf("Num is [%d] and [%d]; returnSize is %d\n", res[0], res[1], returnSize);
	free(res);
    } else {
        printf("Not Found\n");
    }

    return EXIT_SUCCESS;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                int *res_arr = malloc(sizeof(int) * 2);
                res_arr[0] = i;
                res_arr[1] = j;
                *returnSize = 2;
                return res_arr;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}
