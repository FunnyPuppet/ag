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

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

class Solution {
    int ans = 0;

    void dfs(TreeNode *node, int mn, int mx) {
        if (node == nullptr) {
            ans = max(ans, mx - mn);
            return;
        }
        mn = min(mn, node->val);
        mx = max(mx, node->val);
        dfs(node->left, mn, mx);
        dfs(node->right, mn, mx);
    }

public:
    int maxAncestorDiff(TreeNode *root) {
        dfs(root, root->val, root->val);
        return ans;
    }
};

int main(int argc, char *argv[]) {

    return 0;
}
