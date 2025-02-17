#include <stdio.h>
#include <stdlib.h>

int minPathSum(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];

    for (int i = 1; i < m; i++) {
        grid[i][0] += grid[i - 1][0];
    }

    for (int i = 1; i < n; i++) {
        grid[0][i] += grid[0][i - 1];
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            int min = grid[i - 1][j] < grid[i][j - 1] ? grid[i - 1][j] : grid[i][j - 1];
            grid[i][j] += min;
        }
    }

    return grid[m - 1][n - 1];
}

int main() {
    int m = 3;
    int n = 3;
    int *col = malloc(sizeof(int) * m);
    int nums[3][3] = {{1,3,1}, {1,5,1}, {4,2,1}};

    int **arr = malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i++) {
        arr[i] = nums[i];
        col[i] = n;
    }

    minPathSum(arr, m, col);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    free(n);
    free(arr);

    return 0;
}