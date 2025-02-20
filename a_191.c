#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int hammingWeight(int n) {
    int ans = 0;

    while(n > 0) {
        if (n & 1 == 1) {
            ans++;
        }
        n >>= 1;
    }

    return ans;
}

int main() {
    int res = hammingWeight(11);

    printf("%d ", res);

    return 0;
}