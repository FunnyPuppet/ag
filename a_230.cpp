#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <list>
#include <stack>

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
    void inorderTraversal(vector<int>& nums, TreeNode* root) {
        if (root != nullptr) {
            inorderTraversal(nums, root->left);
            nums.push_back(root->val);
            inorderTraversal(nums, root->right);
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> sk;
        while (root != nullptr || sk.size() > 0) {
            while (root != nullptr) {
                sk.push(root);
                root = root->left;
            }
            root = sk.top();
            sk.pop();
            --k;
            if (k == 0) {
                break;
            }
            root = root->right;
        }

        return root->val;
    }
};

int main(int argc, char *argv[]) {

    return 0;
}
