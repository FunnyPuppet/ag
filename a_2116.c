#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

bool canBeValid(char* s, char* locked) {
    int n = strlen(s);
    int mx = 0;
    int mn = 0;
    for (int i = 0; i < n; ++i) {
        if (locked[i] == '1') {
            int diff;
            if (s[i] == '(') {
                diff = 1;
            } else {
                diff = -1;
            }
            mx += diff;
            mn = fmax(mn + diff, (i + 1) % 2);
        } else {
            ++mx;
            mn = fmax(mn - 1, (i + 1) % 2);
        }
        if (mx < mn) {
            return false;
        }
    }

    return mn == 0;
}

int main() {
    bool res = canBeValid("((()))", "111111");
    printf("%d\n", res);

    return 0;
}