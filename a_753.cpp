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
#include <string.h>

using namespace std;

class Solution {
private:
    unordered_set<int> seen;
    string ans;
    int highest;
    int k;

public:
    void dfs(int node) {
        for (int x = 0; x < k; ++x) {
            int nei = node * 10 + x;
            if (!seen.count(nei)) {
                seen.insert(nei);
                dfs(nei % highest);
                ans += (x + '0');
            }
        }
    }

    string crackSafe(int n, int k) {
        highest = pow(10, n - 1);
        this->k = k;
        dfs(0);
        ans += string(n - 1, '0');
        return ans;
    }
};

int main(int argc, char *argv[]) {

    return 0;
}
