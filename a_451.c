#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

#define HASH_SIZE 128

typedef struct {
    int index;
    int count;
} CN;

int compareCn(const void* a, const void* b) {
    return ((CN*)b)->count - ((CN*)a)->count;
}

char* frequencySort(char* s) {
    int n = strlen(s);

    int hash[HASH_SIZE] = {0};

    for (int i = 0; i < n; i++) {
        hash[s[i]]++;
    }

    CN cns[HASH_SIZE];
    for (int i = 0; i < HASH_SIZE; i++) {
        CN c = {i, hash[i]};
        cns[i] = c;
    }

    qsort(cns, HASH_SIZE, sizeof(CN), compareCn);

    char *ans = malloc(sizeof(char) * (n + 1));
    int idx = 0;
    for (int i = 0; i < HASH_SIZE; i++) {
        for (int j = 0; j < cns[i].count; j++) {
            ans[idx++] = cns[i].index;
        }
    }
    ans[n] = '\0';

    return ans;
}

int main() {
    char *res = frequencySort("tree");

    printf("%s\n", res);

    free(res);

    return 0;
}