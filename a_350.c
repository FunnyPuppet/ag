#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 1001

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int map[HASH_SIZE] = {0};
    int ans[HASH_SIZE] = {0};

    int num;
    for(int i = 0; i < nums1Size; i++) {
        num = nums1[i];
        map[num] = ++map[num];
    }

    *returnSize = 0;
    for(int i = 0; i < nums2Size; i++) {
        num = nums2[i];
        if (map[num] > 0) {
            map[num] == --map[num];
            ans[(*returnSize)++] = num;
        }
    }

    int *res = malloc(sizeof(int) * *returnSize);
    for (int i = 0; i < *returnSize; i++) {
        res[i] = ans[i];
    }

    return res;
}

int main(void) {
    int nums1[] = {4, 9, 5};
    int nums2[] = {9, 4, 9, 8, 4};

    int returnSize = 0;

    int *res = intersect(nums1, 3, nums2, 5, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("Result is: %d\n", res[i]);
    }

    free(res);

    return EXIT_SUCCESS;
}
