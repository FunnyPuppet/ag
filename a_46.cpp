#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backTrack(res, nums, 0);

        return res;
    }

    void backTrack(vector<vector<int>>& res, vector<int>& nums, int start) {
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);
            backTrack(res, nums, start + 1);
            swap(nums[start], nums[i]);
        }
    }
};



int main() {
    vector<int> nums = {1, 2, 3};
    Solution sl;
    vector<vector<int>> res = sl.permute(nums);

    return 0;
}
