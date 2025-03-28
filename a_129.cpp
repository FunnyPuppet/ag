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
    void dfs(vector<int>& nums, TreeNode* node, int val) {
        if (node == nullptr) {
            return;
        }

        val = val * 10 + node->val;

        if (node->left == nullptr && node->right == nullptr) {
            nums.push_back(val);
        }

        dfs(nums, node->left, val);
        dfs(nums, node->right, val);
    }

    int sumNumbers(TreeNode* root) {
        vector<int> nums;

        dfs(nums, root, 0);

        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            ans += nums[i];
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    TreeNode *root = new TreeNode(1);
    TreeNode *node1 = new TreeNode(3);
    TreeNode *node2 = new TreeNode(2);

    node1->right = node2;
    root->left = node1;

    Solution sl;

    sl.sumNumbers(root);
    return 0;
}
