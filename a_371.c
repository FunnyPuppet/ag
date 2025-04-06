#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int getSum(int a, int b) {
    while (b != 0) {
        unsigned int carry = (unsigned int) (a & b) << 1;
        a ^= b;
        b = carry;
    }

    return a;
}

int main() {
    int res = getSum(-2, -3);
    printf("%d\n", res);

    return 0;
}