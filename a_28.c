#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strStr(char* haystack, char* needle) {
    int m = strlen(haystack);
    int n = strlen(needle);
    char t[n + 1];
    for (int i = 0; i <= m - n; i++) {
        strncpy(t, haystack + i, n);
        t[n] = '\0';

        if (strcmp(t, needle) == 0) {
            return i;
        }
    }

    return -1;
}

int main() {
    char* haystack = "sadbutsad", *needle = "sad";

    strStr(haystack, needle);

    return 0;
}

