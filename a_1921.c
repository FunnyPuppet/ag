#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int eliminateMaximum(int* dist, int distSize, int* speed, int speedSize) {
    int arrive[distSize];
    for (int i = 0; i < distSize; i++) {
        int a = dist[i] / speed[i];
        if (dist[i] % speed[i] != 0) {
            a += 1;
        }
        arrive[i] = a;
    }

    qsort(arrive, distSize, sizeof(arrive[0]), compare);

    int count = 0;
    for (int i = 0; i < distSize; i++) {
        if (arrive[i] <= i) {
            break;
        }
        count++;
    }

    return count;
}

int main() {
    int dist[] = {3,5,7,4,5};
    int speed[] = {1, 1, 8, 1, 1};

    int count = eliminateMaximum(dist, 5, speed, 5);

    return 0;
}

