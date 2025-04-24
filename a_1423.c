#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int maxScore(int* cardPoints, int cardPointsSize, int k) {
    int n = cardPointsSize, len = n - k, min = 0, sum = 0, tmp = 0;

    for (int i = 0; i < n; i++) {
        sum += cardPoints[i];
    }

    for (int i = 0; i < n; i++) {
        if (i < len) {
            min += cardPoints[i];
            tmp = min;
        } else {
            tmp = tmp - cardPoints[i - len] + cardPoints[i];
            min = fmin(min, tmp);
        }
    }

    return sum - min;
}

int main() {
    int cardPoints[] = {1,2,3,4,5,6,1};
    int len = sizeof(cardPoints) / sizeof(cardPoints[0]);
    int res = maxScore(cardPoints, len, 3);
    printf("%d\n", res);

    return 0;
}