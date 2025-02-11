#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            long num = nums[i];
            int id = getID(num, valueDiff + 1ll);
            if (map.count(id)) {
                return true;
            }
            if (map.count(id - 1) && abs(num - map[id - 1]) <= valueDiff) {
                return true;
            }
            if (map.count(id + 1) && abs(num - map[id + 1]) <= valueDiff) {
                return true;
            }
            map[id] = num;
            if (i >= indexDiff) {
                map.erase(getID(nums[i - indexDiff], valueDiff + 1ll));
            }
        }
        return false;
    }

    int getID(long x, long w) {
        return x < 0 ? (x + 1ll) / w - 1 : x / w;
    }
};



int main() {
    vector<int> nums = {1, 5, 9, 1, 5, 9};
    Solution sl;
    bool res = sl.containsNearbyAlmostDuplicate(nums, 2, 3);

    cout << res << endl;

    return 0;
}
