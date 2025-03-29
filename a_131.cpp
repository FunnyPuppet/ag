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
private:
    vector<vector<bool>> dp;
    vector<vector<string>> res;
    vector<string> ans;
    int n;
public:
    void dfs(string& s, int i) {
        if (i == n) {
            res.push_back(ans);
            return;
        }

        for (int j = i; j < n; j++) {
            if (dp[i][j]) {
                ans.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1);
                ans.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        n = s.size();

        dp.assign(n, vector<bool>(n ,true));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
            }
        }

        dfs(s, 0);

        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sl;
    sl.partition("aaba");

    return 0;
}
