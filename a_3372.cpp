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
    vector<vector<int>> buildTree(vector<vector<int>>& edges) {
        vector<vector<int>> g(edges.size() + 1);
        for (auto& e : edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        return g;
    }

    int dfs(int x, int fa, int d, vector<vector<int>>& g, int k) {
        if (d > k) {
            return 0;
        }
        int cnt = 1;
        for (int y : g[x]) {
            if (y != fa) {
                cnt += dfs(y, x, d + 1, g, k);
            }
        }
        return cnt;
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int max2 = 0;
        if (k > 0) {
            auto g = buildTree(edges2);
            for (int i = 0; i < edges2.size() + 1; i++) {
                max2 = max(max2, dfs(i, -1, 0, g, k - 1));
            }
        }

        auto g = buildTree(edges1);
        vector<int> ans(edges1.size() + 1);
        for (int i = 0; i < ans.size(); i++) {
            ans[i] = dfs(i, -1, 0, g, k) + max2;
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {

    return 0;
}
