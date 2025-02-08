#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


bool isAnagram(char* s, char* t) {
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
        if (hash[i] != 0) {
            return false;
        }
    }

    return true;
}


int main() {
    bool res = isAnagram("abcd", "cdab");

    printf("%d\n", res);

    return 0;
}

