#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int findClosest(int x, int y, int z) {
    int xz = abs(z - x);
    int yz = abs(z - y);

    return xz == yz ? 0 : (xz < yz ? 1 : 2);
}

int main() {
    int res = findClosest(2, 3, 4);
    printf("%d\n", res);

    return 0;
}