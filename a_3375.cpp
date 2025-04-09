#include <algorithm>
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
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> s;

        for (int num : nums) {
            if (num < k) {
                return -1;
            }
            if (num != k) {
                s.insert(num);
            }
        }

        return s.size();
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums = {5,2,5,4,5};
    Solution sl;
    int res = sl.minOperations(nums, 2);
    cout << res << endl;

    return 0;
}
