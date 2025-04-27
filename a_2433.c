#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int* findArray(int* pref, int prefSize, int* returnSize) {
    int *ans = malloc(sizeof(int) * prefSize);
    int tmp = 0;
    *returnSize = 0;
    for (int i = 0; i < prefSize; i++) {
        ans[(*returnSize)++] = tmp ^ pref[i];
        tmp = pref[i];
    }

    return ans;
}

int main() {
    int arr[] = {5, 2, 0, 3, 1};
    int len = sizeof(arr) / sizeof(arr[0]);
    int returnSize;
    int* res = findArray(arr, len, &returnSize);
    free(res);

    return 0;
}