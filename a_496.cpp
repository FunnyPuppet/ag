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
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        int stack[1000];
        int top = -1;

        for (int num : nums2) {
            while (top >= 0 && stack[top] < num) {
                map[stack[top--]] = num;
            }
            stack[++top] = num;
        }
        vector<int> ans;
        for (int num : nums1) {
            if (map.find(num) == map.end()) {
                ans.push_back(-1);
            } else {
                ans.push_back(map[num]);
            }
        }

        return ans;
    }
};


int main(int argc, char *argv[]) {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    Solution sl;

    sl.nextGreaterElement(nums1, nums2);

    return 0;
}
