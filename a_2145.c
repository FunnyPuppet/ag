#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int numberOfArrays(int* differences, int differencesSize, int lower, int upper) {
    int min = 0, max = 0, cur = 0;

    for (int i = 0; i < differencesSize; i++) {
        cur += differences[i];
        min = fmin(cur, min);
        max = fmax(cur, max);
        if (max - min > upper - lower) {
            return 0;
        }
    }
    return (upper - lower) - (max - min) + 1;
}

int main() {

    return 0;
}