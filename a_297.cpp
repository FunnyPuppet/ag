#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    void dfs(string& str, TreeNode* node) {
        if (node == NULL) {
            str += "null,";
            return;
        }

        str += to_string(node->val) + ",";

        dfs(str, node->left);
        dfs(str, node->right);
    }

    string serialize(TreeNode* root) {
        string ans;
        dfs(ans, root);
        return ans;
    }

    TreeNode* redeserialize(queue<string>& dataQueue) {
        if (dataQueue.front() == "null") {
            dataQueue.pop();
            return NULL;
        }

        TreeNode *node = new TreeNode(stoi(dataQueue.front()));
        dataQueue.pop();
        node->left = redeserialize(dataQueue);
        node->right = redeserialize(dataQueue);

        return node;
    }

    TreeNode* deserialize(string data) {
        queue<string> dataQueue;
        string str;

        for (char ch : data) {
            if (ch == ',') {
                dataQueue.push(str);
                str.clear();
            } else {
                str.push_back(ch);
            }
        }

        return redeserialize(dataQueue);
    }
};


int main() {
    Codec c;

    c.deserialize("1,2,3,null,null,4,5,");

    return 0;
}
