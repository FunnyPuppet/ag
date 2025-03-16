#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include "list_node.h"


char* reorganizeString(char* s) {
    int n = strlen(s);
    int hash[26] = {0};

    int max = 0;
    for (int i = 0; i < n; i++) {
        hash[s[i] - 'a']++;
        max = fmax(max, hash[s[i] - 'a']);
    }

    if (max > (n + 1) / 2) {
        return "";
    }

    char *ans = malloc(sizeof(char) * (n + 1));
    int evenIdx = 0, oddIdx = 1;

    for (int i = 0; i < 26; i++) {
        char ch = i + 'a';

        while (hash[i] > 0 && hash[i] <= (n / 2) && oddIdx < n) {
            ans[oddIdx] = ch;
            hash[i]--;
            oddIdx += 2;
        }
        while (hash[i] > 0) {
            ans[evenIdx] = ch;
            hash[i]--;
            evenIdx += 2;
        }
    }

    ans[n] = '\0';
    return ans;
}

int main() {
    char* res = reorganizeString("vlvov");
    printf("%s\n", res);

    return 0;
}