#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <list>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        bool flag = false;
        int left = newInterval[0], right = newInterval[1];
        for (auto t : intervals) {
            if (t[0] > right) {
                if (!flag) {
                    ans.push_back({left, right});
                    flag = true;
                }
                ans.push_back(t);
            } else if (t[1] < left) {
                ans.push_back(t);
            } else {
                left = min(left, t[0]);
                right = max(right, t[1]);
            }
        }

        if (!flag) {
            ans.push_back({left, right});
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    vector<vector<int>> mat = {{1, 2}, {4, 6}, {8, 9}};
    vector<int> newInterval = {5, 7};
    Solution sl;
    sl.insert(mat, newInterval);
    return 0;
}
