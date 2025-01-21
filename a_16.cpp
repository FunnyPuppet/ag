#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int cnt = 300000;
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            int r = n - 1;

            int t = target - nums[i];
            for (int l = i + 1; l < n; l++) {
                while (l < r && nums[l] + nums[r] > t) {
                    r--;
                }

                if (r != n - 1) {
                    int sum = nums[i] + nums[l] + nums[r + 1];
                    cnt = abs(sum - target) > abs(cnt - target) ? cnt : sum;
                }

                if (l == r) {
                    break;
                }

                int sum = nums[i] + nums[l] + nums[r];
                cnt = abs(sum - target) > abs(cnt - target) ? cnt : sum;
            }
        }
        return cnt;
    }
};

int main(){
    vector<int> nums = {3, 2, 3};
    Solution sl;
    int res = sl.threeSumClosest(nums, 2);

    cout << res << endl;

    return 0;
}
