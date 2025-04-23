#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int toInt(char *s, int l, int r) {
    int res = 0;
    for (; l < r; l++) {
        res = res * 10 + s[l] - '0';
    }
    return res;
}

int binary(char *s, int l, int x) {
    int r = l;
    for (; x; x >>= 1) {
        s[r++] = '0' + (x & 1);
    }
    for (int i = l, j = r - 1; i < j; i++, j--) {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
    return r;
}

char* convertDateToBinary(char* date) {
    int year = toInt(date, 0, 4);
    int month = toInt(date, 5, 7);
    int day = toInt(date, 8, 10);

    char *res = (char *)calloc(128, 1);
    int i = binary(res, 0, year);
    res[i++] = '-';
    i = binary(res, i, month);
    res[i++] = '-';
    i = binary(res, i, day);
    return res;
}

int main() {

    return 0;
}