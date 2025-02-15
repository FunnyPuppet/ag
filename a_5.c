#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <tgmath.h>

char* longestPalindrome(char* s) {
    int len = strlen(s);

    if (len == 1) {
        return s;
    }

    int start = 0, max = 0;
    for (int i = 0; i < len; i++) {
        int l = i - 1;
        int r = i + 1;

        while (l >= 0 && s[l] == s[r]) {
            l--;
            r++;
        }
        if (r - l - 1 > max) {
            start = l + 1;
            max = r - l - 1;
        }

        l = i;
        r = i + 1;
        while (l >= 0 && s[l] == s[r]) {
            l--;
            r++;
        }
        if (r - l - 1 > max) {
            start = l + 1;
            max = r - l - 1;
        }
    }

    char *ans = malloc(sizeof(char) * (max + 1));
    strncpy(ans, s + start, max);
    ans[max] = '\0';

    return ans;
}

int main() {
    char *res = longestPalindrome("bbacc");
    printf("%s\n", res);

    return 0;
}