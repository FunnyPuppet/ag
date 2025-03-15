#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int scoreOfString(char* s) {
    int n = strlen(s);

    int ans = 0;

    for (int i = 1; i < n; i++) {
        ans += abs(s[i] - s[i - 1]);
    }

    return ans;
}

int main() {
    int res = scoreOfString("adadddad");
    printf("%d\n", res);

    return 0;
}