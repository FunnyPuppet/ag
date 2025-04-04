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

#define NULL_NODE (-1)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* arrayToTree(const std::vector<int>& arr) {
    if (arr.empty() || arr[0] == NULL_NODE) return nullptr;
    auto* root = new TreeNode(arr[0]);
    std::queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < arr.size()) {
        TreeNode* node = q.front();
        q.pop();
        if (arr[i] != NULL_NODE) {
            node->left = new TreeNode(arr[i]);
            q.push(node->left);
        }
        i++;
        if (i < arr.size() && arr[i] != NULL_NODE) {
            node->right = new TreeNode(arr[i]);
            q.push(node->right);
        }
        i++;
    }
    return root;
}

class Solution {
public:
    pair<TreeNode*, int> dfs(TreeNode* root) {
        if (root == nullptr) {
            return {root, 0};
        }

        auto l = dfs(root->left);
        auto r = dfs(root->right);

        if (l.second > r.second) {
            return {l.first, l.second + 1};
        }
        if (l.second < r.second) {
            return {r.first, r.second + 1};
        }

        return {root, l.second + 1};
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).first;
    }
};

int main(int argc, char *argv[]) {
    vector<int> arr = {3,5,1,6,2,0,8,NULL_NODE,NULL_NODE,7,4};
    TreeNode* root = arrayToTree(arr);

    Solution sl;

    TreeNode * res = sl.lcaDeepestLeaves(root);

    cout << res->val << endl;

    delete root;

    return 0;
}
