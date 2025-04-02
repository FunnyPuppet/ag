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
    void dfs(vector<vector<int>>& ans, vector<int>& tmp, TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return;
        }

        targetSum = targetSum - root->val;
        tmp.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr && targetSum == 0) {
            ans.push_back(tmp);
        }

        dfs(ans, tmp, root->left, targetSum);
        dfs(ans, tmp, root->right, targetSum);
        tmp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;

        vector<int> tmp;

        dfs(ans, tmp, root, targetSum);

        return ans;
    }
};

int main(int argc, char *argv[]) {

    return 0;
}
