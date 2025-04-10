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
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        int m = s.size(), n = 17;
        dp.resize(n);
        dp[m] = 1;
        long long add = 1;

        for (int i = 1; i < m; ++i) {
            add = add * 10 - s[i] + '0';
        }

        for (int i = m + 1; i < n; ++i) {
            dp[i] = (limit + 1) * dp[i - 1];
        }

        return getCnt(finish + add, limit, s) - getCnt(start + add - 1, limit, s);
    }
private:
    vector<long long> dp;
    long long getCnt(long long num, int limit, string& s) {
        for (int i = s.size() - 1; i > 0; --i, num /= 10);
        long long res = (num % 10) > s[0] - '0';

        for (int i = s.size(); num > 9; ++i) {
            num /= 10;
            int last = num % 10;
            res = (last > limit) ? dp[i] * (limit + 1) : (res + dp[i] * last);
        }

        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution sl;
    long long res = sl.numberOfPowerfulInt(1, 6000, 4, "24");

    cout << res << endl;

    return 0;
}
