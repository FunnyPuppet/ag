#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int minOperations(int n) {
    int ans = 0;
    for (int i = 0; i < n / 2; i++) {
        ans += n - (2 * i + 1);
    }

    return ans;
}

int main() {
    int res = minOperations(6);

    return 0;
}