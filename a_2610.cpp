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
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> cnt;

        for (int num : nums) {
            cnt[num]++;
        }

        vector<vector<int>> ans;
        while (!cnt.empty()) {
            vector<int> arr;

            auto it = cnt.begin();
            while (it != cnt.end()) {
                it->second--;
                arr.push_back(it->first);
                if (it->second == 0) {
                    it = cnt.erase(it);
                } else {
                    ++it;
                }
            }
            ans.push_back(arr);
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution sl;

    vector<int> nums = {1,3,4,1,2,3,1};
    vector<vector<int>> res = sl.findMatrix(nums);

    return 0;
}
