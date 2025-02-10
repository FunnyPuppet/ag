#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    char ab[64], ba[64];
    strcpy(ab, *(const char **)a);
    strcat(ab, *(const char **)b);
    strcpy(ba, *(const char **)b);
    strcat(ba, *(const char **)a);
    return strcmp(ba, ab);
}

char* largestNumber(int* nums, int numsSize) {
    char **arr = malloc(sizeof(char*) * numsSize);

    for (int i = 0; i < numsSize; i++) {
        arr[i] = (char *)malloc(12 * sizeof(char));
        sprintf(arr[i], "%d", nums[i]);
    }

    qsort(arr, numsSize, sizeof(char*), compare);

    char *ans = malloc(sizeof(char) * 1200);
    strcpy(ans, arr[0]);
    if (strcmp(arr[0], "0") != 0) {
        for (int i = 1; i < numsSize; i++) {
            strcat(ans, arr[i]);
        }
    }

    for (int i = 0; i < numsSize; i++) {
        free(arr[i]);
    }
    free(arr);
    return ans;
}

int main() {
    int nums[] = {0, 0};
    int len = sizeof(nums) / sizeof(nums[0]);
    char* res = largestNumber(nums, len);

    printf("%s\n", res);
    free(res);

    return 0;
}