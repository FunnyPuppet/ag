#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

bool canAliceWin(int* nums, int numsSize) {
    int sum = 0;

    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        if (num < 10) {
            sum += num;
        } else {
            sum -= num;
        }
    }

    return sum != 0;
}

int main() {

    return 0;
}