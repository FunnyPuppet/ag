#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int maxProfit(int* prices, int pricesSize) {
    int ans = 0;
    for (int i = 1; i < pricesSize; i++) {
        ans += fmax(0, prices[i] - prices[i - 1]);
    }

    return ans;
}

int main() {
    int prices[] = {1, 2, 3, 4, 5};
    int len = sizeof(prices) / sizeof(prices[0]);

    int res = maxProfit(prices, len);
    printf("%d\n", res);

    return 0;
}