#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int gk = 0;

int compare(const void* a, const void* b) {
    int* ua = *(int**)a;
    int* ub = *(int**)b;
    return ub[gk] - ua[gk];
}

int** sortTheStudents(int** score, int scoreSize, int* scoreColSize, int k, int* returnSize, int** returnColumnSizes) {
    gk = k;
    qsort(score, scoreSize, sizeof(int*), compare);
    *returnSize = scoreSize;
    *returnColumnSizes = scoreColSize;
    return score;
}

int main() {

    return 0;
}