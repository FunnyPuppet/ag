#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int findTheWinner(int n, int k) {
    int p = 0;

    for (int i = 2; i <= n; i++) {
        p = (p + k) % i;
    }

    return p + 1;
}

int main() {

    return 0;
}