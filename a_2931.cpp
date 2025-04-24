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
    long long maxSpending(vector<vector<int>>& values) {
        int m = static_cast<int>(values.size()), n = static_cast<int>(values[0].size());
        vector<int> shops(m ,n - 1);

        long long ans = 0;
        for (int i = 1; i <= m * n; i++) {

            int min = 1e7, p = 0;
            for (int j = 0; j < m; j++) {
                if (shops[j] >= 0 && values[j][shops[j]] < min) {
                    min = values[j][shops[j]];
                    p = j;
                }
            }
            shops[p]--;
            ans += static_cast<long long>(min) * i;
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    vector<vector<int>> nums = {{8,5,2}, {6,4,1}, {9,7,3}};
    Solution sl;
    long long res = sl.maxSpending(nums);

    cout << res << endl;

    return 0;
}
