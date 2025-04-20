#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define HASH_SIZE 1000

int numRabbits(int* answers, int answersSize) {
    int n = answersSize;
    int cnt[HASH_SIZE] = {0};

    for (int i = 0; i < n; i++) {
        cnt[answers[i]]++;
    }

    int ans = 0;
    ans += cnt[0];
    for (int i = 1; i < HASH_SIZE; i++) {
        if (cnt[i] > 0) {
            ans += (cnt[i] / (i + 1) + (cnt[i] % (i + 1) == 0 ? 0 : 1)) * (i + 1);
        }
    }

    return ans;
}

int main() {

    return 0;
}