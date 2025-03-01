#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

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

int query(int *tree, int start, int end, int L, int R, int node) {
    // 如果查询区间完全在当前节点的区间内
    if (L <= start && R >= end) {
        return tree[node];
    }
    // 如果查询区间完全不在当前节点的区间内
    if (L > end || R < start) {
        return 0;  // 区间和的单位是 0
    }
    // 否则，查询左子树和右子树
    int m = start + ((end - start) >> 1);
    int leftSum = query(tree, start, m, L, R, 2 * node + 1);
    int rightSum = query(tree, m + 1, end, L, R, 2 * node + 2);
    return leftSum + rightSum;
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6};
    int len = sizeof(nums) / sizeof(nums[0]);
    int ts = len * 4;
    int *tree = malloc(sizeof(int) * ts);

    for (int i = 0; i < ts; i++) {
        tree[i] = 0;
    }

    buildTree(nums, 0, len - 1, 0, tree);

    update(nums, 0, len - 1, 0, tree, 1, 7);

    for (int i = 0; i < ts; i++) {
        printf("%d ", tree[i]);
    }
    printf("\n");

    int res = query(tree, 0, len - 1, 2, 4, 0);
    printf("%d\n", res);

    return 0;
}