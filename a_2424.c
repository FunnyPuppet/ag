#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

typedef struct {
    int idx;
    int *arr;
} LUPrefix;


LUPrefix* lUPrefixCreate(int n) {
    LUPrefix *lup = malloc(sizeof(LUPrefix));
    lup->idx = 0;
    lup->arr = malloc(sizeof(int) * (n + 1));

    for (int i = 0; i <= n; i++) {
        lup->arr[i] = 0;
    }

    return lup;
}

void lUPrefixUpload(LUPrefix* obj, int video) {
    obj->arr[video - 1] = 1;
}

int lUPrefixLongest(LUPrefix* obj) {
    while (obj->arr[obj->idx] == 1) {
        obj->idx++;
    }

    return obj->idx;
}

void lUPrefixFree(LUPrefix* obj) {
    free(obj->arr);
    free(obj);
}

int main() {
    LUPrefix *p = lUPrefixCreate(4);

    lUPrefixUpload(p, 3);
    printf("%d\n", lUPrefixLongest(p));
    lUPrefixUpload(p, 1);
    printf("%d\n", lUPrefixLongest(p));
    lUPrefixUpload(p, 2);
    printf("%d\n", lUPrefixLongest(p));

    lUPrefixFree(p);

    return 0;
}