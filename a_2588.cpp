#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int, int> map{{0, 1}};
        long long ans = 0;
        int base = 0;
        for (int num : nums) {
            ans += map[(base ^= num)]++;
        }

        return ans;
    }
};


int main(int argc, char *argv[]) {
    vector<int> nums = {4,3,1,2,4,4};
    Solution sl;

    long long res = sl.beautifulSubarrays(nums);

    cout << res << endl;

    return 0;
}
