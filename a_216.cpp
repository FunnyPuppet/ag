#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <list>

using namespace std;

class Solution {
public:
    void backtrack(vector<vector<int>> &ans, vector<int> &tmp, int last, int n, int k) {
        if (k == 0) {
            if (n == 0) {
                ans.push_back(tmp);
            }
            return;
        }

        for (int i = last; i <= 9; i++) {
            tmp.push_back(i);
            backtrack(ans, tmp, i + 1, n - i, k - 1);
            tmp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> tmp;

        backtrack(ans, tmp, 1, n, k);

        return ans;
    }
};


int main(int argc, char *argv[]) {
    Solution sl;

    vector<vector<int>> res = sl.combinationSum3(3, 9);

    return 0;
}
