#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLastWord(char* s) {
    int i = strlen(s) - 1;

    while (i >= 0 && s[i] == ' ') i--;

    int len = 0;
    while (i >= 0 && s[i] != ' ') {
        len++;
        i--;
    }
    return len;
}

int main() {
    int res = lengthOfLastWord("   fly me   to   the moon  ");
    printf("%d\n", res);

    return 0;
}