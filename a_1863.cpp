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
    void tracback(int& res, vector<int>& nums, vector<int>& path, vector<bool> used, int start, int ps) {
        if (path.size() == ps) {
            int t = 0;
            for (const int& p : path) {
                t ^= p;
            }
            res += t;
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }
            used[i] = true;
            path.push_back(nums[i]);
            tracback(res, nums, path, used, start + 1, ps);
            path.pop_back();
        }
    }

    int subsetXORSum(vector<int>& nums) {
        int res = 0;

        for (int i = 1; i <= nums.size(); i++) {
            vector<int> path;
            vector<bool> used(nums.size(), false);

            tracback(res, nums, path, used, 0, i);
        }

        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sl;
    vector<int> nums = {1, 2, 3, 4};
    int res = sl.subsetXORSum(nums);
    cout << res << endl;

    return 0;
}
