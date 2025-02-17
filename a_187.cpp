#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        if (n < 10) {
            return {};
        }
        unordered_map<string, int> map;

        vector<string> ans;

        for (int i = 0; i <= n - 10; i++) {
            string t = s.substr(i, 10);
            map[t]++;
        }

        for (const auto& pair : map) {
            if (pair.second > 1) {
                ans.push_back(pair.first);
            }
        }

        return ans;
    }
};



int main() {
    vector<int> nums = {1, 5, 9, 1, 5, 9};
    Solution sl;

    vector<string> res = sl.findRepeatedDnaSequences("AAAAAAAAAAA");

    for (auto s : res) {
        cout << s << endl;
    }

    return 0;
}
