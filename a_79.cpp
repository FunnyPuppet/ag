#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <list>

using namespace std;

class Solution {
public:
    bool find = false;

    void bfs(vector<vector<char>>& board, vector<vector<bool>>& used, string word, int i, int j, int index) {
        if (word[index] != board[i][j] || find) {
            return;
        }
        if (index == word.length() - 1) {
            find = true;
            return;
        }
        used[i][j] = true;

        bool res = false;
        if (i > 0 && !used[i - 1][j]) {
            bfs(board, used, word, i - 1, j, index + 1);
        }

        if (j > 0 && !used[i][j - 1]) {
            bfs(board, used, word, i, j - 1, index + 1);
        }

        if (i < board.size() - 1 && !used[i + 1][j]) {
            bfs(board, used, word, i + 1, j, index + 1);
        }

        if (j < board[0].size() - 1 && !used[i][j + 1]) {
            bfs(board, used, word, i, j + 1, index + 1);
        }
        used[i][j] = false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> used(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bfs(board, used, word, i, j, 0);
                if (find) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main(int argc, char *argv[]) {
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    Solution sl;
    bool res = sl.exist(board, "ABCCED");

    cout << res << endl;

    return 0;
}
