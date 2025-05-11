#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int* findThePrefixCommonArray(int* A, int ASize, int* B, int BSize, int* returnSize) {
    int n = ASize;
    int hash[n + 1];
    memset(hash, 0, sizeof(hash));

    int *ans = malloc(sizeof(int) * n);
    *returnSize = n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (++hash[A[i]] == 2) {
            cnt++;
        }
        if (++hash[B[i]] == 2) {
            cnt++;
        }

        ans[i] = cnt;
    }

    return ans;
}

int main() {

    return 0;
}