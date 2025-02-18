#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";

        for (int i = 1; i < n; i++) {
            ans = getStr(ans);
        }
        return ans;
    }

    string getStr(string& s) {
        string ans;

        int l = 0, r = 0;
        char cur = s[0];
        for (int i = 1; i < s.length(); i++) {
            if (s[i] != cur) {
                ans.push_back( r - l + 1 + '0');
                ans.push_back(cur);
                cur = s[i];
                l = i;
            }
            r++;
        }

        ans.push_back( r - l + 1 + '0');
        ans.push_back(cur);

        return ans;
    }
};


int main() {
    Solution sl;

    string res = sl.countAndSay(4);

    cout << res << endl;


    return 0;
}
