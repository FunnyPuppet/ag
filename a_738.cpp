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
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int start = s.size();
        for (int i = s.size() - 1; i > 0; i--) {
            if (s[i - 1] > s[i]) {
                start = i;
                s[i - 1]--;
            }
        }
        for (int i = start; i < s.size(); i++) {
            s[i] = '9';
        }

        return stoi(s);
    }
};

int main(int argc, char *argv[]) {
    Solution sl;
    int res = sl.monotoneIncreasingDigits(721528309);

    cout << res << endl;

    return 0;
}
