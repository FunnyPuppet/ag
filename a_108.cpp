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
    TreeNode* bfs(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int mid = left + (right - left) / 2;
        TreeNode *root = new TreeNode(nums.at(mid));

        root->left = bfs(nums, left, mid - 1);
        root->right = bfs(nums, mid + 1, right);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return bfs(nums, 0, nums.size() - 1);
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums = {1, 2, 3, 4};
    Solution sl;
    TreeNode *node = sl.sortedArrayToBST(nums);

    return 0;
}
