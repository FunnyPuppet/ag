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
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        long long ans = 0, cnt = 0;
        for (int i = 0, j = 0; i < nums.size(); i++) {
            cnt += mp[nums[i]]++;
            while (cnt >= k) {
                cnt -= --mp[nums[j++]];
            }
            ans += j;
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums1 = {1,2,2,2,2,1,2,1,1,1};
    Solution sl;
    long long res = sl.countGood(nums1, 10);

    cout << res << endl;

    return 0;
}
