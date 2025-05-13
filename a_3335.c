#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define MOD 1000000007

int lengthAfterTransformations(char* s, int t) {
    int hash[26] = {0};

    int n = strlen(s);

    for (int i = 0; i < n; i++) {
        hash[s[i] - 'a']++;
    }

    for (int i = 0; i < t; i++) {
        int cnt[26] = {0};
        cnt[0] = hash[25];
        cnt[1] = (hash[25] + hash[0]) % MOD;
        for (int j = 2; j < 26; j++) {
            cnt[j] = hash[j - 1];
        }

        memcpy(hash, cnt, sizeof(hash));
    }

    int ans = 0;

    for (int i = 0; i < 26; i++) {
        ans = (ans + hash[i]) % MOD;
    }

    return ans;
}

int main() {
    int res = lengthAfterTransformations("abcyy", 2);
    printf("%d\n", res);

    return 0;
}