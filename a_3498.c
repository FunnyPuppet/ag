#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int reverseDegree(char* s) {
    int n = strlen(s), ans = 0;

    for (int i = 0; i < n; i++) {
        ans += (26 - (s[i] - 'a')) * (i + 1);
    }

    return ans;
}

int main() {
    int res = reverseDegree("abc");
    printf("%d\n", res);

    return 0;
}