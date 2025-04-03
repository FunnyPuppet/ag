#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int compareVersion(char* version1, char* version2) {
    int m = strlen(version1), n = strlen(version2);

    int i = 0, j = 0;

    while (i < m || j < n) {
        long long x = 0;
        for (; i < m && version1[i] != '.'; i++) {
            x = x * 10 + version1[i] - '0';
        }
        i++;
        long long y = 0;
        for (; j < n && version2[j] != '.'; j++) {
            y = y * 10 + version2[j] - '0';
        }
        j++;
        if (x != y) {
            return x > y ? 1 : -1;
        }
    }

    return 0;
}

int main() {
    int res = compareVersion("1.0.1", "1");
    printf("%d\n", res);

    return 0;
}