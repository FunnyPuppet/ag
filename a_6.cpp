#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        string str;
        for (int i = 0; i < numRows; i++) {
            int j = i;
            int b = numRows - 1 - i;
            if (i == numRows - 1) {
                b = numRows - 1;
            }
            while (j < s.length()) {
                str.push_back(s[j]);
                j += 2 * b;
                if (i != 0 && i != numRows - 1) {
                    b = numRows - 1 - b;
                }
            }
        }

        return str;
    }
};


int main(int argc, char *argv[]) {
    Solution sl;

    string res = sl.convert("abdx", 2);

    cout << res << endl;

    return 0;
}
