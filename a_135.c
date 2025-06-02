#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int candy(int* ratings, int ratingsSize) {
    int left[ratingsSize];

    for (int i = 0; i < ratingsSize; i++) {
        if (i > 0 && ratings[i] > ratings[i - 1]) {
            left[i] = left[i - 1] + 1;
        } else {
            left[i] = 1;
        }
    }

    int right = 0, ans = 0;
    for (int i = ratingsSize - 1; i >= 0; i--) {
        if (i < ratingsSize - 1 && ratings[i] > ratings[i + 1]) {
            right++;
        } else {
            right = 1;
        }
        ans += fmax(left[i], right);
    }

    return ans;
}

int main() {

    return 0;
}