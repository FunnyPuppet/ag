#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

bool threeConsecutiveOdds(int* arr, int arrSize) {
    for (int i = 0; i < arrSize - 2; i++) {
        if ((arr[i] & 1) && (arr[i + 1] & 1) && (arr[i + 2] & 1)) {
            return true;
        }
    }

    return false;
}

int main() {
    int arr[] = {1,2,34,3,4,5,7,23,12};
    int len = sizeof(arr) / sizeof(arr[0]);
    bool res = threeConsecutiveOdds(arr, len);
    printf("%d\n", res);

    return 0;
}