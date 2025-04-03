#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int addDigits(int num) {
    if (num < 10) {
        return num;
    }

    int t = 0;

    while (num > 0) {
        t += num % 10;
        num /= 10;
    }

    return addDigits(t);
}

int main() {
    int res = addDigits(45);
    printf("%d\n", res);

    return 0;
}