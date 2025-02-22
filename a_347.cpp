#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;

        int max = INT_MIN;
        for (const int &num: nums) {
            int cnt = ++map[num];
            max = max > cnt ? max : cnt;
        }

        vector<vector<int>> buckets(max);

        for (const auto &pair: map) {
            buckets[pair.second - 1].push_back(pair.first);
        }
        vector<int> ans;

        for (int i = max - 1; i >= 0; i--) {
            for (const auto &item: buckets[i]) {
                ans.push_back(item);
                if (--k == 0) {
                    return ans;
                }
            }
        }

        return ans;
    }
};

int main() {
    vector<int> nums = {1, 1, 2, 2, 2, 3};

    Solution sl;
    vector<int> res = sl.topKFrequent(nums, 2);

    for (const auto &item: res) {
        cout << item << " ";
    }

    return EXIT_SUCCESS;
}
