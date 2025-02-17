#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define HASH_SIZE 128

int longestPalindrome(char* s) {
    int n = strlen(s);

    int hash[HASH_SIZE] = {0};
    for (int i = 0; i < n; i++) {
        hash[s[i]]++;
    }

    int ans = 0;
    int c = 0;
    for (int i = 0; i < HASH_SIZE; i++) {
        if (hash[i] % 2 == 1) {
            ans += hash[i] - 1;
            c = 1;
        } else {
            ans += hash[i];
        }
    }

    ans += c;

    return ans;
}

int main() {
    int res = longestPalindrome("dccaccd");
    printf("%d\n", res);

    return 0;
}