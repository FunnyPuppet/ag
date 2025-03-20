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
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        string ans = "0";
        int m = num1.size(), n = num2.size();
        for (int i = n - 1; i >= 0; i--) {
            string curr;
            int add = 0;
            for (int j = n - 1; j > i; j--) {
                curr.push_back(0);
            }
            int y = num2.at(i) - '0';
            for (int j = m - 1; j >= 0; j--) {
                int x = num1.at(j) - '0';
                int p = x * y + add;
                curr.push_back(p % 10);
                add = p / 10;
            }
            while (add != 0) {
                curr.push_back(add % 10);
                add /= 10;
            }
            reverse(curr.begin(), curr.end());
            for (auto &c : curr) {
                c += '0';
            }
            ans = addStrings(ans, curr);
        }

        return ans;
    }

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
    string res = sl.multiply("2", "3");

    cout << res << endl;

    return 0;
}
