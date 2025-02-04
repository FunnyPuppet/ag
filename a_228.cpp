#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) {
            return {};
        }

        int l = nums[0], r = nums[0];

        vector<string> res;
        for (int i = 1; i < n; i++) {
            if (nums[i] != r + 1) {
                res.push_back(calRange(l, r));
                l = nums[i];
            }
            r = nums[i];
        }
        res.push_back(calRange(l, r));

        return res;
    }

    string calRange(int l, int r) {
        if (l == r) {
            return to_string(l);
        }

        return to_string(l) + "->" + to_string(r);
    }
};



int main() {
    vector<int> nums = {0, 1, 2, 4, 5, 7};
    Solution sl;
    vector<string> res = sl.summaryRanges(nums);

    return 0;
}
