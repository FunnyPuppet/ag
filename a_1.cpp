#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <list>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> records;

        for (int i = 0; i < nums.size(); i++) {
            if (records.find(target - nums[i]) != records.end()) {
                return {records[target - nums[i]], i};
            }
            records[nums[i]] = i;
        }

        return {};
    }
};


int main(int argc, char *argv[]) {
    Solution sl;

    vector<int> nums = {2, 7, 9, 11};
    vector<int> res = sl.twoSum(nums, 9);

    cout << res[0] << ":" << res[1] << endl;


    return 0;
}
