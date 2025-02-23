#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;

        for (int num : nums) {
            set.insert(num);
        }

        int ans = 0;
        for (int num : set) {
            if (set.find(num - 1) == set.end()) {
                int cur = 1, idx = num;

                while (set.count(idx + 1)) {
                    cur += 1;
                    idx++;
                }
                ans = cur > ans ? cur : ans;
            }
        }

        return ans;
    }
};


int main() {
    vector<int> nums = {0,1,2,4,8,5,6,7,9,3,55,88,77,99,9999999};
    Solution sl;

    int res = sl.longestConsecutive(nums);

    cout << res << endl;

    return 0;
}
