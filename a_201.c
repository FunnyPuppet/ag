#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>


int rangeBitwiseAnd(int left, int right) {
    int cnt = 0;

    while (left < right) {
        left >>= 1;
        right >>= 1;
        cnt++;
    }

    return left << cnt;
}

int main() {
    int left = 1, right = 2147483647;
    int res = rangeBitwiseAnd(left, right);

    printf("%d\n", res);

    return 0;
}