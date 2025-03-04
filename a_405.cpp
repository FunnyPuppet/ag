#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string toHex(int num) {
        if (num == 0) {
            return "0";
        }

        char arr[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        string ans;

        for (int i = 7; i >= 0; i--) {
            char val = arr[(num >> (i * 4)) & 15];
            if (!ans.empty() || val != '0') {
                ans += val;
            }
        }

        return ans;
    }
};


int main() {
    Solution sl;

    string res = sl.toHex(111111);

    cout << res << endl;

    return 0;
}
