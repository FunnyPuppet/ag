#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int countOfSubstrings(char* word, int k) {
    int ans = 0;
    int n = strlen(word);

    for (int i = 0; i < n; i++) {
        int num = k;
        int hash[26] = {0};
        for (int j = i; j < n; j++) {
            char ch = word[j];

            if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
                if (--num < 0) {
                    break;
                }
            } else {
                hash[ch - 'a']++;
            }

            if (hash[0] > 0 && hash[4] > 0 && hash[8] > 0 && hash[14] > 0 && hash[20] > 0 && num == 0) {
                ans++;
            }
        }

    }

    return ans;
}

int main() {
    int res = countOfSubstrings("aeiou", 0);
    printf("%d\n", res);

    return 0;
}