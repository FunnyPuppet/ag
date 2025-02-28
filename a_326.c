#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

bool isPowerOfThree(int n) {
    if (n <= 0) {
        return false;
    }

    while (n > 0) {
        if (n != 1 && n % 3 != 0) {
            return false;
        }
        n /= 3;
    }

    return true;
}

int main() {
    bool res = isPowerOfThree(9);
    printf("%d\n", res);

    return 0;
}