#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int minPartitions(char* n) {
    int len = strlen(n);

    int ans = 0;
    for (int i = 0; i < len; i++) {
        if (n[i] == '9') {
            return 9;
        }
        ans = fmax(ans, n[i] - '0');
    }

    return ans;
}

int main() {

    return 0;
}