#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int twoEggDrop(int n) {
    int base = 1, ans = 0;

    while (n > 0) {
        n -= base++;
        ans++;
    }

    return ans;
}

int main() {

    return 0;
}