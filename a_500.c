#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool checkInRow(char ch, char* row) {
    for (int i = 0; row[i] != '\0'; i++) {
        if (tolower(ch) == row[i]) {
            return true;
        }
    }
    return false;
}

char** findWords(char** words, int wordsSize, int* returnSize) {
    char *rowOne = "qwertyuiop";
    char *rowTwo = "asdfghjkl";
    char *rowThree = "zxcvbnm";

    *returnSize = 0;
    char **ans = malloc(sizeof(char*) * wordsSize);
    for (int i = 0; i < wordsSize; i++) {
        char *word = words[i];

        int row = 0;
        bool flag = true;
        for (int j = 0; j < strlen(word); j++) {
            if (checkInRow(word[j], rowOne)) {
                if (row == 0) {
                    row = 1;
                }
                if (row != 1) {
                    flag = false;
                }
            } else if (checkInRow(word[j], rowTwo)) {
                if (row == 0) {
                    row = 2;
                }
                if (row != 2) {
                    flag = false;
                }
            } else if (checkInRow(word[j], rowThree)) {
                if (row == 0) {
                    row = 3;
                }
                if (row != 3) {
                    flag = false;
                }
            }
        }
        if (flag) {
            ans[*returnSize] = word;
            (*returnSize)++;
        }
    }

    return ans;
}

int main() {
    char **wors = {"hello"};
    int len = sizeof(wors) / sizeof(wors[0]);
    int returnSize;
    char **res = findWords(wors, len, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", res[i]);
    }
    free(res);

    return 0;
}