#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

long long distributeCandies(int n, int limit) {
    long long ans = 0;

    for (int i = 0; i <= fmin(n, limit); i++) {
        if (n - i > 2 * limit) {
            continue;
        }
        ans += fmin(n - i, limit) - fmax(0, n - i - limit) + 1;
    }

    return ans;
}

int main() {

    return 0;
}