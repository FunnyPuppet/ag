#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int countSymmetricIntegers(int low, int high) {
    int ans = 0;

    for (int i = low; i <= high; i++) {
        if (i < 100 && i % 11 == 0) {
            ans++;
        } else if (i >= 1000 && i < 10000) {
            int l = i / 1000 + (i % 1000) / 100;
            int r = (i % 100) / 10 + i % 10;
            if (l == r) {
                ans++;
            }
        }
    }

    return ans;
}

int main() {
    int res = countSymmetricIntegers(1, 100);
    printf("%d\n", res);

    return 0;
}