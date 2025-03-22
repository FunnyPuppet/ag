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
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        int idx = 0, max = 0;
        for (int i = 0; i < m; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    cnt++;
                }
            }
            if (cnt > max) {
                max = cnt;
                idx = i;
            }
        }

        if (max > 0) {
            return {idx, max};
        }

        return {};
    }
};

int main(int argc, char *argv[]) {
    Solution sl;

    vector<vector<int>> mat = {{0, 0, 1}, {1, 1, 1}, {1, 0, 1}};
    vector<int> res = sl.rowAndMaximumOnes(mat);

    return 0;
}
