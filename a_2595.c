#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int* evenOddBit(int n, int* returnSize) {
    int* arr = malloc(sizeof(int) * 2);
    int even = 0, odd = 0;
    int i = 0;
    while (n > 0) {
        if (n % 2 == 1) {
            if (i % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }
        n /= 2;
        i++;
    }
    *returnSize = 2;
    arr[0] = even;
    arr[1] = odd;

    return arr;
}

int main() {
    int returnSize;
    int *res = evenOddBit(50, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", res[i]);
    }

    free(res);

    return 0;
}