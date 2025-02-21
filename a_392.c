#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

bool isSubsequence(char* s, char* t) {
    int ls = strlen(s), lt = strlen(t);
    if (ls == 0) return true;
    int p = 0, q = 0;

    while (p < ls && q < lt) {
        if (s[p] == t[q]) {
            p++;
        }
        q++;
    }

    return p == ls;
}

int main() {
    bool res = isSubsequence("abc", "adebc");
    printf("%d\n", res);

    return 0;
}