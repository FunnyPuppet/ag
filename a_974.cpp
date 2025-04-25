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
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> cnt(k);
        cnt[0] = 1;
        int sum = 0, ans = 0;
        for (int num : nums) {
            sum += num;
            ans += cnt[(sum % k + k) % k]++;
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums = {8,5,2,6,4,1,9,7,3};
    Solution sl;
    long long res = sl.subarraysDivByK(nums, 2);

    cout << res << endl;

    return 0;
}
