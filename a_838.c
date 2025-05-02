#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

char* pushDominoes(char* dominoes) {
    int n = strlen(dominoes), i = 0;
    char left = 'L';
    while (i < n) {
        int j = i;

        while (j < n && dominoes[j] == '.') {
            j++;
        }
        char right = j < n ? dominoes[j] : 'R';
        if (left == right) {
            while (i < j) {
                dominoes[i++] = right;
            }
        } else if (left == 'R' && right == 'L') {
            int k = j - 1;
            while (i < k) {
                dominoes[i++] = 'R';
                dominoes[k--] = 'L';
            }
        }
        left = right;
        i = j + 1;
    }

    return dominoes;
}

int main() {
    char *str = ".L.R...LR..L..";
    char* res = pushDominoes(str);
    printf("%s\n", res);
    return 0;
}
