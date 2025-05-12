#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

char* removeStars(char* s) {
    int n = strlen(s), top = -1;

    char stk[n];

    for (int i = 0; i < n; i++) {
        if (top >= 0 && s[i] == '*') {
            top--;
        } else {
            stk[++top] = s[i];
        }
    }

    char *ans = malloc(sizeof(char) * (top + 2));
    for (int i = 0; i <= top; i++) {
        ans[i] = stk[i];
    }
    ans[top + 1] = '\0';

    return ans;
}

int main() {
    char *res = removeStars("leet**cod*e");
    printf("%s\n", res);
    free(res);

    return 0;
}