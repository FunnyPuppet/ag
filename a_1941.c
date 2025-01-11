#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool areOccurrencesEqual(char* s) {
    int len = strlen(s);

    int hash[26] = {0};

    for (int i = 0; i < len; i++) {
        char ch = s[i];

        int ac = ch - 'a';

        hash[ac]++;
    }

    int val = hash[s[0] - 'a'];
    for (int i = 0; i < 26; i++) {
        int num = hash[i];

        if (num != 0 && val != num) {
            return false;
        }
    }

    return true;
}

int main() {
    bool flag = areOccurrencesEqual("tveixwaeoezcf");

    printf("%d", flag);

    return 0;
}

