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
    TreeNode *t1 = nullptr;
    TreeNode *t2 = nullptr;
    TreeNode *pre = nullptr;
    void recoverTree(TreeNode* root) {
        dfs(root);
        swap(t1->val, t2->val);
    }

    void dfs(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        dfs(node->left);
        if (pre != nullptr) {
            if (pre->val >= node->val) {
                if (t1 == nullptr) {
                    t1 = pre;
                    t2 = node;
                } else {
                    t2 = node;
                    return;
                }
            }
        }
        pre = node;
        dfs(node->right);
    }
};

int main(int argc, char *argv[]) {
    TreeNode *root = new TreeNode(1);
    TreeNode *node1 = new TreeNode(3);
    TreeNode *node2 = new TreeNode(2);

    node1->right = node2;
    root->left = node1;

    Solution sl;

    sl.recoverTree(root);
    return 0;
}
