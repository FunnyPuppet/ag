#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <list>

using namespace std;

class Solution {
public:
    void backtrack(vector<string> &ans, vector<string> &tmp, string s, int index) {
        if (index == 4) {
            if (tmp.size() == 4 && s.empty()) {
                ans.push_back(tmp[0] + "." + tmp[1] + "." + tmp[2] + "." + tmp[3]);
            }
            return;
        }

        for (int j = 1; j <= 3; j++) {
            if (s.length() < j) {
                return;
            }
            string ts = s.substr(0, j);
            if ((ts[0] == '0' && ts.length() > 1) || stoi(ts) > 255) {
                break;
            }
            tmp.push_back(ts);
            backtrack(ans, tmp, s.substr( j), index + 1);
            tmp.pop_back();
        }

    }

    vector<string> restoreIpAddresses(string s) {
        int n = s.length();

        if (n < 4 || n > 12) {
            return {};
        }

        vector<string> ans;
        vector<string> tmp;

        backtrack(ans, tmp, s, 0);

        return ans;
    }
};


int main(int argc, char *argv[]) {
    Solution sl;

    vector<int> nums = {2, 7, 9, 11};
    vector<string> res = sl.restoreIpAddresses("25525511135");

    for (auto r : res) {
        cout << r << endl;
    }

    return 0;
}
