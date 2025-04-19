#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int compareInt(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int maxCoins(int* piles, int pilesSize) {
    qsort(piles, pilesSize, sizeof(int), compareInt);
    int n = pilesSize;

    int k = n / 3;

    int ans = 0;
    for (int i = k; i < n; i += 2) {
        ans += piles[i];
    }

    return ans;
}

int main() {

    return 0;
}