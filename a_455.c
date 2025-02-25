#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

int compareInt(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    qsort(g, gSize, sizeof(int), compareInt);
    qsort(s, sSize, sizeof(int), compareInt);

    int p = 0, q = 0, ans = 0;

    while (p < gSize && q < sSize) {
        if (g[p] <= s[q]) {
            q++;
            ans++;
        }
        p++;
    }

    return ans;
}

int main() {
    int g[] = {1, 2, 3};
    int gSize = sizeof(g) / sizeof(g[0]);
    int s[] = {1, 1};
    int sSize = sizeof(s) / sizeof(s[0]);
    int res = findContentChildren(g, gSize, s, sSize);

    printf("%d\n", res);

    return 0;
}