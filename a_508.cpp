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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    unordered_map<int, int> mp;
    int maxCnt = 0;

    int dfs(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int sum = dfs(node->left) + dfs(node->right) + node->val;
        mp[sum]++;

        maxCnt = max(maxCnt, mp[sum]);

        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);

        vector<int> ans;

        for (auto pair : mp) {
            if (pair.second == maxCnt) {
                ans.push_back(pair.first);
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {

    return 0;
}
