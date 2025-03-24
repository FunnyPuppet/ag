#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#include "list_node.h"

int countPrefixes(char** words, int wordsSize, char* s) {
    int ans = 0;

    for (int i = 0; i < wordsSize; i++) {
        char *word = words[i];
        int n = strlen(word), cnt = 0;

        for (int j = 0; j < n; j++) {
            if (word[j] == s[j]) {
                cnt++;
            } else {
                break;
            }
        }

        if (cnt == n) {
            ans++;
        }
    }

    return ans;
}

int main() {

    return 0;
}