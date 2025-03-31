#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int percentageLetter(char* s, char letter) {
    int n = strlen(s);

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == letter) {
            cnt++;
        }
    }

    return cnt * 100 / n;
}

int main() {
    int res = percentageLetter("abbc", 'a');
    printf("%d\n", res);

    return 0;
}