#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int bases[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
const char* str[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

char* intToRoman(int num) {
    char* res = malloc(sizeof(char) * 20);
    res[0] = '\0';
    for(int i =0 ; i < 13; i++) {
        int base = bases[i];
        while (num >= base) {
            num -= base;
            strcat(res, str[i]);
        }
        if (num == 0) {
            break;
        }
    }

    return res;
}

int main(void) {
    char* res = intToRoman(3749);

    printf("%s\n", res);

    return EXIT_SUCCESS;
}
