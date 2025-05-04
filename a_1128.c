#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize) {
    int nums[100] = {0};
    int ans = 0;

    for (int i = 0; i < dominoesSize; i++) {
        int num = dominoes[i][0] > dominoes[i][1] ? dominoes[i][0] * 10 + dominoes[i][1] : dominoes[i][1] * 10 + dominoes[i][0];
        ans += nums[num];
        nums[num]++;
    }

    return ans;
}

int main() {
    return 0;
}
