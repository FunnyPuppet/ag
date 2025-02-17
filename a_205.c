#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define HASH_SIZE 128

bool isIsomorphic(char* s, char* t) {
    if (strlen(s) != strlen(t)) {
        return false;
    }

    int hash_s[HASH_SIZE] = {0};
    int hash_t[HASH_SIZE] = {0};

    for (int i = 0; i < strlen(s); i++) {
        if (hash_s[s[i]] == 0 && hash_t[t[i]] == 0) {
            hash_s[s[i]] = t[i];
            hash_t[t[i]] = s[i];
        }

        if (hash_s[s[i]] != t[i] || hash_t[t[i]] != s[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    bool res = isIsomorphic("abb", "cdd");
    printf("%d\n", res);

    return 0;
}