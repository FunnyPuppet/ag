#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

char** getLongestSubsequence(char** words, int wordsSize, int* groups, int groupsSize, int* returnSize) {
    int n = wordsSize;
    char **ans = malloc(sizeof(char*) * n);
    *returnSize = 0;

    for (int i = 0; i < n; i++) {
        if (i == 0 || groups[i] != groups[i - 1]) {
            ans[*returnSize] = words[i];
            (*returnSize)++;
        }
    }

    return ans;
}

int main() {

    return 0;
}