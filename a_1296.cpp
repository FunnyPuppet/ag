#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k != 0) {
            return false;
        }
        sort(nums.begin(), nums.end());
        unordered_map<int, int> map;

        for (int num : nums) {
            map[num]++;
        }

        unsigned long long count = nums.size() / k;

        for (int num : nums) {
            if (map[num]-- > 0) {
                int cnt = 1;
                while (cnt < k && map[++num]-- > 0) {
                    cnt++;
                }
                if (cnt != k) return false;
                count--;
            }
        }

        return count == 0;
    }
};


int main() {
    vector<int> nums = {1,1,3,3,4,4,5,6};
    Solution sl;

    bool res = sl.isPossibleDivide(nums, 4);

    cout << res << endl;

    return 0;
}
