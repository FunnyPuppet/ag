#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

bool isBalanced(char* num) {
    int n = strlen(num);

    int sum = 0;

    for (int i = 0; i < n; i++) {
        int tn = num[i] - '0';

        if (i % 2 == 0) {
            sum += tn;
        } else {
            sum -= tn;
        }
    }

    return sum == 0;
}

int main() {
    bool res = isBalanced("01234");
    printf("%d\n", res);

    return 0;
}