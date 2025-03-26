#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int sum(int a, int n) {
    return a * n + n * (n - 1) / 2;
}

int minimumSum(int n, int k) {
    if (n <= k / 2) {
        return sum(1, n);
    }

    return sum(1, k / 2) + sum(k, n - k / 2);
}

int main() {
    int res = minimumSum(10, 8);
    printf("%d", res);

    return 0;
}