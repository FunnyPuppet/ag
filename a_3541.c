#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int maxFreqSum(char* s) {
    int n = strlen(s);

    int hash[26] = {0};

    for (int i = 0; i < n; i++) {
        hash[s[i] - 'a']++;
    }

    int p = 0, q = 0;

    for (int i = 0; i < 26; i++) {
        if (i == 0 || i == 4 || i == 8 || i == 14 || i == 20) {
            p = fmax(p, hash[i]);
        } else {
            q = fmax(q, hash[i]);
        }
    }

    return p + q;
}

int main() {
    int res = maxFreqSum("successes");

    return 0;
}