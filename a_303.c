#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

typedef struct {
    int size;
    int *arr;
    int *prefix;
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *array = malloc(sizeof(NumArray));

    int *prefix = malloc(sizeof(int) * numsSize);
    prefix[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        prefix[i] = prefix[i - 1] + nums[i];
    }
    array->prefix = prefix;
    array->arr = nums;
    array->size = numsSize;

    return array;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    if (left >= obj->size || right < 0) {
        return 0;
    }

    if (left < 0) {
        left = 0;
    }

    if (right >= obj->size) {
        right = obj->size - 1;
    }

    return obj->prefix[right] - obj->prefix[left] + obj->arr[left];
}

void numArrayFree(NumArray* obj) {
    free(obj->prefix);
    free(obj);
}

int main() {
    int nums[] = {1, 4, 6, 7};
    int len = sizeof(nums) / sizeof(nums[0]);

    NumArray *arr = numArrayCreate(nums, len);
    int res = numArraySumRange(arr, 0, 5);

    printf("%d\n", res);

    numArrayFree(arr);

    return 0;
}