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
#include <numeric>
#include <stack>

using namespace std;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int, int> mp;
        unordered_set<int> st(nums.begin(), nums.end());
        int max = st.size();

        int ans = 0, r = 0, n = nums.size();
        for (int l = 0; l < n; l++) {
            if (l > 0) {
                int num = nums[l - 1];
                mp[num]--;
                if (mp[num] == 0) {
                    mp.erase(num);
                }
            }
            while (r < n && mp.size() < max) {
                int num = nums[r];
                mp[num]++;
                r++;
            }
            if (mp.size() == max) {
                ans += n - r + 1;
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums = {1,3,1,2,2};
    Solution sl;
    int res = sl.countCompleteSubarrays(nums);

    cout << res << endl;

    return 0;
}
