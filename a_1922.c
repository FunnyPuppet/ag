#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define MOD 1000000007

typedef long long ll;

long long quickmul(int x, long long y) {
    long long ans = 1;
    long long mul = x;
    while (y > 0) {
        if (y % 2 == 1) {
            ans = (ans * mul) % MOD;
        }
        mul = (mul * mul) % MOD;
        y /= 2;
    }
    return ans;
}

int countGoodNumbers(long long n) {
    return (int)(quickmul(5, (n + 1) / 2) * quickmul(4, n / 2) % MOD);
}

int main() {

    return 0;
}