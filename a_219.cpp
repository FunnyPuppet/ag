#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            if (map.find(nums[i]) != map.end()) {
                if (abs(i - map[nums[i]]) <= k) {
                    return true;
                }
            }
            map[nums[i]] = i;
        }

        return false;
    }
};



int main() {
    vector<int> nums = {1,0,1,1};
    Solution sl;
    bool res = sl.containsNearbyDuplicate(nums, 1);

    cout << res << endl;

    return 0;
}
