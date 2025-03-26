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
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                unordered_set<int> tl;
                int x = i - 1, y = j - 1;
                while (x >= 0 && y >= 0) {
                    tl.insert(grid[x][y]);
                    x--;
                    y--;
                }

                unordered_set<int> br;
                x = i + 1, y = j + 1;
                while (x < m && y < n) {
                    br.insert(grid[x][y]);
                    x++;
                    y++;
                }

                ans[i][j] = abs((int)tl.size() - (int)br.size());
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution sl;
    sl.differenceOfDistinctValues(mat);
    return 0;
}
