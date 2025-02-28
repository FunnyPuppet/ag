#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

bool isPowerOfTwo(int n) {
    if (n <= 0) {
        return false;
    }

    int cnt = 0;
    while (n > 0) {
        if ((n & 1) == 1) {
            cnt++;
            if (cnt > 1) {
                return false;
            }
        }
        n >>= 1;
    }

    return true;
}

int main() {
    bool res = isPowerOfTwo(15);
    printf("%d\n", res);

    return 0;
}