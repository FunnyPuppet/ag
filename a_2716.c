#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define HASH_SIZE 26

int minimizedStringLength(char* s) {
    int hash[HASH_SIZE] = {0};
    int n = strlen(s);

    for (int i = 0; i < n; i++) {
        hash[s[i] - 'a'] = 1;
    }

    int ans = 0;
    for (int i = 0; i < HASH_SIZE; i++) {
        if (hash[i] == 1) {
            ans++;
        }
    }

    return ans;
}

int main() {
    int res = minimizedStringLength("aababc");
    printf("%d", res);

    return 0;
}