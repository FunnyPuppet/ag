#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int uniqueLetterString(string s) {
        unordered_map<char, vector<int>> index;
        for (int i = 0; i < s.size(); i++) {
            index[s[i]].emplace_back(i);
        }
        int ans = 0;
        for (auto &&[_, arr]: index) {
            arr.insert(arr.begin(), -1);
            arr.emplace_back(s.size());
            for (int i = 1; i < arr.size() - 1; i++) {
                ans += (arr[i] - arr[i - 1]) * (arr[i + 1] - arr[i]);
            }
        }
        return ans;
    }
};

int main(){
    Solution sl;
    int res = sl.uniqueLetterString("ABC");
    return 0;
}
