#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define HASH_SIZE 128

int numJewelsInStones(char* jewels, char* stones) {
    int hash[HASH_SIZE] = {0};

    for (int i = 0; i < strlen(jewels); i++) {
        hash[jewels[i]]++;
    }

    int ans = 0;

    for (int i = 0; i < strlen(stones); i++) {
        if (hash[stones[i]] > 0) {
            ans++;
        }
    }

    return ans;
}

int main() {
    int res = numJewelsInStones("aA", "aAAbbbb");
    printf("%d\n", res);

    return 0;
}