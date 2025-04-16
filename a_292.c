#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

bool canWinNim(int n) {
    return n % 4;
}

int main() {
    bool res = canWinNim(4);
    printf("%d\n", res);

    return 0;
}