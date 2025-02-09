#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define HASH_SIZE 26

int findPermutationDifference(char* s, char* t) {
    int hash[HASH_SIZE] = {0};

    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        hash[s[i] - 'a'] += i;
        hash[t[i] - 'a'] -= i;
    }

    int ans = 0;
    for (int i = 0; i < HASH_SIZE; i++) {
        ans += abs(hash[i]);
    }

    return ans;
}

int main() {
    int res = findPermutationDifference("abc", "cba");

    printf("%d\n", res);

    return 0;
}