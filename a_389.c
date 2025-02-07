#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char findTheDifference(char* s, char* t) {
    int hash[26] = {0};

    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        hash[s[i] - 'a']++;
    }

    len = strlen(t);
    for (int i = 0; i < len; i++) {
        hash[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (hash[i] == -1) {
            return i + 'a';
        }
    }

    return 0;
}


int main() {
    char res = findTheDifference("abcd", "abcde");

    printf("%c\n", res);

    return 0;
}

