#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int bases[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
const char* romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

int romanToInt(char* s) {
    int pos = 0, res = 0;
    for(int i = 0; i < 13; i++) {
        const char* roman = romans[i];
        const int len = strlen(roman);

        while(s[pos] == roman[0] && (len == 2 ? s[pos+1] == roman[1] : 1)) {
            res += bases[i];
            pos += len;
        }
    }

    return res;
}

int main(void) {
    const int res = romanToInt("MLVIII");

    printf("%d\n", res);

    return EXIT_SUCCESS;
}
