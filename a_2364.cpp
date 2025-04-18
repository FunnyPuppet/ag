#include <algorithm>
#include <complex>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <list>
#include <stack>

using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> mp;

        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans += i - mp[i - nums[i]];
            mp[i - nums[i]]++;
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums = {1,2,3,4,5};
    Solution sl;
    long long res = sl.countBadPairs(nums);

    cout << res << endl;

    return 0;
}
