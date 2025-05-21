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
#include <string.h>

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
    int ans = 0;
    int cnt = 0;

    int dfs(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int tmp = cnt;
        int sum = dfs(node->left) + dfs(node->right) + node->val;
        cnt++;
        if (node->val == sum / (cnt - tmp)) {
            ans++;
        }

        return sum;
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);

        return ans;
    }
};

int main(int argc, char *argv[]) {

    return 0;
}
