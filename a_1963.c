#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int minSwaps(char* s) {
    int n = strlen(s);

    int count = 0, minCount = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '[') {
            count++;
        } else {
            count--;
        }
        if (count < minCount) {
            minCount = count;
        }
    }
    return (-minCount + 1) >> 1;
}

int main() {
    int res = minSwaps("]]][[[");

    printf("%d\n", res);
    return 0;
}