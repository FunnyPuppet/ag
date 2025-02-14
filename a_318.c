#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <tgmath.h>


int maxProduct(char** words, int wordsSize) {
    int *masks = malloc(sizeof(int) * wordsSize);
    int *lens = malloc(sizeof(int) * wordsSize);

    for (int i = 0; i < wordsSize; i++) {
        int mask = 0;
        for (int j = 0; words[i][j] != '\0'; j++) {
            mask |= 1 << (words[i][j] - 'a');
        }
        masks[i] = mask;
        lens[i] = strlen(words[i]);
    }

    int ans = 0;
    for (int i = 0; i < wordsSize; i++) {
        for (int j = i + 1; j < wordsSize; j++) {
            int t = lens[i] * lens[j];
            if ((masks[i] & masks[j]) == 0) {
                ans = t > ans ? t : ans;
            }
        }
    }

    free(masks);
    free(lens);

    return ans;
}

int main() {
    char words[4][4] = {"a", "aaa", "aa", "cd"};
    int len = sizeof(words) / sizeof(words[0]);
    char **arr = malloc(sizeof(char*) * len);

    for (int i = 0; i < len; i++) {
        arr[i] = words[i];
    }
    int res = maxProduct(arr, len);
    printf("%d\n", res);

    free(arr);

    return 0;
}