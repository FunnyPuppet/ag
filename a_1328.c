#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

char* breakPalindrome(char* palindrome) {
    int len = strlen(palindrome);
    if (len <= 1) {
        palindrome[0] = '\0';
        return palindrome;
    }

    char *ans = malloc(sizeof(char) * (len + 1));
    bool flag = true;
    for (int i = 0; i < len; i++) {
        if (i < (len >> 1) && palindrome[i] != 'a' && flag) {
            ans[i] = 'a';
            flag = false;
        } else {
            ans[i] = palindrome[i];
        }
    }

    if (flag) {
        ans[len - 1] = 'b';
    }
    ans[len] = '\0';

    return ans;
}

int main() {
    char *res = breakPalindrome("aba");

    printf("%s\n", res);
    free(res);

    return 0;
}