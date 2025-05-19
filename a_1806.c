#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int reinitializePermutation(int n) {
    if (n == 2) {
        return 1;
    }
    int step = 1, pow2 = 2;
    while (pow2 != 1) {
        step++;
        pow2 = pow2 * 2 % (n - 1);
    }
    return step;
}

int main() {
    int res = reinitializePermutation(36);
    printf("%d\n", res);

    return 0;
}