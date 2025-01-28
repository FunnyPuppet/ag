#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minimumChairs(char* s) {
    int len = strlen(s);

    int max = 0, y = 0;

    for (int i = 0; i < len; i++) {
        char ch = s[i];
        if (ch == 'E') {
            y++;
        }
        if (ch == 'L') {
            y--;
        }
        max = max > y ? max : y;
    }

    return max;
}

int main() {
    int count = minimumChairs("EEEE");

    return 0;
}

