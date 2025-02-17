#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> temp;
        vector<string> ans;

        temp.push_back(root->val);
        backtrack(root, temp, ans);

        return ans;
    }

    void backtrack(TreeNode* node, vector<int>& temp, vector<string>& result) {
        if (node->left == nullptr && node->right == nullptr) {
            result.push_back(getStr(temp));
            return;
        }

        if (node->left != nullptr) {
            temp.push_back(node->left->val);
            backtrack(node->left, temp, result);
            temp.pop_back();
        }
        if (node->right != nullptr) {
            temp.push_back(node->right->val);
            backtrack(node->right, temp, result);
            temp.pop_back();
        }
    }

    string getStr(vector<int> v) {
        int n = v.size();
        if (n == 0) {
            return "";
        }

        string ans = "";

        for (int i = 0; i < n - 1; i++) {
            ans += to_string(v[i]) + "->";
        }
        ans += to_string(v[n - 1]);
        return ans;
    }
};



int main() {
    vector<int> nums = {1, 5, 9, 1, 5, 9};
    Solution sl;

    cout << sl.getStr(nums) << endl;

    return 0;
}
