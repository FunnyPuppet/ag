#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int minDominoRotations(int* tops, int topsSize, int* bottoms, int bottomsSize) {
    int mask = (1 << 8) - 1;
    int n = topsSize;
    for(int i = 0; i < n; i++){
        mask &= 1 << tops[i] | 1 << bottoms[i];
    }
    if (!mask) return -1;
    int v = 0;
    while ((mask & 1) == 0) {
        mask >>= 1;
        v++;
    }

    int tc = 0,bc = 0;
    for(int i = 0; i < n; i++){
        tc += tops[i] ^ bottoms[i] && !(tops[i] ^ v);
        bc += tops[i] ^ bottoms[i] && !(bottoms[i] ^ v);
    }

    return (tc & ((tc - bc) >> 31)) | (bc & ~((tc - bc) >> 31)) ;
}

int main() {
    return 0;
}
