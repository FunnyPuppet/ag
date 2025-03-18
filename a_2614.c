#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

bool isPrime(int num) {
    if (num == 1) {
        return false;
    }
    int factor = 2;
    while (factor * factor <= num) {
        if (num % factor == 0) {
            return false;
        }
        factor++;
    }
    return true;
}

int diagonalPrime(int** nums, int numsSize, int* numsColSize) {
    int res = 0;
    for (int i = 0; i < numsSize; i++) {
        if (isPrime(nums[i][i])) {
            res = res > nums[i][i] ? res : nums[i][i];
        }
        if (isPrime(nums[i][numsSize - i - 1])) {
            res = res > nums[i][numsSize - i - 1] ? res : nums[i][numsSize - i - 1];
        }
    }
    return res;
}

int main() {
    for (int i = 1; i < 30; i++) {
        printf("%d %d\n", i, isPrime(i));
    }
    return 0;
}