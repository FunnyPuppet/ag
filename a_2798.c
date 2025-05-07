#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int numberOfEmployeesWhoMetTarget(int* hours, int hoursSize, int target) {
    int ans = 0;

    for (int i = 0; i < hoursSize; i++) {
        if (hours[i] >= target) {
            ans++;
        }
    }

    return ans;
}

int main() {

    return 0;
}