#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int divide(int dividend, int divisor) {
    if(dividend == INT_MIN && divisor == -1) return INT_MAX;
    if(dividend == INT_MIN && divisor == 1) return INT_MIN;
    if(dividend > 0) return -divide(-dividend, divisor);
    if(divisor > 0) return -divide(dividend, -divisor);
    if(dividend > divisor) return 0;
    int res = 1, tmp = divisor;
    while((dividend - divisor) <= divisor)
    {
        res += res;
        divisor += divisor;
    }
    return res + divide(dividend - divisor, tmp);
}

int main() {
    int res = divide(8, 3);

    return 0;
}