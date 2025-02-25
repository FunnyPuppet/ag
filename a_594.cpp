#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> map;

        for (int num : nums) {
            map[num]++;
        }

        int ans = 0;
        for (auto pair : map) {
            if (map.find(pair.first + 1) != map.end()) {
                int cnt = pair.second + map[pair.first + 1];
                ans = cnt > ans ? cnt : ans;
            }
        }

        return ans;
    }
};


int main() {
    vector<int> nums = {1,1,3,3,4,4,5,6};
    Solution sl;

    int res = sl.findLHS(nums);

    cout << res << endl;

    return 0;
}
