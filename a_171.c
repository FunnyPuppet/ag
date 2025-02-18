#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int titleToNumber(char* columnTitle) {
    int n = strlen(columnTitle);

    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans = ans * 26 + (columnTitle[i] - 'A' + 1);
    }

    return ans;
}

int main() {
    int res = titleToNumber("ZY");

    printf("%d\n", res);

    return 0;
}