#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Score {
    int index;
    int score;
} Score;

int compareScore(const void *a, const void *b) {
    Score s_a = *(const Score*)a;
    Score s_b = *(const Score*)b;
    return s_b.score - s_a.score;
}

char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    char **ans = malloc(scoreSize * sizeof(char *));
    *returnSize = scoreSize;
    Score *arr = malloc(scoreSize * sizeof(Score));

    for (int i = 0; i < scoreSize; i++) {
        arr[i].score = score[i];
        arr[i].index = i;
    }

    qsort(arr, scoreSize, sizeof(Score), compareScore);

    for (int i = 0; i < scoreSize; i++) {
        int idx = arr[i].index;
        ans[idx] = (char *)malloc(20 * sizeof(char));
        if (i == 0) {
            strcpy(ans[idx], "Gold Medal");
        } else if (i == 1) {
            strcpy(ans[idx], "Silver Medal");
        } else if (i == 2) {
            strcpy(ans[idx], "Bronze Medal");
        } else {
            sprintf(ans[idx], "%d", i + 1);
        }
    }

    free(arr);
    return ans;
}

int main() {
    int score[] = {3, 2, 1};
    int len = sizeof(score) / sizeof(score[0]);
    int returnSize;
    char **res = findRelativeRanks(score, len, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", res[i]);
    }

    free(res);

    return 0;
}
