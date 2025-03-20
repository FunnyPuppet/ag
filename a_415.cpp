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

class Solution {
public:
    string addStrings(string num1, string num2) {
        int m = num1.size() - 1, n = num2.size() - 1;

        string ans;
        int add = 0;
        while (m >= 0 || n >= 0) {
            int sum = add;
            if (m >= 0) {
                sum += num1[m--] - '0';
            }
            if (n >= 0) {
                sum += num2[n--] - '0';
            }
            ans.push_back((sum % 10) + '0');
            add = sum / 10;
        }
        if (add > 0) {
            ans.push_back(add + '0');
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution sl;

    vector<int> nums = {1, 2};
    string res = sl.addStrings("2", "3");

    cout << res << endl;

    return 0;
}
