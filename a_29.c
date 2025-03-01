#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

int divide(int dividend, int divisor) {
    if (divisor == 0) {
        return INT_MAX;
    }
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }

    bool negative = ((dividend < 0) ^ (divisor < 0)) == 1;

    long long ldividend = dividend;

    if (ldividend < 0) {
        ldividend = -ldividend;
    }
    long long ldivisor = divisor;
    if (ldivisor < 0) {
        ldivisor = -ldivisor;
    }

    int ans = 0;

    for (int i = 31; i >= 0; i--) {
        if ((ldividend >> i) >= ldivisor) {
            ans += 1 << i;
            ldividend -= ldivisor << i;
        }
    }

    return negative ? -ans : ans;
}

int main() {
    int res = divide(-2147483648, 1);
    printf("%d\n", res);

    return 0;
}