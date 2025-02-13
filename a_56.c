#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <tgmath.h>

typedef struct {
    int l;
    int r;
} Interval;

int comparePoint(const void* a, const void* b) {
    Interval* i_a = (Interval*)a;
    Interval* i_b = (Interval*)b;

    return i_a->l - i_b->l;
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    Interval *ti = malloc(sizeof(Interval) * intervalsSize);
    for (int i = 0; i < intervalsSize; i++) {
        ti[i].l = intervals[i][0];
        ti[i].r = intervals[i][1];
    }

    qsort(ti, intervalsSize, sizeof(Interval), comparePoint);

    int** result = malloc(sizeof(int*) * intervalsSize);
    *returnColumnSizes = malloc(sizeof(int) * intervalsSize);
    int index = 0;
    result[index] = malloc(sizeof(int) * 2);
    result[index][0] = ti[0].l;
    result[index][1] = ti[0].r;
    (*returnColumnSizes)[index] = 2;

    for (int i = 1; i < intervalsSize; i++) {
        if (result[index][1] >= ti[i].l) {
            result[index][1] = result[index][1] > ti[i].r ? result[index][1] : ti[i].r;
        } else {
            index++;
            result[index] = malloc(sizeof(int) * 2);
            result[index][0] = ti[i].l;
            result[index][1] = ti[i].r;
            (*returnColumnSizes)[index] = 2;
        }
    }

    *returnSize = index + 1;

    free(ti);

    return result;
}

int main() {
    int intervals[4][2] = {{1,3}, {2,6}, {15,18}, {8,10}};
    int len = sizeof(intervals) / sizeof(intervals[0]);
    int *arr[4];
    int *colSize = malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++) {
        arr[i] = intervals[i];
        colSize[i] = 2;
    }

    int returnSize;
    int *returnColumnSizes;
    int **res = merge(arr, len, 2, &returnSize, &returnColumnSizes);
    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d]\n", res[i][0], res[i][1]);
        free(res[i]);
    }
    free(res);
    free(returnColumnSizes);

    return 0;
}