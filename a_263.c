#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

bool isUgly(int n) {
    if (n <= 0) {
        return false;
    }

    int arr[] = {2, 3, 5};
    for (int i = 0; i < 3; i++) {
        while (n % arr[i] == 0) {
            n /= arr[i];
        }
    }

    return n == 1;
}

int main() {
    bool res = isUgly(6);
    printf("%d\n", res);

    return 0;
}