#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool checkAlmostEquivalent(char* word1, char* word2) {
    int hash[26] = {0};

    for (int i = 0; i < strlen(word1); i++) {
        hash[word1[i] - 'a']++;
        hash[word2[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (hash[i] < -3 || hash[i] > 3) {
            return false;
        }
    }

    return true;
}

int main() {

    return 0;
}

