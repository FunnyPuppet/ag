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
    string addSpaces(string s, vector<int>& spaces) {
        string ans;

        int l = 0;
        for (int space : spaces) {
            ans += s.substr(l, space - l) + " ";
            l = space;
        }

        ans += s.substr(l);

        return ans;
    }
};

int main(int argc, char *argv[]) {
    vector<int> spaces = {8, 13, 15};

    Solution sl;
    sl.addSpaces("LeetcodeHelpsMeLearn", spaces);

    return 0;
}
