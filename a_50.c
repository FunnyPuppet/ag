#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

double mul(double x, long long N) {
    if (N == 0) {
        return 1.0;
    }
    double y = mul(x, N / 2);

    return N % 2 == 0 ? y * y : y * y * x;
}

double myPow(double x, int n) {
    long long N = n;
    return N >= 0 ? mul(x, N) : 1.0 / mul(x, -N);
}

int main() {
    double res = myPow(2, -2);
    printf("%f\n", res);

    return 0;
}