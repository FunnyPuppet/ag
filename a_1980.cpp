#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> set;

        for (const auto& num : nums) {
            set.insert(num);
        }

        string str;
        for (int i = 0; i < nums.size(); i++) {
            str += "1";
        }

        for (int i = 0; i < nums.size(); i++) {
            if (set.find(str) == set.end()) {
                return str;
            }
            str[i] = '0';
        }

        return "";
    }
};



int main() {
    vector<string> nums = {"111","011","001"};
    Solution sl;
    string res = sl.findDifferentBinaryString(nums);

    cout << res << endl;

    return 0;
}
