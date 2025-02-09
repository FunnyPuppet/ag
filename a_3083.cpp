#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isSubstringPresent(string s) {
        int n = s.size();

        if (n < 2) {
            return false;
        }

        unordered_set<string> set;
        for (int i = 1; i < n; i++) {
            set.insert(s.substr(i - 1, 2));
        }

        reverse(s.begin(), s.end());
        for (int i = 1; i < n; i++) {
            if (set.find(s.substr(i - 1, 2)) != set.end()) {
                return true;
            }
        }

        return false;
    }
};



int main() {
    Solution sl;
    bool res = sl.isSubstringPresent("abcd");

    cout << res << endl;

    return 0;
}
