#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int pick;

int guess(int num) {
    if (num > pick) {
        return -1;
    }
    if (num < pick) {
        return 1;
    }
    return 0;
}

int guessNumber(int n){
    int min = 1, max = n;

    while (min < max) {
        int mid = min + (max - min) / 2;

        if (guess(mid) == 0) {
            return mid;
        } else if (guess(mid) == 1) {
            min = mid + 1;
        } else {
            max = mid - 1;
        }
    }

    return 0;
}

int main() {
    pick = 6;

    int res = guessNumber(10);

    printf("%d", res);

    return 0;
}
