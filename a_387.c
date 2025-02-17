#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define HASH_SIZE 26

int firstUniqChar(char* s) {
    int n = strlen(s);

    int hash[HASH_SIZE] = {0};

    for (int i = 0; i < n; i++) {
        hash[s[i] - 'a']++;
    }

    for (int i = 0; i < n; i++) {
        if (hash[s[i] - 'a'] == 1) {
            return i;
        }
    }

    return -1;
}

int main() {
    int res = firstUniqChar("abb");
    printf("%d\n", res);

    return 0;
}