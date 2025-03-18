#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int ,int> map;

        for (int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }

        return build(preorder, map, 0, preorder.size() - 1, 0, inorder.size());
    }

    TreeNode* build(vector<int>& preorder, unordered_map<int, int>& map, int pLeft, int pRight, int iLeft, int iRight) {
        if (pLeft > pRight || iLeft > iRight) {
            return nullptr;
        }

        int rootVal = preorder[pLeft];
        auto *root = new TreeNode(rootVal);
        int pIndex = map[rootVal];

        root->left = build(preorder, map, pLeft + 1, pLeft + pIndex - iLeft, iLeft, pIndex - 1);
        root->right = build(preorder, map, pLeft + pIndex - iLeft + 1, pRight, pIndex + 1, iRight);

        return root;
    }
};

int main(int argc, char *argv[]) {
    Solution sl;

    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode *res = sl.buildTree(preorder, inorder);

    cout << res << endl;

    return 0;
}
