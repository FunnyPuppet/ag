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
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, int> cnt;
        cnt[0] = 1;

        long long ans = 0, prefix = 0;
        for(const int num : nums){
            prefix += num % modulo == k;
            ans += cnt[static_cast<int>((prefix - k + modulo)) % modulo];
            cnt[static_cast<int>(prefix) % modulo]++;
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums = {8,5,2,6,4,1,9,7,3};
    Solution sl;
    long long res = sl.countInterestingSubarrays(nums, 2, 1);

    cout << res << endl;

    return 0;
}
