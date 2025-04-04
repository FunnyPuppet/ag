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
    TreeNode* ans;

    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return false;
        }

        bool lf = dfs(root->left, p, q);
        bool rf = dfs(root->right, p, q);

        if ((lf && rf) || ((root->val == p->val || root->val == q->val) && (lf || rf))) {
            ans = root;
        }

        return lf || rf || (root->val == p->val || root->val == q->val);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
};

int main(int argc, char *argv[]) {
    vector<int> arr = {3,5,1,6,2,0,8,NULL_NODE,NULL_NODE,7,4};
    TreeNode* root = arrayToTree(arr);

    auto* p = new TreeNode(5);
    auto* q = new TreeNode(1);

    Solution sl;

    TreeNode * res = sl.lowestCommonAncestor(root, p, q);

    cout << res->val << endl;

    delete p;
    delete q;
    delete root;

    return 0;
}
