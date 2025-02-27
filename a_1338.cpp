#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> map;

        for (int num : arr) {
            map[num]++;
        }

        vector<int> cc;

        for (auto pair : map) {
            cc.push_back(pair.second);
        }

        sort(cc.begin(), cc.end(), greater<int>());

        int ans = 0, cnt = arr.size();
        for (int c : cc) {
            cnt -= c;
            ans++;
            if (cnt * 2 <= arr.size()) {
                break;
            }
        }

        return ans;
    }
};


int main() {
    vector<int> nums = {3,3,3,3,5,5,5,2,2,7};
    Solution sl;

    int res = sl.minSetSize(nums);

    cout << res << endl;

    return 0;
}
