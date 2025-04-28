#include <algorithm>
#include <complex>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <list>
#include <numeric>
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
    int maxLvl;
    int sum;

    void dfs(TreeNode* root, int level) {
        if (root == nullptr) {
            return;
        }

        if (level == maxLvl) {
            sum += root->val;
        }

        if (level > maxLvl) {
            maxLvl = level;
            sum = root->val;
        }


        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }

    int deepestLeavesSum(TreeNode* root) {
        sum = 0;
        dfs(root, 0);

        return sum;
    }
};

int main(int argc, char *argv[]) {

    return 0;
}
