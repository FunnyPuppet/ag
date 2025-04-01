#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

long long mostPoints(int** questions, int questionsSize, int* questionsColSize) {
    long long dp[questionsSize + 1];
    for (int i = 0; i <= questionsSize; i++) {
        dp[i] = 0;
    }

    for (int i = questionsSize - 1; i >= 0; i--) {
        dp[i] = fmax(dp[i + 1], dp[(int)fmin(questionsSize, questions[i][1] + i + 1)] + questions[i][0]);
    }

    return dp[0];
}

int main() {
    int m = 5;
    int questions[5][2] = {{1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}};
    int *arr[m];

    for (int i = 0; i < m; i++) {
        arr[i] = questions[i];
    }

    mostPoints(arr, m, NULL);

    return 0;
}