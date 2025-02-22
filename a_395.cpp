#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        vector<int> hash(26, 0);

        int n = (int) s.length();

        for (const char &c: s) {
            hash[c - 'a']++;
        }

        int i = 0;
        while (i < n && hash[s[i] - 'a'] >= k) i++;
        if (i == n) return n;

        int l = longestSubstring(s.substr(0, i), k);
        while (i < n && hash[s[i] - 'a'] < k) i++;
        int r = longestSubstring(s.substr(i), k);

        return l > r ? l : r;
    }
};

int main() {
    Solution sl;
    int res = sl.longestSubstring("aaabb", 3);

    cout << res << endl;

    return 0;
}