#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int theMaximumAchievableX(int num, int t) {
    return num + 2 * t;
}

int main() {
    printf("%d\n", theMaximumAchievableX(3, 2));

    return 0;
}