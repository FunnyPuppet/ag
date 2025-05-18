#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int finalPositionOfSnake(int n, char** commands, int commandsSize) {
    int x = 0, y = 0;
    for (int i = 0; i < commandsSize; i++) {
        if (commands[i][0] == 'U') {
            y--;
        }
        if (commands[i][0] == 'D') {
            y++;
        }
        if (commands[i][0] == 'L') {
            x--;
        }
        if (commands[i][0] == 'R') {
            x++;
        }
    }

    return y * n + x;
}

int main() {

    return 0;
}