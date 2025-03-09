#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#include "list_node.h"

int compareItem(const void* a, const void* b) {
    int *A = *(int**)a;
    int *B  = *(int**)b;
    if (A[0] == B[0]) {
        return A[1] - B[1];
    }
    return A[0] - B[0];
}

int query(int** items, int itemsSize, int q) {
    int l = 0, r = itemsSize;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (items[mid][0] <= q) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    if (l == 0) {
        return 0;
    }

    return  items[l - 1][1];
}

int* maximumBeauty(int** items, int itemsSize, int* itemsColSize, int* queries, int queriesSize, int* returnSize) {
    qsort(items, itemsSize, sizeof(int*), compareItem);

    int max = items[0][1];
    for (int i = 0; i < itemsSize; i++) {
        if (items[i][1] > max) {
            max = items[i][1];
        } else {
            items[i][1] = max;
        }
    }

    int *ans = malloc(sizeof(int) * queriesSize);
    for (int i = 0; i < queriesSize; i++) {
        ans[i] = query(items, itemsSize, queries[i]);
    }
    *returnSize = queriesSize;

    return ans;
}

int main() {
    int m = 20, n = 2;
    int *cols = malloc(sizeof(int) * m);
    int items[20][2] = {{193,732},{781,962},{864,954},{749,627},{136,746},{478,548},{640,908},{210,799},{567,715},{914,388},{487,853},{533,554},{247,919},{958,150},{193,523},{176,656},{395,469},{763,821},{542,946},{701,676}};
    int *arr[m];
    for (int i = 0; i < m; i++) {
        arr[i] = items[i];
        cols[i] = n;
    }
    int queries[] = {885,1445,1580,1309,205,1788,1214,1404,572,1170,989,265,153,151,1479,1180,875,276,1584};
    int queriesSize = sizeof(queries) / sizeof(queries[0]);
    int returnSize;
    int * res = maximumBeauty(arr, m, cols, queries, queriesSize, &returnSize);

    free(res);
    free(cols);
    return 0;
}