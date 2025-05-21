#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int finalValueAfterOperations(char** operations, int operationsSize) {
    int ans = 0;

    for (int i = 0; i < operationsSize; i++) {
        if (operations[i][1] == '+') {
            ans++;
        } else {
            ans--;
        }
    }

    return ans;
}

int main() {

    return 0;
}