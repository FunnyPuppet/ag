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
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        int sum = 0, ans = 0;
        for (int num : nums) {
            sum += num;
            if (cnt.find(sum - k) != cnt.end()) {
                ans += cnt[sum - k];
            }
            cnt[sum]++;
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums = {8,5,2,6,4,1,9,7,3};
    Solution sl;
    long long res = sl.subarraySum(nums, 4);

    cout << res << endl;

    return 0;
}
