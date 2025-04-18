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
    string stringHash(string s, int k) {
        int n = s.size();
        string ans;
        for (int i = 0; i < n; i += k) {
            int sum = 0;

            for (int j = i; j < i + k; j++) {
                sum += s[j] - 'a';
            }
            ans.push_back((sum % 26) + 'a');
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution sl;
    string res = sl.stringHash("abcd", 2);

    cout << res << endl;

    return 0;
}
