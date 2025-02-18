#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        backtrack(res, s, n, n);
        return res;
    }

    void backtrack(vector<string>& res, string& s, int left, int right) {
        if (left == 0 && right == 0) {
            res.push_back(s);
            return;
        }
        if (left > 0) {
            s.push_back('(');
            backtrack(res, s, left - 1, right);
            s.pop_back();
        }

        if (right > left) {
            s.push_back(')');
            backtrack(res, s, left, right - 1);
            s.pop_back();
        }
    }
};



int main() {
    Solution sl;

    vector<string> res = sl.generateParenthesis(4);

    for (const string& s : res) {
        cout << s << endl;
    }

    return 0;
}
