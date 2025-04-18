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
#include <stack>

using namespace std;

class Solution {
public:
    vector<string> ans;
    int len;
    string path;

    void tracback(int idx, int last) {
        if (idx == len) {
            ans.emplace_back(path);
            return;
        }

        if (last == 0) {
            path.push_back('1');
            tracback(idx + 1, 1);
            path.pop_back();
        } else {
            path.push_back('0');
            tracback(idx + 1, 0);
            path.pop_back();

            path.push_back('1');
            tracback(idx + 1, 1);
            path.pop_back();
        }
    }

    vector<string> validStrings(int n) {
        len = n;
        tracback(0, 1);
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution sl;
    vector<string> res = sl.validStrings(6);

    for (const auto& s : res) {
        cout << s << endl;
    }

    return 0;
}
