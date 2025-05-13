#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int* minOperations(char * boxes, int* returnSize) {
    int n = strlen(boxes);
    int *ans = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (boxes[j] == '1') {
                sum += abs(j - i);
            }
        }
        ans[i] = sum;
    }
    *returnSize = n;

    return ans;
}

int main() {

    return 0;
}