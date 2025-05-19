#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

bool dfs(const char *s, int pos, int tot, int target) {
    if (s[pos] == '\0') {
        return tot == target;
    }
    int sum = 0;
    for (int i = pos; s[i] != '\0'; i++) {
        sum = sum * 10 + s[i] - '0';
        if (sum + tot > target) {
            break;
        }
        if (dfs(s, i + 1, sum + tot, target)) {
            return true;
        }
    }
    return false;
}

int punishmentNumber(int n){
    int res = 0;
    char s[32];
    for (int i = 1; i <= n; i++) {
        sprintf(s, "%d", i * i);
        if (dfs(s, 0, 0, i)) {
            res += i * i;
        }
    }
    return res;
}

int main() {
    int res = punishmentNumber(37);
    printf("%d\n", res);

    return 0;
}