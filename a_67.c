#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char* addBinary(char* a, char* b) {
    int la = strlen(a), lb = strlen(b);

    int lm = la > lb ? la : lb;

    char *res = malloc((lm + 2) * sizeof(char));
    int r = 0;
    for (int i = 0; i < lm; i++) {
        int na = 0, nb = 0;
        if (la > 0) {
            na = a[--la] - '0';
        }
        if (lb > 0) {
            nb = b[--lb] - '0';
        }

        int n = na + nb + r;

        res[i] = n % 2 + '0';

        r = n / 2;
    }

    int sl = 0, sr;
    if (r == 1) {
        res[lm] = 1 + '0';
        res[lm + 1] = '\0';
        sr = lm;
    } else {
        res[lm] = '\0';
        sr = lm - 1;
    }

    while (sl < sr) {
        char temp = res[sl];
        res[sl] = res[sr];
        res[sr] = temp;
        sl++;
        sr--;
    }

    return res;
}

int main() {
    char *s = addBinary("101", "11");
    printf("%s", s);

    return 0;
}

