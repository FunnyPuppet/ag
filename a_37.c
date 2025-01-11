#include <stdio.h>
#include <stdbool.h>

bool isValid(char** board, int row, int col, char c) {
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == c) return false;
        if (board[row][i] == c) return false;
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
    }
    return true;
}

bool solve_sudoku(char** board, int boardSize, int* boardColSize) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                for (char c = '1'; c <= '9'; c++) {
                    if (isValid(board, i, j, c)) {
                        board[i][j] = c;
                        if (solve_sudoku(board, boardSize, boardColSize))
                            return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }

    return true;
}

void solveSudoku(char** board, int boardSize, int* boardColSize) {
    solve_sudoku(board, boardSize, boardColSize);
}

int main() {
    char board[9][9] = {{'5','3','.','.','7','.','.','.','.'}
        , {'6','.','.','1','9','5','.','.','.'}
        , {'.','9','8','.','.','.','.','6','.'}
        , {'8','.','.','.','6','.','.','.','3'}
        , {'4','.','.','8','.','3','.','.','1'}
        , {'7','.','.','.','2','.','.','.','6'}
        , {'.','6','.','.','.','.','2','8','.'}
        , {'.','.','.','4','1','9','.','.','5'}
        , {'.','.','.','.','8','.','.','7','9'}};

    char *tmp[9];
    for (int i = 0; i < 9; i++) {
        tmp[i] = board[i];
    }
    solveSudoku(tmp, 9, NULL);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%c ", tmp[i][j]);
        }
        printf("\n");
    }

    return 0;
}

