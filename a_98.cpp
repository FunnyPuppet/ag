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
    void recursive(vector<int>& nums, TreeNode* root) {
        if (root != nullptr) {
            recursive(nums, root->left);
            nums.push_back(root->val);
            recursive(nums, root->right);
        }
    }

    bool isValidBST(TreeNode* root) {
        vector<int> nums;

        recursive(nums, root);

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                return false;
            }
        }

        return true;
    }
};

int main(int argc, char *argv[]) {

    return 0;
}
