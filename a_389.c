#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char findTheDifference(char* s, char* t) {
    int ans = 0;

    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        ans ^= s[i];
    }

    len = strlen(t);
    for (int i = 0; i < len; i++) {
        ans ^= t[i];
    }

    return ans;
}


int main() {
    char res = findTheDifference("abcd", "abcde");

    printf("%c\n", res);

    return 0;
}

