#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int differenceOfSums(int n, int m) {
    int num1 = 0, num2 = 0;

    for (int i = 1; i <= n; i++) {
        if (i % m == 0) {
            num2 += i;
        } else {
            num1 += i;
        }
    }

    return num1 - num2;
}

int main() {
    int res = differenceOfSums(10, 3);
    printf("%d\n", res);

    return 0;
}