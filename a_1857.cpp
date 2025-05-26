#include <algorithm>
#include <complex>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <list>
#include <numeric>
#include <stack>
#include <string.h>

using namespace std;

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            int x = e[0], y = e[1];
            if (x == y) {
                return -1;
            }
            g[x].push_back(y);
        }

        vector<vector<int>> memo(n);
        auto dfs = [&](this auto&& dfs, int x) -> vector<int> {
            if (!memo[x].empty()) {
                return memo[x];
            }
            memo[x] = {0};
            vector<int> res(26);
            for (int y : g[x]) {
                auto cy = dfs(y);
                if (cy.size() <= 1) {
                    return cy;
                }
                for (int i = 0; i < 26; i++) {
                    res[i] = max(res[i], cy[i]);
                }
            }
            res[colors[x] - 'a']++;
            return memo[x] = res;
        };

        int ans = 0;
        for (int x = 0; x < n; x++) {
            auto res = dfs(x);
            if (res.size() <= 1) {
                return -1;
            }
            ans = max(ans, res[colors[x] - 'a']);
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {

    return 0;
}
