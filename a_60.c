#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int factorial(int n) {
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans *= i;
    }
    return ans;
}

void process(char *ans, int n, int k, int index, int max, int* used) {
    if (index == max) {
        return;
    }
    int f = factorial(n - 1);

    int idx = k / f;

    for (int i = 1; i <= max; i++) {
        if (used[i] == 0) {
            if (idx == 0) {
                ans[index] = i + '0';
                used[i] = 1;
                break;
            }
            idx--;
        }
    }

    process(ans, n - 1, k % f, index + 1, max, used);
}

char* getPermutation(int n, int k) {
    char *ans = malloc(sizeof(char) * (n + 1));
    int *used = malloc(sizeof(int) * (n + 1));

    for (int i = 0; i <= n; i++) {
        used[i] = 0;
    }

    process(ans, n, k - 1, 0, n, used);

    ans[n] = '\0';
    return ans;
}

int main() {
    char *res = getPermutation(4, 10);

    printf("%s\n", res);
    return 0;
}