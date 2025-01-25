#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(), changed.end());
        unordered_map<int, int> map;

        for (int num : changed) {
            map[num]++;
        }

        vector<int> res;

        for (int num : changed) {
            if (map[num] == 0) {
                continue;
            }
            map[num]--;

            if (map[num * 2] == 0) {
                return {};
            }
            map[num * 2]--;
            res.push_back(num);
        }

        return res;
    }
};



int main() {
    vector<int> nums = {4, 4, 16, 20, 8, 8, 2, 10};
    Solution sl;
    vector<int> res = sl.findOriginalArray(nums);

    for (const int num : res) {
        cout << num << " ";
    }

    return 0;
}
