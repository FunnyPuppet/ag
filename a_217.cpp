#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;

        for (int num : nums) {
            if (set.count(num)) {
                return true;
            }
            set.insert(num);
        }

        return false;
    }
};



int main() {
    vector<int> nums = {4, 4, 16, 20, 8, 8, 2, 10};
    Solution sl;
    bool res = sl.containsDuplicate(nums);

    cout << res << endl;

    return 0;
}
