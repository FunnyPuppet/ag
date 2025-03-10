#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int divisorSubstrings(int num, int k) {
    char str[20];
    sprintf(str, "%d", num);

    int n = strlen(str);
    int ans = 0;
    for (int i = 0; i <= n - k; i++) {
        char substr[k + 1];

        strncpy(substr, str + i, k);
        substr[k] = '\0';

        int tn = atoi(substr);
        if (tn != 0 && num % tn == 0) {
            ans++;
        }
    }

    return ans;
}

int main() {
    int res = divisorSubstrings(430043, 2);
    printf("%d\n", res);

    return 0;
}