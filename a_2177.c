#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

long long* sumOfThree(long long num, int* returnSize) {
    long long *ans = malloc(sizeof(long long) * 3);
    *returnSize = 0;

    if (num % 3 != 0) {
        return ans;
    }

    *returnSize = 3;
    long long m = num / 3;
    ans[0] = m - 1;
    ans[1] = m;
    ans[2] = m + 1;

    return ans;
}

int main() {

    return 0;
}