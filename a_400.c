#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int findNthDigit(int n) {
    if (n < 10)  return n;
    long long length = 0, cnt = 9, i = 1;
    while (length + cnt * i < n) {
        length += cnt * i;
        cnt *= 10;
        i++;
    }
    long long num = 1;
    for (int j = 1; j < i; j++) {
        num *= 10;
    }
    num += (n - length - 1) / i;
    long long index = (n - length - 1) % i;
    for (int j = 0; j < i - index - 1; j++) {
        num /= 10;
    }
    return num % 10;
}

int main() {
    int res = findNthDigit(401);
    printf("%d\n", res);

    return 0;
}