#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

typedef struct {
    int size;
    int *nums;
    int *tree;
} NumArray;

void buildTree(int* arr, int start, int end, int node, int* tree) {
    if (start == end) {
        tree[node] = arr[start];
        return;
    }

    int m = start + ((end - start) >> 1);

    buildTree(arr, start, m, node * 2 + 1, tree);
    buildTree(arr, m + 1, end, node * 2 + 2, tree);
    tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
}

NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *array = malloc(sizeof(NumArray));

    int *arr = malloc(sizeof(int) * (4 * numsSize));

    buildTree(nums, 0, numsSize - 1, 0, arr);

    array->size = numsSize;
    array->nums = nums;
    array->tree = arr;

    return array;
}

void update(int* arr, int start, int end, int node, int* tree, int idx, int val) {
    if (start == end) {
        arr[idx] = val;
        tree[node] = val;
        return;
    }

    int m = start + ((end - start) >> 1);

    if (idx <= m) {
        update(arr, start, m, node * 2 + 1, tree, idx, val);
    } else {
        update(arr, m + 1, end, node * 2 + 2, tree, idx, val);
    }

    tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
}

void numArrayUpdate(NumArray* obj, int index, int val) {
    update(obj->nums, 0, obj->size - 1, 0, obj->tree, index, val);
}

int query(int *tree, int start, int end, int L, int R, int node) {
    if (L <= start && R >= end) {
        return tree[node];
    }

    if (L > end || R < start) {
        return 0;
    }
    int m = start + ((end - start) >> 1);
    int leftSum = query(tree, start, m, L, R, 2 * node + 1);
    int rightSum = query(tree, m + 1, end, L, R, 2 * node + 2);
    return leftSum + rightSum;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    return query(obj->tree, 0, obj->size - 1, left, right, 0);
}

void numArrayFree(NumArray* obj) {
    free(obj->tree);
    free(obj);
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6};
    int len = sizeof(nums) / sizeof(nums[0]);

    NumArray *array = numArrayCreate(nums, len);



    free(array);

    return 0;
}