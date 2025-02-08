#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


bool canConstruct(char* ransomNote, char* magazine) {
    int hash[26] = {0};

    int len = strlen(magazine);

    for (int i = 0; i < len; i++) {
        hash[magazine[i] - 'a']++;
    }

    len = strlen(ransomNote);

    for (int i = 0; i < len; i++) {
        if (hash[ransomNote[i] - 'a'] == 0) {
            return false;
        }
        hash[ransomNote[i] - 'a']--;
    }

    return true;
}

int main() {

    return 0;
}