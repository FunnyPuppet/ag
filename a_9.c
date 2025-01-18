#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }

    long r = 0;

    int s = x;
    while (s > 0) {
        r = r * 10 + s % 10;
        s =  s / 10;
    }

    return r == x;
}

int main() {
    isPalindrome(121);

    return 0;
}

