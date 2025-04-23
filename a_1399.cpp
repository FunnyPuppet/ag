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
#include <stack>

using namespace std;

class Solution {
public:
    int digitalSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num %10;
            num /= 10;
        }

        return sum;
    }

    int countLargestGroup(int n) {
        unordered_map<int, int> mp;

        int max = 0;
        for (int i = 1; i <= n; i++) {
            int sum = digitalSum(i);
            mp[sum]++;
            max = static_cast<int>(fmax(max, mp[sum]));
        }

        int ans = 0;
        for (auto pair : mp) {
            if (pair.second == max) {
                ans++;
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution sl;
    int res = sl.countLargestGroup(13);

    cout << res << endl;

    return 0;
}
