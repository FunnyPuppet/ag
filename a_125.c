#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool validCode(char c) {
    if (c == '\0') {
        return false;
    }
    if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
        return false;
    }

    return true;
}

bool isPalindrome(char* s) {
    int n = strlen(s);
    int l = 0, r = n - 1;

    while (l < r) {
        while (l < r && validCode(s[l])) {
            l++;
        }
        while (l < r && validCode(s[r])) {
            r--;
        }
        if (l < r) {
            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            l++;
            r--;
        }
    }

    return true;
}

int main() {
    bool res = isPalindrome(".,");
    printf("%d\n", res);

    return 0;
}