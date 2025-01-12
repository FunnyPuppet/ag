#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool checkAlmostEquivalent(char* word1, char* word2) {
    int hash_o[26] = {0};
    int hash_t[26] = {0};

    for (int i = 0; i < strlen(word1); i++) {
        hash_o[word1[i] - 'a']++;
    }

    for (int i = 0; i < strlen(word2); i++) {
        hash_t[word2[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        int m = hash_o[i] - hash_t[i];
        if (m < -3 || m > 3) {
            return false;
        }
    }

    return true;
}

int main() {

    return 0;
}

