#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<int> ans;
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] < target) {
                l = mid + 1;
            } else if (target < nums[mid]) {
                r = mid;
            } else {
                int min = mid, max = mid;
                while (max <= r) {
                    if (nums[max] != target) {
                        break;
                    }
                    max++;
                }
                while (min >= l) {
                    if (nums[min] != target) {
                        break;
                    }
                    min--;
                }
                for (int i = min + 1; i < max; i++) {
                    ans.push_back(i);
                }
                break;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1,2,5,2,3};
    Solution sl;
    sl.targetIndices(nums, 4);

    return 0;
}
