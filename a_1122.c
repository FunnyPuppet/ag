#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize) {
    int max = arr1[0], min = arr1[0];

    for (int i = 0; i < arr1Size; i++) {
        if (max < arr1[i]) max = arr1[i];
        if (min > arr1[i]) min = arr1[i];
    }

    int range = max - min + 1;

    int *count = calloc(range, sizeof(int));
    int *res = malloc(arr1Size * sizeof(int));
    for (int i = 0; i < arr1Size; i++) {
        count[arr1[i] - min]++;
    }

    *returnSize = 0;
    for (int i = 0; i < arr2Size; i++) {
        for (int j = 0; j < count[arr2[i] - min]; j++) {
            res[*returnSize] = arr2[i];
            (*returnSize)++;
        }
        count[arr2[i] - min] = 0;
    }

    for (int i = 0; i < range; i++) {
        for (int j = 0; j < count[i]; j++) {
            res[*returnSize] = i + min;
            (*returnSize)++;
        }
    }

    free(count);

    return res;
}

int main() {
    int arr1[] = {2,3,1,3,2,4,6,7,9,2,19};
    int arr1Size = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {2,1,4,3,9,6};
    int arr2Size = sizeof(arr2) / sizeof(arr2[0]);
    int returnSize;
    int *res = relativeSortArray(arr1, arr1Size, arr2, arr2Size, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");

    free(res);

    return 0;
}

