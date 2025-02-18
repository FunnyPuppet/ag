#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

char* convertToTitle(int columnNumber) {
    char tmp[50];
    int index = 0;

    while (columnNumber > 0) {
        int num = (columnNumber - 1) % 26;
        tmp[index++] = num + 'A';
        columnNumber = (columnNumber - 1) / 26;
    }

    char *ans = malloc(sizeof(char) * (index + 1));

    for (int i = 0; i < index; i++) {
        ans[i] = tmp[index - i - 1];
    }
    ans[index] = '\0';

    return ans;
}

int main() {
    char *res = convertToTitle(1);

    printf("%s\n", res);

    return 0;
}