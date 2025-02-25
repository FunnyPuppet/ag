#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

int compareInt(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}

int matchPlayersAndTrainers(int* players, int playersSize, int* trainers, int trainersSize) {
    qsort(players, playersSize, sizeof(int), compareInt);
    qsort(trainers, trainersSize, sizeof(int), compareInt);

    int p = 0, q = 0, ans = 0;

    while (p < playersSize && q < trainersSize) {
        if (players[p] <= trainers[q]) {
            q++;
            ans++;
        }
        p++;
    }

    return ans;
}

int main() {

    return 0;
}