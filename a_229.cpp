#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, candidate1 = -1;
        int count2 = 0, candidate2 = -1;

        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;

        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            }
        }

        vector<int> res;
        if (count1 > nums.size() / 3) {
            res.push_back(candidate1);
        }
        if (count2 > nums.size() / 3) {
            res.push_back(candidate2);
        }

        return res;
    }
};

int main() {
    vector<int> nums = {1,2};
    Solution sl;
    vector<int> vc = sl.majorityElement(nums);

    for (int v : vc) {
        cout << v << endl;
    }

    return 0;
}
