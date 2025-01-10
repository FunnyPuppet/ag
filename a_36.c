#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    // 记录数字在某一行、某一列或某一个区块是否出现过
    bool rows[9][9] = {false};
    bool cols[9][9] = {false};
    bool areas[9][9] = {false};

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char ch = board[i][j];
            if (ch != '.') {
                int num = ch - '1';
                int area = (i / 3) * 3 + j / 3;
                // 判断数字是否出现过
                if (rows[i][num] || cols[j][num] || areas[area][num]) {
                    return false;
                }
                // 记录数字是否出现过
                rows[i][num] = cols[j][num] = areas[area][num] = true;
            }
        }
    }

    return true;
}

int main(void) {
    char board[9][9] = {{'5','3','.','.','7','.','.','.','.'}
        ,{'6','.','.','1','9','5','.','.','.'}
        ,{'.','9','8','.','.','.','.','6','.'}
        ,{'8','.','.','.','6','.','.','.','3'}
        ,{'4','.','.','8','.','3','.','.','1'}
        ,{'7','.','.','.','2','.','.','.','6'}
        ,{'.','6','.','.','.','.','2','8','.'}
        ,{'.','.','.','4','1','9','.','.','5'}
        ,{'.','.','.','.','8','.','.','7','9'}};

    char *tmp[9];
    for (int i = 0; i < 9; i++) {
        tmp[i] = board[i];
    }

    int colSize = 9;
    bool vaild = isValidSudoku(tmp, 9, &colSize);

    printf("%d\n", vaild);

    return EXIT_SUCCESS;
}