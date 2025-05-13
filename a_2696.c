#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int minLength(char* s) {
    int n = strlen(s), top = -1;
    char stk[n];

    for (int i = 0; i < n; i++) {
        if (top >= 0 && ((s[i] == 'B' && stk[top] == 'A') || (s[i] == 'D' && stk[top] == 'C'))) {
            top--;
        } else {
            stk[++top] = s[i];
        }
    }

    return top + 1;
}

int main() {
    int res = minLength("ABFCACDB");
    printf("%d\n", res);

    return 0;
}